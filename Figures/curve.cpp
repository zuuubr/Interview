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
	std::vector<float> point = getPoint(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Point in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
	}
}

std::vector<float> Circle::getPoint(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		point.push_back(radious * cos(t_var));
		point.push_back(radious * sin(t_var));
		point.push_back(0);
	}

	return point;
}

std::vector<float> Circle::getDerivative(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		point.push_back(((radious * cos(t_var + h)) - (radious * cos(t_var - h))) / (2.0 * h));
		point.push_back(((radious * sin(t_var + h)) - (radious * sin(t_var - h))) / (2.0 * h));
		point.push_back(0);
	}

	return point;
}

void Circle::printDerivative(float t_var) const
{
	std::vector<float> point = getDerivative(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Derivate oint in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
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
	std::vector<float> point = getPoint(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Point in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
	}
}

std::vector<float> Ellipse::getPoint(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		point.push_back(radious_x * cos(t_var));
		point.push_back(radious_y * sin(t_var));
		point.push_back(0);
	}

	return point;
}

std::vector<float> Ellipse::getDerivative(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		point.push_back(((radious_x * cos(t_var + h)) - (radious_x * cos(t_var - h))) / (2.0 * h));
		point.push_back(((radious_y * sin(t_var + h)) - (radious_y * sin(t_var - h))) / (2.0 * h));
		point.push_back(0);
	}

	return point;
}

void Ellipse::printDerivative(float t_var) const
{
	std::vector<float> point = getDerivative(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Derivate oint in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
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

bool Spiral::sortFunc(std::shared_ptr<Spiral> a, std::shared_ptr<Spiral> b)
{
	return (a->getRadious() < b->getRadious());
}

void Spiral::printPoint(float t_var) const
{
	std::vector<float> point = getPoint(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Point in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
	}
}

std::vector<float> Spiral::getPoint(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		point.push_back(radious * cos(t_var));
		point.push_back(radious * sin(t_var));
		point.push_back(step * t_var);
	}

	return point;
}

std::vector<float> Spiral::getDerivative(float t_var) const
{
	std::vector<float> point;
	if (t_var < 0 || t_var > 2 * M_PI) {
		std::cout << "ERROR INPUT" << std::endl;
	}
	else {
		const double h = 1e-10;
		point.push_back(((radious * cos(t_var + h)) - (radious * cos(t_var - h))) / (2.0 * h));
		point.push_back(((radious * sin(t_var + h)) - (radious * sin(t_var - h))) / (2.0 * h));
		point.push_back(((step * (t_var + h)) - (step * (t_var - h))) / (2.0 * h));
	}

	return point;
}

void Spiral::printDerivative(float t_var) const
{
	std::vector<float> point = getDerivative(t_var);
	if (point.empty()) {
		std::cout << "Empty vector (error input)" << std::endl;
	}
	else {
		std::cout << "Derivate oint in Pi / 4: [" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
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
