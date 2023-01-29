
# init

## backgournd
简单的安装和配置是在环境安装里面介绍， 复杂一点的项目设置是在这里，例如使用bazel启动项目， 搭建脚手架， 使用火焰图测试性能等等。

# workflow


## BuildCppByBazel() //使用bazel 编译cpp


```sh

1. crete and add content into workspace  file in root dir.

workspace(name = "com_googletest_driven")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test
http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/release-1.10.0.zip"],
  strip_prefix = "googletest-release-1.10.0",
  sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
)


2. create and add content  in BUILD file for lib build.

cc_library(
  name = "pearl_hourse",
  hdrs = ["*.*"],
  srcs = ["add.cpp"]
)


3. create and add content in BUILD file for binary build.

cc_test(
  name = "test_log",
  srcs = glob(
      ["*.cc=pp"],
  ),
  deps = [
    "@com_google_googletest//:gtest_main",
  ],
  linkopts = ["-pthread"],
  visibility = ["//visibility:public"],
)


cc_binary(
  name = "test_log",
  srcs = glob(
      ["*.cc=pp"],
  ),

  linkopts = ["-pthread"],
  visibility = ["//visibility:public"],
)


4. run build commanad. 
# test is dir under of root.
bazel test //test:test_log

bazel build //test:test_log
```

