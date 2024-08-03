cmake_minimum_required(VERSION 3.16)

# Project/target name is passed from the main project to allow IDF to have a dependency on this target
# as well as embed the binary into the main app
project(${ULP_APP_NAME})

set(ulp_app_sources
    "../../coremark/core_list_join.c"
    "../../coremark/core_main.c"
    "../../coremark/core_matrix.c"
    "../../coremark/core_state.c"
    "../../coremark/core_util.c"
    "core_portme.c")

add_executable(${ULP_APP_NAME} ${ulp_app_sources})

# Import the ULP project helper functions
include(IDFULPProject)

# Apply default compile options
ulp_apply_default_options(${ULP_APP_NAME})

# Apply default sources provided by the IDF ULP component
ulp_apply_default_sources(${ULP_APP_NAME})

# Add targets for building the binary, as well as the linkerscript which exports ULP shared variables to the main app
ulp_add_build_binary_targets(${ULP_APP_NAME})

target_include_directories(${ULP_APP_NAME} PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../coremark"
)


# target_compile_options(${ULP_APP_NAME} PRIVATE "-Os")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-Os" "-msave-restore")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-O2")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-O2" "-msave-restore")
target_compile_options(${ULP_APP_NAME} PRIVATE "-O3")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-O3" "-msave-restore")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-O3" "-fno-jump-tables")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-O3" "-fno-jump-tables" "-fno-tree-switch-conversion")
# target_compile_options(${ULP_APP_NAME} PRIVATE "-Ofast")

include(cmake/ulp_tools.cmake)
ulp_print_size(${ULP_APP_NAME})
