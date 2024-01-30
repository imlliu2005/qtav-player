# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qtav_player_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qtav_player_autogen.dir\\ParseCache.txt"
  "qtav_player_autogen"
  )
endif()
