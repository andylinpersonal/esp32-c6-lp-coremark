idf_component_register(
    SRCS 
        "main.cpp"
    REQUIRES
        "driver"
        "ulp"
    WHOLE_ARCHIVE)

ulp_add_project("lp_coremark" "${CMAKE_CURRENT_SOURCE_DIR}/ulp")
