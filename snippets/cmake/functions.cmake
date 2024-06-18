# ====================================================================================================================================
# @file       functions.bash
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:09:46 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      CMake basics - functions
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

function(target_binary_executable target)
    
    set(SINGLE_ARGUMENTS
        ELF_NAME
        HEX_NAME
        BIN_NAME
    )

    set(ARG_PREFIX "ARG")

    cmake_parse_arguments(${ARG_PREFIX}
        ""
        "${SINGLE_ARGUMENTS}"
        ""
        ${ARGN}
    )
    
    # --------------------------------------------------------------------
    
    if(NOT DEFINED ${ARG_PREFIX}_ELF_NAME)
        set(${ARG_PREFIX}_ELF_NAME ${target}.elf)
    endif()
    if(NOT DEFINED ${ARG_PREFIX}_HEX_NAME)
        set(${ARG_PREFIX}_HEX_NAME ${target}.hex)
    endif()
    if(NOT DEFINED ${ARG_PREFIX}_BIN_NAME)
        set(${ARG_PREFIX}_BIN_NAME ${target}.bin)
    endif()

    # --------------------------------------------------------------------

    string(REPLACE " " ";" CMAKE_HEX "$ENV{CMAKE_HEX}")
    string(REPLACE " " ";" CMAKE_BIN "$ENV{CMAKE_BIN}")

    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy           $<TARGET_FILE:${target}> ${CMAKE_BINARY_DIR}/${ARG_ELF_NAME}
        COMMAND arm-none-eabi-objcopy -O ihex      $<TARGET_FILE:${target}> ${CMAKE_BINARY_DIR}/${ARG_HEX_NAME}
        COMMAND arm-none-eabi-objcopy -O binary -S $<TARGET_FILE:${target}> ${CMAKE_BINARY_DIR}/${ARG_BIN_NAME}
        COMMENT "Building ${ARG_ELF_NAME}
                 Building ${ARG_HEX_NAME}
                 Building ${ARG_BIN_NAME}"
    )

endfunction()
