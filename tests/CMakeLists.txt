# add catch
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
endif()

set(tests
    minimal_cider.cpp)

add_executable(cider_test test.cpp ${tests})
target_link_libraries(cider_test cppzmq)
target_include_directories(cider_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(cider_test PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME test COMMAND cider_test)

