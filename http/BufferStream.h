//
// Created by Tinggeng Yan on 2020/7/22.
//

#ifndef CLIONPROJECT_BUFFERSTREAM_H
#define CLIONPROJECT_BUFFERSTREAM_H

#include "Stream.h"

namespace httplib {

    namespace detail {

        class BufferStream : public Stream {
        public:
            BufferStream() = default;

            ~BufferStream() override = default;

            bool is_readable() const override;

            bool is_writable() const override;

            ssize_t read(char *ptr, size_t size) override;

            ssize_t write(const char *ptr, size_t size) override;

            void get_remote_ip_and_port(std::string &ip, int &port) const override;

            const std::string &get_buffer() const;

        private:
            std::string buffer;
            size_t position = 0;
        };
    };
};
#endif //CLIONPROJECT_BUFFERSTREAM_H
