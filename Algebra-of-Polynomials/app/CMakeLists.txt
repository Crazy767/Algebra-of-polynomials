project(WinFormApp)

# Добавить исходники проекта WinForms
file(GLOB APP_SOURCES "Form/*.cpp" "Form/*.h")

# Добавить исполняемый файл для проекта WinForms
add_executable(WinFormApp ${APP_SOURCES})
include_directories(../libs)

# Установить свойства проекта
set_property(TARGET WinFormApp PROPERTY VS_GLOBAL_ROOTNAMESPACE "WinFormApp")
set_property(TARGET WinFormApp PROPERTY VS_GLOBAL_KEYWORD "Win32Proj")
set_property(TARGET WinFormApp PROPERTY VS_GLOBAL_ApplicationType "Windows")
set_property(TARGET WinFormApp PROPERTY VS_GLOBAL_CLRSupport "true")
set_property(TARGET WinFormApp PROPERTY VS_GLOBAL_CLRApplicationType "WindowsForms")

# Указать ссылки на необходимые библиотеки WinForms
set_property(TARGET WinFormApp PROPERTY VS_DOTNET_REFERENCES
    "System"
    "System.Data"
    "System.Drawing"
    "System.Windows.Forms"
    "System.Xml"
)

# Установить свойство использования C++/CLI для проекта WinForms
set_property(TARGET WinFormApp PROPERTY COMMON_LANGUAGE_RUNTIME "CommonLanguageRuntimeSupport")

# Получаем список всех поддиректорий в папке libs/
file(GLOB LIB_DIRS "../libs/Core/*" "../libs/Tables/*")

# Для каждого поддиректория добавляем его в проект и прописываем для него target_link_libraries
add_compile_options(/clr)
foreach(LIB_DIR ${LIB_DIRS})
    if(IS_DIRECTORY ${LIB_DIR})
        get_filename_component(LIB_NAME ${LIB_DIR} NAME)
        target_link_libraries(WinFormApp ${LIB_NAME})
    endif()
endforeach()

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/json json)


target_link_libraries(WinFormApp nlohmann_json::nlohmann_json)