#include "creation_errors.h"

const char* TriangleAngleSumException::what() const {
	return "����� ����� ������������ �� ����� 180 ��������";
}

const char* QuadrangleAngleSumException::what() const {
	return "����� ����� ��������������� �� ����� 360 ��������";
}