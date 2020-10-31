if(${CMAKE_C_COMPILER_ID} MATCHES "Intel") # icc / icpc
  # prevent shared libraries from depending on Intel provided libraries
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-intel")
endif()
