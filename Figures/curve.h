#pragma once
#include <string>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

class Сurve
{
private:
	// Variables

public:
	// Variables
	const std::string figureName;

	// Methods
	Сurve(void) : figureName("unknown")
	{ }

	Сurve(std::string name) : figureName(name)
	{ }

	virtual std::vector<float> getPoint(float t_var) const = 0;

	virtual std::vector<float> getDerivative(float t_var) const = 0;

	virtual void printPoint(float t_var) const = 0;						// Вектор к точке по параметру 

	virtual void printDerivative(float t_var) const = 0;				// Дифференцирование в точке

	virtual void printInfo() const = 0;									// Подробная информация
};


class Circle : public Сurve
{
private:
	// Variables
	float radious;
public:
	// Variables

	// Methods
	Circle(float Or) : Сurve("Circle"), radious(abs(Or))
	{ }

	// Функция возращает радиус
	float getRadious() const;

	// Функция для сортировки в порядке возрастания для std::sort
	static bool sortFunc(std::shared_ptr<Circle> a, std::shared_ptr<Circle> b);

	// Вектор к точке по параметру
	void printPoint(float t_var) const override;

	std::vector<float> getPoint(float t_var) const override;

	std::vector<float> getDerivative(float t_var) const override;

	// Дифференцирование в точке
	void printDerivative(float t_var) const override;

	// Подробная информация
	void printInfo() const override;
};


class Ellipse : public Сurve
{
private:
	// Variables
	float radious_x, radious_y;
public:
	// Variables

	// Methods
	Ellipse(float Or_x, float Or_y) : Сurve("Ellipse"), radious_x(abs(Or_x)), radious_y(abs(Or_y))
	{ }

	// Вектор к точке по параметру
	void printPoint(float t_var) const override;

	std::vector<float> getPoint(float t_var) const override;

	std::vector<float> getDerivative(float t_var) const override;

	// Дифференцирование в точке
	void printDerivative(float t_var) const override;

	// Подробная информация
	void printInfo() const override;
};


class Spiral : public Сurve
{
private:
	// Variables
	float radious, step;
public:
	// Variables

	// Methods
	Spiral(float Or, float step_var) : Сurve("Spiral"), radious(abs(Or)), step(abs(step_var))
	{ }

	// Функция возращает радиус
	float getRadious() const;

	// Функция для сортировки в порядке возрастания для std::sort
	static bool sortFunc(std::shared_ptr<Spiral> a, std::shared_ptr<Spiral> b);

	// Вектор к точке по параметру
	void printPoint(float t_var) const override;

	std::vector<float> getPoint(float t_var) const override;

	std::vector<float> getDerivative(float t_var) const override;

	// Дифференцирование в точке
	void printDerivative(float t_var) const override;

	// Подробная информация
	void printInfo() const override;
};
