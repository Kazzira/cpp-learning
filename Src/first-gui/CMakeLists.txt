find_package(Qt6
  REQUIRED COMPONENTS Core Gui Widgets
)

qt_standard_project_setup()


qt_add_executable(
  first-gui
  "${SOURCE_DIR}/first-gui/main.cpp"
  "${SOURCE_DIR}/first-gui/first_gui_main_window.cpp"
)

target_include_directories(
  first-gui
  PUBLIC
  "${INCLUDE_DIR}"
)

target_link_libraries( first-gui PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
)
