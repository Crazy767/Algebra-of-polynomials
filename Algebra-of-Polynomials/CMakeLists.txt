cmake_minimum_required (VERSION 3.10)

project (Algebra-of-Polynomials)

include(cmake/function.cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")

add_executable(win_forms libs/win_form/Form.cpp)

add_subdirectory(libs/interface_avl_tree)
add_subdirectory(libs/polynomial)
add_subdirectory(libs/linear_array)
add_subdirectory(libs/monoms)
add_subdirectory(libs/clist)
add_subdirectory(libs/app)
add_subdirectory(libs/sorted_array_table)
add_subdirectory(libs/postfix_polinoms)
add_subdirectory(libs/hash_chain_table)

option(BTEST "build test?" OFF) # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()