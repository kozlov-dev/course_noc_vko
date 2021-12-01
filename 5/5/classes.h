#pragma once

#include <iostream>
#include <string>


using namespace std;

#define FIGURE_TYPE_UNDEFINED 0
#define FIGURE_TYPE_SQUARE 1
#define FIGURE_TYPE_RECTANGLE 2
#define FIGURE_TYPE_TRIANGLE 3
#define FIGURE_TYPE_CIRCLE 4
#define FIGURE_TYPE_CUBE 5
#define FIGURE_TYPE_BALL 6

class Figure //Базовый класс
{
protected:
	string name;
	int type;

public:
	Figure(string);
	~Figure() { std::cout << " Figure destructor " << std::endl; }
	//Реализуем методы базового  класса
	virtual string get_name();
	virtual int get_type();
	virtual double calc_area();

};
//------------------------------------------------------------------------
class Square : public Figure //Класс-потомок (Квадрат)
{
private:
	double a;

public:
	Square(string, double);
	~Square() { std::cout << " Figure destructor " << std::endl; }
	double calc_area();
	double calc_perimeter();
};
//------------------------------------------------------------------------
class Rectangle : public Figure
{
private:
	double a, b;

public:
	Rectangle(string, double, double);
	~Rectangle() { std::cout << " Rectangle destructor  " << std::endl; }
	// Реализация методов
	double calc_area();
	double calc_perimeter();
};
//------------------------------------------------------------------------
class Triangle : public Figure
{
private:
	double a, b, c ;

public:
	Triangle(string, double, double, double);
	~Triangle() { std::cout << " Triangle destructor  " << std::endl; }

	// Реализация методов
	double calc_area();
	double calc_perimeter();
};
//------------------------------------------------------------------------
class Circle : public Figure
{
private:
	double r;

public:
	Circle(string, double);
	~Circle() { std::cout << " Circle destructor  " << std::endl; }
	// Реализация методов
	double calc_area();
	double calc_perimeter();

};
//------------------------------------------------------------------------
class Cube : public Figure
{
private:
	double s;

public:
	Cube(string, double);
	~Cube() { std::cout << " Cube destructor  " << std::endl; }
	// Реализация методов
	double calc_volume();
};
//------------------------------------------------------------------------

class Ball : public Figure
{
private:
	double r;

public:
	Ball(string, double);
	~Ball() { std::cout << " Ball destructor  " << std::endl; }
	// Реализация методов
	double calc_volume();
};
