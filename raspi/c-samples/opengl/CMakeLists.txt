cmake_minimum_required(VERSION 3.10)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} rpi_opengl_graph.c)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_dependencies(${PROJECT_NAME} OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL ${GLUT_LIBRARY} )