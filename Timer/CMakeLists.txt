cmake_minimum_required(VERSION 2.8)

project(Timer)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(DEPENDENCIES_DIR ${PROJECT_DIR}/../Dependencies)

set(IMGUI_INCLUDE_DIR ${DEPENDENCIES_DIR}/imgui)

file(GLOB IMGUI_SOURCES ${IMGUI_INCLUDE_DIR}/*.cpp)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set(PROJECT_SOURCES
            ${PROJECT_SOURCE_DIR}/main.cpp
            ${PROJECT_SOURCE_DIR}/glad.c
            ${PROJECT_SOURCE_DIR}/shaderprogram.cpp
            ${PROJECT_SOURCE_DIR}/square.cpp
            ${PROJECT_SOURCE_DIR}/texturemanager.cpp
            ${PROJECT_SOURCE_DIR}/VertexArrayObject.cpp
            ${PROJECT_SOURCE_DIR}/Mesh.cpp
            ${PROJECT_SOURCE_DIR}/MeshManager.cpp
            ${PROJECT_SOURCE_DIR}/Scene.cpp
            ${PROJECT_SOURCE_DIR}/VertexArrayObjectManager.cpp
            ${PROJECT_SOURCE_DIR}/WindowTransform.cpp
            ${PROJECT_SOURCE_DIR}/OpenGLManager.cpp
            ${PROJECT_SOURCE_DIR}/Timer.cpp
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