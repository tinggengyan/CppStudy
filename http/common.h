//
// Created by Tinggeng Yan on 2020/7/22.
//

#ifndef CLIONPROJECT_COMMON_H
#define CLIONPROJECT_COMMON_H

#include <array>
#include <atomic>
#include <cassert>
#include <climits>
#include <condition_variable>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <random>
#include <regex>
#include <string>
#include <sys/stat.h>
#include <thread>

#include <arpa/inet.h>
#include <cstring>
#include <ifaddrs.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#ifdef CPPHTTPLIB_USE_POLL
#include <poll.h>
#endif

#include <csignal>
#include <pthread.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

using socket_t = int;


namespace httplib {


    namespace detail {

        struct ci {
            bool operator()(const std::string &s1, const std::string &s2) const {
                return std::lexicographical_compare(
                        s1.begin(), s1.end(), s2.begin(), s2.end(),
                        [](char c1, char c2) { return ::tolower(c1) < ::tolower(c2); });
            }
        };

    } // namespace detail

    using Headers = std::multimap<std::string, std::string, detail::ci>;

    namespace detail {

        inline void get_remote_ip_and_port(const struct sockaddr_storage &addr,
                                           socklen_t addr_len, std::string &ip,
                                           int &port) {
            if (addr.ss_family == AF_INET) {
                port = ntohs(reinterpret_cast<const struct sockaddr_in *>(&addr)->sin_port);
            } else if (addr.ss_family == AF_INET6) {
                port =
                        ntohs(reinterpret_cast<const struct sockaddr_in6 *>(&addr)->sin6_port);
            }

            std::array<char, NI_MAXHOST> ipstr{};
            if (!getnameinfo(reinterpret_cast<const struct sockaddr *>(&addr), addr_len,
                             ipstr.data(), static_cast<socklen_t>(ipstr.size()), nullptr,
                             0, NI_NUMERICHOST)) {
                ip = ipstr.data();
            }
        }

        inline void get_remote_ip_and_port(socket_t sock, std::string &ip, int &port) {
            struct sockaddr_storage addr;
            socklen_t addr_len = sizeof(addr);

            if (!getpeername(sock, reinterpret_cast<struct sockaddr *>(&addr),
                             &addr_len)) {
                get_remote_ip_and_port(addr, addr_len, ip, port);
            }
        }


        template<typename T>
        inline ssize_t handle_EINTR(T fn) {
            ssize_t res = false;
            while (true) {
                res = fn();
                if (res < 0 && errno == EINTR) { continue; }
                break;
            }
            return res;
        }


        inline ssize_t select_read(socket_t sock, time_t sec, time_t usec) {
#ifdef CPPHTTPLIB_USE_POLL
            struct pollfd pfd_read;
  pfd_read.fd = sock;
  pfd_read.events = POLLIN;

  auto timeout = static_cast<int>(sec * 1000 + usec / 1000);

  return handle_EINTR([&]() { return poll(&pfd_read, 1, timeout); });
#else
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(sock, &fds);

            timeval tv;
            tv.tv_sec = static_cast<long>(sec);
            tv.tv_usec = static_cast<decltype(tv.tv_usec)>(usec);

            return handle_EINTR([&]() {
                return select(static_cast<int>(sock + 1), &fds, nullptr, nullptr, &tv);
            });
#endif
        }


        inline ssize_t select_write(socket_t sock, time_t sec, time_t usec) {
#ifdef CPPHTTPLIB_USE_POLL
            struct pollfd pfd_read;
  pfd_read.fd = sock;
  pfd_read.events = POLLOUT;

  auto timeout = static_cast<int>(sec * 1000 + usec / 1000);

  return handle_EINTR([&]() { return poll(&pfd_read, 1, timeout); });
#else
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(sock, &fds);

            timeval tv;
            tv.tv_sec = static_cast<long>(sec);
            tv.tv_usec = static_cast<decltype(tv.tv_usec)>(usec);

            return handle_EINTR([&]() {
                return select(static_cast<int>(sock + 1), nullptr, &fds, nullptr, &tv);
            });
#endif
        }


    }
}


#endif //CLIONPROJECT_COMMON_H
