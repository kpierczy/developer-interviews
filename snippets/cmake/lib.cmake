# ====================================================================================================================================
# @file       lib.bash
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:09:30 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      CMake basics - lib targets
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

add_library(some-lib STATIC ${ASB_FUZING_CONTROLLER_LIB_SOURCES})

target_link_libraries(some-lib PUBLIC
    some-other-lib::some-other-lib
)

if(NOT (TARGET_MCU STREQUAL "none"))
    target_link_libraries(some-lib PUBLIC
        some-embedded-lib::some-embedded-lib
    )
endif()

target_include_directories(some-lib PRIVATE
    ${CMAKE_SOURCE_DIR}/src)
target_include_directories(some-lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
