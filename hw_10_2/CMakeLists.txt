cmake_minimum_required(VERSION 3.16)

set(CMAKE_<LANG>_STANDARD 20)
set(CMAKE_<LANG>_STANDARD_REQUIRED true)

project(hw_10_2)

set(SHAPE_DIR shape)
set(TRIANGLE_DIR triangles)
set(QUADRANGLE_DIR quadrangles)

include_directories(${SHAPE_DIR} ${TRIANGLE_DIR} ${QUADRANGLE_DIR})

set(SHAPE  
	${SHAPE_DIR}/shape.cpp)

set(TRIANGLES
	${TRIANGLE_DIR}/triangle.cpp
	${TRIANGLE_DIR}/right_triangle.cpp
	${TRIANGLE_DIR}/isosceles_triangle.cpp
	${TRIANGLE_DIR}/equilateral_triangle.cpp 
	
	${TRIANGLE_DIR}/triangle.h
	${TRIANGLE_DIR}/right_triangle.h
	${TRIANGLE_DIR}/isosceles_triangle.h
	${TRIANGLE_DIR}/equilateral_triangle.h)

set(QUADRANGLES 
	${QUADRANGLE_DIR}/parallelogram.cpp 
	${QUADRANGLE_DIR}/quadrangle.cpp
	${QUADRANGLE_DIR}/rectangle.cpp
	${QUADRANGLE_DIR}/rhombus.cpp
	${QUADRANGLE_DIR}/square.cpp
	
	${QUADRANGLE_DIR}/parallelogram.h
	${QUADRANGLE_DIR}/quadrangle.h 
	${QUADRANGLE_DIR}/rectangle.h
	${QUADRANGLE_DIR}/rhombus.h
	${QUADRANGLE_DIR}/square.h)

add_executable(hw_10_2 hw_10_2.cpp ${SHAPE} ${TRIANGLES} ${QUADRANGLES})

