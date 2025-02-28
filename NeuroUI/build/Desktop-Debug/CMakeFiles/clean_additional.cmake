# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/NeuroUI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/NeuroUI_autogen.dir/ParseCache.txt"
  "NeuroUI_autogen"
  )
endif()
