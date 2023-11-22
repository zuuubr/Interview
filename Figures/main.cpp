#include <algorithm>
#include <iostream>
#include <vector>
#include "curve.h"


int main()
{
	std::vector<std::shared_ptr<Сurve>> curves;
	for (int i = 0; i < 10; i++) {
		curves.push_back(std::make_shared<Circle>(10 - i));
		curves.push_back(std::make_shared<Ellipse>(1 + i, 1 + (2 * i)));
		curves.push_back(std::make_shared<Spiral>(1 + i, 2 + i));
	}
	curves.push_back(std::make_shared<Circle>(-5));
	curves.push_back(std::make_shared<Ellipse>(-5, -5));
	curves.push_back(std::make_shared<Spiral>(-5, -5));

	std::vector<std::shared_ptr<Circle>> circles;
	for (int i = 0; i < curves.size(); i++) {

		// Выведем информацию о фигуре
		curves[i]->printInfo();

		// Выведем точку в Pi / 4
		curves[i]->printPoint(0);

		// Выведем значение производной в точке Pi / 4
		curves[i]->printDerivative(M_PI / 4);

		// Заполним вектор circles копиями элементов из вектора всех кривых curves, которые равны "Circle"
		auto circle = std::dynamic_pointer_cast<Circle>(curves[i]);
		if (circle) {
			circles.push_back(std::make_shared<Circle>(*circle));
		}
	}
	std::cout << std::endl;

	// Сортировка вектора с окружностями в порядке возрастания
	std::sort(circles.begin(), circles.end(), Circle::sortFunc);
	float radious = 0;
	for (int i = 0; i < circles.size(); i++) {
		// Выведем на экран информацию об элементах отсортированного вектора окружностей
		circles[i]->printInfo();
		radious += circles[i]->getRadious();
	}
	std::cout << std::endl;

	std::cout << "Sum of all radiouses: " << radious << std::endl;
	return 0;
}
