# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SpaceInvaderShip_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SpaceInvaderShip_autogen.dir\\ParseCache.txt"
  "SpaceInvaderShip_autogen"
  )
endif()
