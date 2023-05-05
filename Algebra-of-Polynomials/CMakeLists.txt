cmake_minimum_required (VERSION 3.10)

project (Algebra-of-Polynomials)

include(cmake/function.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")

add_executable(win_forms app/Form.cpp)
add_executable(main_test app/main.cpp)

set_property(TARGET win_forms PROPERTY VS_DOTNET_REFERENCES
    "System"
    "System.Drawing"
    "System.Windows.Forms"
)

include_directories(libs)

# Получаем список всех поддиректорий в папке libs
file(GLOB LIB_DIRS "libs/*")

# Для каждого поддиректория добавляем его в проект и прописываем для него target_link_libraries
add_compile_options(/clr)
foreach(LIB_DIR ${LIB_DIRS})
    if(IS_DIRECTORY ${LIB_DIR})
        add_subdirectory(${LIB_DIR})
        get_filename_component(LIB_NAME ${LIB_DIR} NAME)
        target_link_libraries(main_test ${LIB_NAME})
        target_link_libraries(win_forms ${LIB_NAME})
        set_property(TARGET ${LIB_NAME} PROPERTY COMMON_LANGUAGE_RUNTIME "")
    endif()
endforeach()

option(BTEST "build test?" OFF) # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
