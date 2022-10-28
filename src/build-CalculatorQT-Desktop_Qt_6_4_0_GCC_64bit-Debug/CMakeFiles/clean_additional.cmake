# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CalculatorQT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CalculatorQT_autogen.dir/ParseCache.txt"
  "CalculatorQT_autogen"
  )
endif()
