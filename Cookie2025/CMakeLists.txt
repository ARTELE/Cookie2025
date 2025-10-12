# CMakeList.txt: Cookie2025 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
include_directories(./)
include_directories(ThirdPartLib/glm)

file(GLOB_RECURSE CORE_SOURCE Core/*.h Core/*.cpp)


set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "" FORCE)
set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "" FORCE)
add_subdirectory(ThirdPartLib/yaml)

set(MI_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(MI_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(MI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(ThirdPartLib/mimalloc)

# 将源代码添加到此项目的可执行文件。
add_executable (Cookie2025 "main.cpp" "Engine.h" "Engine.cpp" ${CORE_SOURCE})

target_link_libraries(Cookie2025 yaml-cpp mimalloc-static)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cookie2025 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
