# CMakeList.txt: проект CMake для Gen_Intererface; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Gen_Intererface")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Gen_Intererface "Gen_Intererface.cpp" "Gen_Intererface.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
