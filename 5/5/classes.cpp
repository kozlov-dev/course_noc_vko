#include <iostream>
#include <string>
#include "classes.h"

using namespace std;
// Figure::Figure(string _name)
public:
	Figure(string name, int type) { _name = name; _type = type; }

	// абстрактные методы базового  класса
	string get_name() const { return _name; }
	virtual int get_type() const { return _type; }
	virtual double calc_area() const = 0;
	virtual double calc_perimeter() const = 0;

	friend ostream& operator<<(ostream& os, const Figure& fig) { return fig.write(os); }
	friend istream& operator>>(istream& in, Figure& fig) { return fig.read(in); }
};

// Figure::Figure(string _name)
// {
// 	name = _name;
// 	type = FIGURE_TYPE_UNDEFINED;
// }
// //Реализуем методы базового  класса
// string Figure::get_name()
// {
// 	std::cout << name << std::endl;
// 	return name;
// }
// int Figure::get_type()
// {
// 	std::cout << type << std::endl;
// 	return type;
// }
//  double Figure::calc_area() {return 0;}

//------------------------------------------------------------------------
Square::Square(string _name, double side_a) : Figure(_name)
{
	type = FIGURE_TYPE_SQUARE;
	a = side_a;
}
double Square::calc_area()
{
	std::cout << "Square area = " << a * a << endl;
	return a * a;
}
double Square::calc_perimeter()
{
	std::cout << "Square perimeter = " << 4 * a << endl;
	return 4 * a;
}
//------------------------------------------------------------------------
Rectangle::Rectangle(string _name, double side_a, double side_b) : Figure(_name)
{
	type = FIGURE_TYPE_RECTANGLE;
	a = side_a;
	b = side_b;
}
// Реализация методов
double Rectangle::calc_area()
{
	std::cout << "Rectangle area = " << a * b << endl;
	return a * b;
}
double Rectangle::calc_perimeter()
{
	std::cout << "Rectangle perimeter = " << a * b << endl;

	std::cout << 2 * (a + b) << endl;
	return 2 * (a + b);
}
//------------------------------------------------------------------------
Triangle::Triangle(string _name, double side_a, double side_b, double side_c) : Figure(_name)
{
	type = FIGURE_TYPE_TRIANGLE;
	a = side_a;
	b = side_b;
	c = side_c;
}
// Реализация методов
double Triangle::calc_area()
{
	std::cout << "Triangle area = " << 0.5 * (a * b) << endl;
	return 0.5 * (a * b);
}
double Triangle::calc_perimeter()
{
	std::cout << "Triangle perimeter = " << a + b + c << endl;
	return a + b + c;
}
//------------------------------------------------------------------------
Circle::Circle(string _name, double side_r) : Figure(_name)
{
	type = FIGURE_TYPE_CIRCLE;
	r = side_r;
}
// Реализация методов
double Circle::calc_area()
{
	std::cout << "Circle area = " << 3.14 * r << endl;
	return 3.14 * r;
}
double Circle::calc_perimeter()
{
	std::cout << "Circle perimeter = " << 2 * r * 3.14 << endl;
	return 2 * r * 3.14;
}
//------------------------------------------------------------------------
Cube::Cube(string _name, double side_s) : Figure(_name)
{
	type = FIGURE_TYPE_CUBE;
	s = side_s;
}
// Реализация методов
double Cube::calc_volume()
{
	std::cout << "Cube volume = " << s * s * s << endl;
	return s * s * s;
}
//------------------------------------------------------------------------
Ball::Ball(string _name, double side_r) : Figure(_name)
{
	type = FIGURE_TYPE_CUBE;
	r = side_r;
}
// Реализация методов
double Ball::calc_volume()
{
	std::cout << (4 / 3) * (3.14 * (r * r * r)) << endl;
	return (4 / 3) * (3.14 * (r * r * r));
}
