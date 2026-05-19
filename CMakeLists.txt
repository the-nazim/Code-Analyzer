cmake_minimum_required(VERSION 3.13)
project(StaticAnalyzer)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

include_directories(
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
    include
)

add_definitions(${LLVM_DEFINITIONS})

add_executable(analyzer
    src/main.cpp
    src/AnalyzerAction.cpp
    src/AnalyzerConsumer.cpp
    src/ASTVisitor.cpp
)

target_link_libraries(analyzer
    clangTooling
    clangBasic
    clangASTMatchers
    clangFrontend
)