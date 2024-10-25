
add_library(
  toilet-runner-app
  STATIC
  "${SOURCE_DIR}/toilet_runner/app/runner.cpp"
)

target_include_directories(
  toilet-runner-app
  PUBLIC
  "${INCLUDE_DIR}"
)

target_link_libraries( toilet-runner-app PRIVATE
  zdm
)

add_executable(
  toilet-runner
  "${SOURCE_DIR}/toilet_runner/main.cpp"
)

target_include_directories(
  toilet-runner
  PUBLIC
  "${INCLUDE_DIR}"
)

target_link_libraries( toilet-runner PRIVATE
  toilet-runner-app
)
