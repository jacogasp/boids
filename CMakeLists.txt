cmake_minimum_required(VERSION 3.20)
project(Boids)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(
        Boids
        main.cpp
        src/App.cpp
        src/App_onInit.cpp
        src/App_onEvent.cpp
        src/App_onLoop.cpp
        src/App_onRender.cpp
        src/App_onCleanup.cpp
        src/Boid.cpp
        src/Boid.h
        src/VectorsMath.h
        src/Constants.h
        src/Slider.h
        src/Slider.cpp
        src/GUI.h
        src/GUI.cpp
        src/Environment.h
        src/Environment.cpp
)
target_include_directories(Boids PUBLIC include)
target_include_directories(Boids PRIVATE src)
target_link_libraries(Boids sfml-graphics)

add_subdirectory(tests)