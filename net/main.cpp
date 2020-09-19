#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>
#include <vector>

#ifndef   NI_MAXHOST
#define   NI_MAXHOST 1025
#endif

/**
 *
 * +-------+        +---------------+
 * |       |        |               |
 * |       |        |               |
 * | Call  |        |  Client       |
 * |       |        |               |
 * |       |        |               |
 * +-------+        +---------------+

 * @return
 */
int main() {
    std::vector<const char *> hosts;

    struct addrinfo *result;
    struct addrinfo *res;
    struct addrinfo hints;
    int error;

    bzero(&hints, sizeof(hints));
    hints.ai_flags = AI_CANONNAME;
    hints.ai_family = AF_INET;
    hints.ai_socktype = IPPROTO_TCP;

    /* resolve the domain name into a list of addresses */
    error = getaddrinfo("baidu.cn", nullptr, &hints, &result);
    if (error != 0) {
        if (error == EAI_SYSTEM) {
            std::cout << "getaddrinfo" << std::endl;
        } else {
            std::cout << "error in getaddrinfo: " << gai_strerror(error) << std::endl;
        }
        return 1;
    }

    /* loop over all returned results and do inverse lookup */
    for (res = result; res != NULL; res = res->ai_next) {
        char hostname[NI_MAXHOST];
        error = getnameinfo(res->ai_addr, res->ai_addrlen, hostname, NI_MAXHOST, NULL, 0, 0);
        if (error != 0) {
            std::cout << "error in getnameinfo: " << gai_strerror(error) << std::endl;
            continue;
        }
        if (*hostname != '\0') {
            std::cout << "hostname: " << hostname << std::endl;
            hosts.push_back(hostname);
        }
    }
    freeaddrinfo(result);

    return 0;
}
