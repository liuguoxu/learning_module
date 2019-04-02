cmake_minimum_required(VERSION 3.13)
project(c_ C)

set(CMAKE_C_STANDARD 11)

include_directories(dl_list)

add_executable(c_
        "dl_list/dl_test.si4project/Backup/my_dl_list(334).c"
        "dl_list/dl_test.si4project/Backup/my_dl_list(3586).c"
        "dl_list/dl_test.si4project/Backup/my_dl_list(6028).c"
        dl_list/list.h
        dl_list/my_dl_list.c
        dl_list/test1.c
        libcurl_test/main.c
        macro/macro_.c
        parse_host/getaddrinfo.c
        pipe/pipe.c
        pipe/pipe1.c
        popen/fork_exec.c
        popen/proc.c
        str/strdup.c
        str/strtok_test.c
        str_palindrome/main.c
        array2.c
        big_small_endian.c
        curl.c
        enum_test.c
        fork.c
        func_ptr.c
        struct.c
        test.c
        three.c
        unsigned.c
        thread_test.c)
