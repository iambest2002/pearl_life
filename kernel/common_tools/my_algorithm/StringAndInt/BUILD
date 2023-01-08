cc_library(
    name = "string_and_int",
    srcs = glob([
        "arr_sort.cpp",
        "MoveChangeSimulate.cpp",
    ]),
    hdrs = glob(["*.h"]),
    linkopts = ["-std=c++11 " ],
    #visibility = ["//visibility:public"],
)


cc_test(
    name = "arr_sort_test",
    srcs = glob([
        "arr_sort_test.cpp",
    ]),
    deps = [
        "@com_google_googletest//:gtest_main",
        ":StringAndInt",
    ],
    linkopts = ["-std=c++11" ],
    #visibility = ["//visibility:public"],
)






