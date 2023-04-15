cmake_minimum_required(VERSION 2.8)

project(SahneAgaci)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(DEPENDENCIES_DIR ${PROJECT_DIR}/../Dependencies)

set(IMGUI_INCLUDE_DIR ${DEPENDENCIES_DIR}/imgui)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

file(GLOB IMGUI_SOURCES ${IMGUI_INCLUDE_DIR}/*.cpp)
file(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set(PROJECT_SOURCES
            ${PROJECT_SOURCE_FILES}
            ${PROJECT_SOURCE_DIR}/glad.c
            ${IMGUI_SOURCES}
            )

set(PROJECT_HEADERS)
            

set(glfw3_DIR ${PROJECT_DIR}/../Dependencies/GLFW/lib/cmake/glfw3)
set(GLM_INCLUDE_DIR ${PROJECT_DIR}/../Dependencies)

set(PROJECT_INCLUDE_DIR
                    ${PROJECT_DIR}/include
                    ${GLM_INCLUDE_DIR}
                    ${IMGUI_INCLUDE_DIR}
                    )

find_package(glfw3 3.3 REQUIRED)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw)