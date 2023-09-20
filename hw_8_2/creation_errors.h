#pragma once

#include <exception>

class TriangleAngleSumException : public std::exception
{
public:
	const char* what() const override;
};

class QuadrangleAngleSumException : public std::exception
{
public:
	const char* what() const override; 
};