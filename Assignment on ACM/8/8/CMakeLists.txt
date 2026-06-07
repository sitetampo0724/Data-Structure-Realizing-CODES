# CMakeList.txt : CMake project for 8, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (8 "8.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
