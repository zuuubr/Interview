#pragma once
#include <string>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

class �urve
{
private:
	// Variables

public:
	// Variables
	const std::string figureName;

	// Methods
	�urve(void) : figureName("unknown")
	{ }

	�urve(std::string name) : figureName(name)
	{ }
	virtual void printPoint(float t_var) const = 0;						// ������ � ����� �� ��������� 

	virtual void printDerivative(float t_var) const = 0;				// ����������������� � �����

	virtual void printInfo() const = 0;									// ��������� ����������
};


class Circle : public �urve
{
private:
	// Variables
	float radious;
public:
	// Variables

	// Methods
	Circle(float Or) : �urve("Circle"), radious(abs(Or))
	{ }

	float getRadious() const;

	// ������� ��� ���������� � ������� ����������� ��� std::sort
	static bool sortFunc(std::shared_ptr<Circle> a, std::shared_ptr<Circle> b);

	// ������ � ����� �� ���������
	void printPoint(float t_var) const override;

	// ����������������� � �����
	void printDerivative(float t_var) const override;

	// ��������� ����������
	void printInfo() const override;
};


class Ellipse : public �urve
{
private:
	// Variables
	float radious_x, radious_y;
public:
	// Variables

	// Methods
	Ellipse(float Or_x, float Or_y) : �urve("Ellipse"), radious_x(abs(Or_x)), radious_y(abs(Or_y))
	{ }

	// ������ � ����� �� ���������
	void printPoint(float t_var) const override;

	// ����������������� � �����
	void printDerivative(float t_var) const override;

	// ��������� ����������
	void printInfo() const override;
};


class Spiral : public �urve
{
private:
	// Variables
	float radious, step;
public:
	// Variables

	// Methods
	Spiral(float Or, float step_var) : �urve("Spiral"), radious(abs(Or)), step(abs(step_var))
	{ }

	float getRadious() const;

	// ������ � ����� �� ���������
	void printPoint(float t_var) const override;

	// ����������������� � �����
	void printDerivative(float t_var) const override;

	// ��������� ����������
	void printInfo() const override;
};
