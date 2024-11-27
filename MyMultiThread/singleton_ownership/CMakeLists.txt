cmake_minimum_required(VERSION 3.16.3)

project(singletonowner VERSION 0.0.1 LANGUAGES C CXX DESCRIPTION "Singleton Ownership test")


file(GLOB SINGLETONOWNER_SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${SINGLETONOWNER_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


