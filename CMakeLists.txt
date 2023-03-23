#1.cmake verson，指定cmake版本
cmake_minimum_required(VERSION 3.8)


#set(TOOLCHAIN_PATH /home/junlin/tina_t113/T113-S3-TinaSDK/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/bin/)
#set(CMAKE_C_COMPILER /home/junlin/tina_t113/T113-S3-TinaSDK/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/bin/arm-openwrt-linux-gcc)
#set(CMAKE_CXX_COMPILER /home/junlin/tina_t113/T113-S3-TinaSDK/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/bin/arm-openwrt-linux-g++)


# C++  版本
set(CMAKE_CXX_STANDARD 14)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(lvgl)

#3.
INCLUDE_DIRECTORIES(
    aerof/include/
    ./
    src/
)

#3.添加依赖
#find_package(brclcpp REQUIRED)
#find_package(brclcpp_action REQUIRED)



include_directories(${CMAKE_CURRENT_BINARY_DIR})


## Specify additional locations of header files
## Your package locations should be listed before other locations


#4.proto/ 子目录中所有的 .proto 文件，并生成静态库 brclcpp_action_example_protos.a
#file(GLOB_RECURSE ALL_PROTOS ${CMAKE_CURRENT_LIST_DIR}/proto/*.proto)
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${ALL_PROTOS})
#add_library(brclcpp_action_protos STATIC ${PROTO_SRCS})

#5.source directory，源文件目录
file(GLOB_RECURSE SRCS 
    src/*.c
    main.c
)
#

#7.编译选项\添加库文件
# add_compile_options(-g)


#8.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
#SET(TEST_MATH
#    ${DIR_SRCS}
#    )

#9.add executable file，添加要编译的可执行文件

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})
#10.add link library，添加可执行文件所需要的库，比如我们用到了libevent.so（命名规则：lib+name+.so），就添加该库的名称
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    pthread
    rt
    )
