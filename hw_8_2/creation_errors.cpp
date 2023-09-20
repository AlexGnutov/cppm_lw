#include "creation_errors.h"

const char* TriangleAngleSumException::what() const {
	return "Сумма углов треугольника не равна 180 градусам";
}

const char* QuadrangleAngleSumException::what() const {
	return "Сумма углов четырёхугольника не равна 360 градусам";
}