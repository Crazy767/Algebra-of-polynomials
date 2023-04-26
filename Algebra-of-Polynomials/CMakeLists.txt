# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.10)

project ("Algebra-of-Polynomials")

include(cmake/function.cmake) # подхватываем функции, реализованные в файле function.cmake

add_subdirectory(libs/interface_avl_tree)
add_subdirectory(libs/linear_array)

option(BTEST "build test?" OFF) # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()