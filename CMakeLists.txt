cmake_minimum_required (VERSION 3.27)

project(cpp-learning)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#SET(CMAKE_AUTOUIC ON)

enable_testing()

set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDE_DIR "${ROOT_DIR}/Src")
set(SOURCE_DIR "${ROOT_DIR}/Src")


#
# Compile commands
# From stackoverflow.
# https://stackoverflow.com/questions/57464766/copy-compile-commands-json-to-project-root-folder
#
add_custom_target(
    copy-compile-commands ALL
    DEPENDS
        ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    )
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    DEPENDS
        # Unlike "proper" targets like executables and libraries,
        # custom command / target pairs will not set up source
        # file dependencies, so we need to list file explicitly here
        generate-compile-commands
        ${CMAKE_BINARY_DIR}/compile_commands.json
    )
#
# Generate the compilation commands. Necessary so cmake knows where it came
# from and if for some reason you delete it.
#
add_custom_target(generate-compile-commands
    DEPENDS
        ${CMAKE_BINARY_DIR}/compile_commands.json
    )
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -B${CMAKE_BINARY_DIR} -S${CMAKE_SOURCE_DIR}
    )


add_subdirectory(Src)
add_subdirectory(Tests)
