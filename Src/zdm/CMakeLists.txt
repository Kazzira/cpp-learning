add_library(
  zdm
  SHARED
  "${SOURCE_DIR}/zdm/toilet.cpp"
  "${SOURCE_DIR}/zdm/metap/factorial.cpp"
)

target_include_directories(
  zdm
  PUBLIC
  "${INCLUDE_DIR}"
)
