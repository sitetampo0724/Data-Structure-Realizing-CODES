# CMakeList.txt : CMake project for 3088, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (3088 "3088.cpp"   )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3088 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
