cc_library(
    name = "logger",
    srcs = [

        "logger.cpp",
        "timestamp.cpp",

    ],
    hdrs = glob(["*.h"]),
    linkopts = ["-pthread -std=c++11"],
    visibility = ["//visibility:public"],
)



cc_binary(
    name = "test_log",
    srcs = ["test.cpp"],
    deps = [
        ":logger",
    ],
    linkopts = ["-pthread -std=c++11"],
)

cc_library(
  name = "add",
  hdrs = ["add.h"],
  srcs = ["add.cpp"]
  
)

cc_test(
  name = "add_test",
  srcs = ["add_test.cpp"],
  deps = [
    ":add",
    "@com_google_googletest//:gtest_main",
  ],
)

cc_test(
  name = "test_logger",
  srcs = ["gtest_log.cpp"],
  deps = [
    ":logger",
    "@com_google_googletest//:gtest_main",
  ],
  linkopts = ["-pthread -std=c++11"],
)