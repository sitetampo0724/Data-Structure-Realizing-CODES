# CMakeList.txt : CMake project for 3094, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (3094 "3094.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3094 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
