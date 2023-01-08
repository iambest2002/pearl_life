cc_library(
    name = "linux_db_pool",
    srcs = glob([
        "connect.cpp",
        "connect_pool.cpp",
    ]),
    hdrs = glob(["*.h"]),
    linkopts = ["-pthread -std=c++11  -I/usr/include/mysql -L/usr/lib64/mysql"],
    #visibility = ["//visibility:public"],
)



cc_binary(
    name = "test_dp",
    srcs = ["test.cpp"],
    deps = [
        ":linux_db_pool",
    ],
    linkopts = ["-pthread -lmysqlclient -std=c++11  -I/usr/include/mysql -L/usr/lib64/mysql"],
)
