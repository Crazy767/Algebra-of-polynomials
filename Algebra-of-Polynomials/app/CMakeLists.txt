project(WinFormApp)

# Добавить исходники проекта WinForms
file(GLOB APP_SOURCES "Form/*.cpp" "Form/*.h")

# Добавить исполняемый файл для проекта WinForms
add_executable(WinFormApp ${APP_SOURCES})

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

# Получаем список всех поддиректорий в папке libs
file(GLOB LIB_DIRS "../libs/*")

add_compile_options(/clr)
foreach(LIB_DIR ${LIB_DIRS})
    if(IS_DIRECTORY ${LIB_DIR})
        # Получаем имя библиотеки из пути к директории
        get_filename_component(LIB_NAME ${LIB_DIR} NAME)
        target_link_libraries(WinFormApp ${LIB_NAME})
    endif()
endforeach()
