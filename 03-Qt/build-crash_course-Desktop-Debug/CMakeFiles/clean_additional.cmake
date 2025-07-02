# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/crash_course_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/crash_course_autogen.dir/ParseCache.txt"
  "crash_course_autogen"
  )
endif()
