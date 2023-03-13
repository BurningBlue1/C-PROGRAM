# vscode中使用gtest

https://blog.csdn.net/leapold_Z/article/details/123025113

本文将介绍如何以源码的形式在 vscode 中使用 googletest，重点在于目录结构与 CMakeLists.txt 的创建，不涉及如何在 vscode 中使用 CMake 进行构建与生成。目标是将生产代码与测试代码分离，保持代码环境整洁。

上述 include 与 src 中为生产代码，tests 中为测试代码与 gtest 源码。