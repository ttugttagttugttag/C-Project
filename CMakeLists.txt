cmake_minimum_required(VERSION 3.24)
project(ToDoList)

set(CMAKE_CXX_STANDARD 98)

add_executable(ToDoList main.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    file(WRITE ${PROJECT_BINARY_DIR}\\crun.bat start\ /wait\ ccore.bat)
    file(WRITE ${PROJECT_BINARY_DIR}\\ccore.bat @echo\ off\ntitle\ ${CMAKE_PROJECT_NAME}\ncls\n${CMAKE_PROJECT_NAME}\npause\nexit)
endif()