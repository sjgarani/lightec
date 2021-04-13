add_celix_bundle(lightec_service
    SOURCES
        src/led_service_impl
        src/led_service_activator
    SYMBOLIC_NAME "lightec_service"
    VERSION 1.0.0
)

target_include_directories(lightec_service PRIVATE src)
target_link_libraries(lightec_service PRIVATE Celix::log_service_api Celix::log_helper Celix::rsa_spi lightec_api)

get_target_property(DESCR lightec_api INTERFACE_DESCRIPTOR)
celix_bundle_files(lightec_service ${DESCR} DESTINATION .)