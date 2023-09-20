#include "triangle.h"
#include "quadrangle.h"
#include "creation_errors.h"

#include <iostream>

void print_info(Shape* shape) {
	std::cout << shape->get_name() << ":" << std::endl;
	std::cout << "Стороны: " << shape->get_edges_info() << std::endl;
	std::cout << "Углы: " << shape->get_angles_info() << std::endl;
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	try {
		Triangle tr(1,1,1,60,60,60);
		std::cout << "Создана фигура: " << std::endl;
		print_info(&tr);
	}
	catch (TriangleAngleSumException& err) {
		std::cout << "Ошибка создания фигуры: " << err.what() << std::endl;
		std::cout << std::endl;
	}
	
	try {
		Triangle tr(1, 1, 1, 60, 60, 56);
		std::cout << "Создана фигура: " << std::endl;
		print_info(&tr);
	}
	catch (TriangleAngleSumException &err) {
		std::cout << "Ошибка создания фигуры: " << err.what() << std::endl;
		std::cout << std::endl;
	}

	try {
		Quadrangle quad(1, 1, 1, 1, 90, 90, 90, 90);
		std::cout << "Создана фигура: " << std::endl;
		print_info(&quad);
	}
	catch (QuadrangleAngleSumException &err) {
		std::cout << "Ошибка создания фигуры: " << err.what() << std::endl;
		std::cout << std::endl;
	}

	try {
		Quadrangle quad(1, 1, 1, 1, 90, 90, 90, 91);
		std::cout << "Создана фигура: " << std::endl;
		print_info(&quad);
	}
	catch (QuadrangleAngleSumException& err) {
		std::cout << "Ошибка создания фигуры: " << err.what() << std::endl;
		std::cout << std::endl;
	}
	
}
