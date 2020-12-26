cmake_minimum_required(VERSION 3.16)
project(CIDER VERSION 2020.12)

option(CIDER_BUILD_EXAMPLES "whether or not to build the examples" ON)
option(CIDER_BUILD_TESTS "whether or not to build the tests" ON)

set(include_dest "include")
set(tool_dest "bin")

# add external libraries (not header-only)
# include(external/external.cmake)

# subdirectories
if (CIDER_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if (CIDER_BUILD_EXAMPLES)
	macro(cider_add_examples EXAMPLENAME)
		add_executable(${EXAMPLENAME} ${ARGN})
		set_target_properties(${EXAMPLENAME} PROPERTIES FOLDER examples)
		set_target_properties(${EXAMPLENAME} PROPERTIES CXX_STANDARD 17)
		target_include_directories(${EXAMPLENAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
		add_test(NAME ${EXAMPLENAME} COMMAND ${EXAMPLENAME})
	endmacro()
    add_subdirectory(examples)
endif()

find_package(cppzmq)
target_link_libraries(CIDER cppzmq)
