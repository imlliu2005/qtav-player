# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\av_player_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\av_player_autogen.dir\\ParseCache.txt"
  "av_player_autogen"
  )
endif()
