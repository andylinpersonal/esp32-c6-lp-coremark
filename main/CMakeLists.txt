idf_component_register(
    SRCS 
        "main.cpp"
    REQUIRES
        "driver"
        "ulp"
    WHOLE_ARCHIVE)

set(ulp_app_name lp_coremark)
set(ulp_sources 
    "../coremark/core_list_join.c"
    "../coremark/core_main.c"
    "../coremark/core_matrix.c"
    "../coremark/core_state.c"
    "../coremark/core_util.c"
    "ulp/core_portme.c"
)
set(ulp_exp_dep_srcs "main.cpp")
ulp_embed_binary(${ulp_app_name} "${ulp_sources}" "${ulp_exp_dep_srcs}")
