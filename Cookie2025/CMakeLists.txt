# CMakeList.txt: Cookie2025 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
include_directories(./)
include_directories(ThirdPartLib/glm)

file(GLOB_RECURSE CORE_SOURCE Core/*.h Core/*.cpp)
file(GLOB_RECURSE EDITOR_SOURCE Editor/*.h Editor/*.cpp)
file(GLOB_RECURSE PLATFORM_SOURCE Platform/*.h Platform/*.cpp)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(ThirdPartLib/sdl3)

set(MI_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(MI_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(MI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(ThirdPartLib/mimalloc)

include_directories(ThirdPartLib/cereal/include)

include_directories(ThirdPartLib/imgui-docking)
include_directories(ThirdPartLib/imgui-docking/backends)
file(GLOB_RECURSE IMGUI_SOURCE ThirdPartLib/imgui-docking/*.h ThirdPartLib/imgui-docking/*.cpp)

# 将源代码添加到此项目的可执行文件。
add_executable (Cookie2025 "main.cpp" "Engine.h" "Engine.cpp" ${CORE_SOURCE} ${EDITOR_SOURCE} ${PLATFORM_SOURCE} ${IMGUI_SOURCE})

target_link_libraries(Cookie2025 mimalloc-static d3d12 d3d11 dxguid dxgi SDL3-static)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cookie2025 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
