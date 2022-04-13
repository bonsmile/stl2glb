cmake_minimum_required(VERSION 3.4)

project(stl2glb CXX)

add_executable(${PROJECT_NAME} WIN32
    ../imgui/imconfig.h
    ../imgui/imgui.h
    ../imgui/imgui.cpp
    ../imgui/imgui_demo.cpp
    ../imgui/imgui_draw.cpp
    ../imgui/imgui_internal.h
    ../imgui/imgui_tables.cpp
    ../imgui/imgui_widgets.cpp
    ../imgui/backends/imgui_impl_dx11.h
    ../imgui/backends/imgui_impl_dx11.cpp
    ../imgui/backends/imgui_impl_win32.h
    ../imgui/backends/imgui_impl_win32.cpp
    MainWindow.h
    MainWindow.cpp
    Main.cpp
)

#target_precompile_headers(${PROJECT_NAME} PRIVATE ../src/stdafx.h)

target_include_directories(${PROJECT_NAME} PRIVATE
    ..
    ../imgui
)

target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8" "/MP" "/wd4251" "/wd4996")
target_compile_definitions(${PROJECT_NAME} PUBLIC -DUNICODE -D_UNICODE -DBUILDING_DLL)
target_link_libraries(${PROJECT_NAME}  PRIVATE
    lxd
    d3d11.lib
)
