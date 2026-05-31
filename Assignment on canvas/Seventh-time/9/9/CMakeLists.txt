# CMakeList.txt : CMake project for 9, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (9 "9.cpp" "9.h" "KeyValue.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 9 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
