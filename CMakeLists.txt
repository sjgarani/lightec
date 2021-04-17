cmake_minimum_required(VERSION 3.4)
project(lightec)

SET(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti ${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

find_package(Celix REQUIRED)

add_subdirectory(bundles/lightec_api)
add_subdirectory(bundles/lightec_service)

add_celix_container(lightec
    COPY
    BUNDLES
        Celix::rsa_discovery
        Celix::rsa_topology_manager
        Celix::rsa_dfi
        Celix::log_admin
        lightec_service
    PROPERTIES
        RSA_PORT=18888
)