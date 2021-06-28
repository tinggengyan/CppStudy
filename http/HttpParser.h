//
// Created by Tinggeng Yan on 2020/7/22.
//

#ifndef CLIONPROJECT_HTTPPARSER_H
#define CLIONPROJECT_HTTPPARSER_H

#include "Stream.h"
#include "stream_line_reader.h"
#include "httplib.h"

namespace httplib {

    namespace detail {

        inline bool read_headers(Stream &strm, Headers &headers) {
            const auto bufsiz = 2048;
            char buf[bufsiz];
            stream_line_reader line_reader(strm, buf, bufsiz);

            for (;;) {
                if (!line_reader.getline()) { return false; }

                // Check if the line ends with CRLF.
                if (line_reader.end_with_crlf()) {
                    // Blank line indicates end of headers.
                    if (line_reader.size() == 2) { break; }
                } else {
                    continue; // Skip invalid line.
                }

                // Skip trailing spaces and tabs.
                auto end = line_reader.ptr() + line_reader.size() - 2;
                while (line_reader.ptr() < end && (end[-1] == ' ' || end[-1] == '\t')) {
                    end--;
                }

                parse_header(line_reader.ptr(), end, headers);
            }

            return true;
        }
    }
}

#endif //CLIONPROJECT_HTTPPARSER_H
