#include "curve.h"

float Circle::getRadious() const
{
	return radious;
}

bool Circle::sortFunc(std::shared_ptr<Circle> a, std::shared_ptr<Circle> b)
{
	return (a->getRadious() < b->getRadious());
}

void Circle::printPoint(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		std::cout << "[" << radious * cos(t_var) << ", " << radious * sin(t_var) << ", " << 0 << "]" << std::endl;
	}
}

void Circle::printDerivative(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		std::cout << "[" << ((radious * cos(t_var + h)) - (radious * cos(t_var - h))) / (2.0 * h) <<
			", " << ((radious * sin(t_var + h)) - (radious * sin(t_var - h))) / (2.0 * h) <<
			", " << 0 << "]" << std::endl;
	}
}

void Circle::printInfo() const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Type of curve: " << figureName << std::endl;
	std::cout << "Radious is: " << radious << std::endl;
	std::cout << "----------------------" << std::endl;
}

void Ellipse::printPoint(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		std::cout << "[" << radious_x * cos(t_var) << ", " << radious_y * sin(t_var) << ", " << 0 << "]" << std::endl;
	}
}

void Ellipse::printDerivative(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		std::cout << "[" << ((radious_x * cos(t_var + h)) - (radious_x * cos(t_var - h))) / (2.0 * h) <<
			", " << ((radious_y * sin(t_var + h)) - (radious_y * sin(t_var - h))) / (2.0 * h) <<
			", " << 0 << "]" << std::endl;
	}
}

void Ellipse::printInfo() const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Type of curve: " << figureName << std::endl;
	std::cout << "X_Radiouses | Y_Radiouese is: " << radious_x << " | " << radious_y << std::endl;
	std::cout << "----------------------" << std::endl;
}

float Spiral::getRadious() const
{
	return radious;
}

void Spiral::printPoint(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		std::cout << "[" << radious * cos(t_var) << ", " << radious * sin(t_var) << ", " << step * t_var << "]" << std::endl;
	}
}

void Spiral::printDerivative(float t_var) const
{
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		std::cout << "[" << ((radious * cos(t_var + h)) - (radious * cos(t_var - h))) / (2.0 * h) <<
			", " << ((radious * sin(t_var + h)) - (radious * sin(t_var - h))) / (2.0 * h) <<
			", " << ((step * (t_var + h)) - (step * (t_var - h))) / (2.0 * h) << "]" << std::endl;
	}
}

void Spiral::printInfo() const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Type of curve: " << figureName << std::endl;
	std::cout << "Radious is: " << radious << std::endl;
	std::cout << "Step is: " << step << std::endl;
	std::cout << "----------------------" << std::endl;
}
