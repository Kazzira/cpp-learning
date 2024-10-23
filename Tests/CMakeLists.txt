SET(TEST_SOURCE_DIR "${ROOT_DIR}/Tests")

SET(TEST_SOURCE_FILES
  "${TEST_SOURCE_DIR}/zdm/toilet.test.cpp"
)

add_executable(
  cpp-learning-tests
  ${TEST_SOURCE_FILES}
)

# Include source.
target_include_directories(
  cpp-learning-tests
  PRIVATE
  "${INCLUDE_DIR}"
)

# Also include tests as well.
target_include_directories(
  cpp-learning-tests
  PRIVATE
  "${TEST_SOURCE_DIR}"
)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries( cpp-learning-tests PRIVATE
  zdm
  Catch2::Catch2WithMain
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(cpp-learning-tests)


add_custom_command(
  OUTPUT _run-cpp-learning-tests-completed
  COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --output-on-failure
  COMMAND cmake -E touch _run-cpp-learning-tests-completed
  DEPENDS cpp-learning-tests zdm
)

add_custom_target(run-cpp-learning-tests ALL
  DEPENDS _run-cpp-learning-tests-completed
)
