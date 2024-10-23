SET(ZDM_SOURCE_FILES
  "${SOURCE_DIR}/zdm/toilet.cpp"
)

add_library(
  zdm
  STATIC
  ${ZDM_SOURCE_FILES}
)

target_include_directories(
  zdm
  PUBLIC
  "${INCLUDE_DIR}"
)
