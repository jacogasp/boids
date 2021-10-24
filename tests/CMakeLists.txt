add_executable(
        VectorMathTest VectorMathTest.cpp
)

target_include_directories(VectorMathTest PUBLIC ../include)
target_include_directories(VectorMathTest PRIVATE ../src)

target_link_libraries(VectorMathTest sfml-graphics)
