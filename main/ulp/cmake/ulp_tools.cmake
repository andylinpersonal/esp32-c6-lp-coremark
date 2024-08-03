# Print size
macro(ulp_print_size ulp_app)
    set(CMAKE_SIZE "riscv32-esp-elf-size")
    add_custom_command(TARGET ${ulp_app} POST_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_SIZE} "$<TARGET_FILE:${ulp_app}>"
        VERBATIM)
endmacro(ulp_print_size)

