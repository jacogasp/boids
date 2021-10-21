add_executable(
        VectorMathTest VectorMathTest.cpp
        ../src/VectorsMath.h
)

target_link_libraries(VectorMathTest sfml-graphics)
