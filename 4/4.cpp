/**
 * @file 4.cpp
 * @author kozlov alex(kozlov_a0@mail.ru)
 * @brief
 * @version 0.1
 * @date 2021-11-18
 *
 * @copyright Copyrig;ht (c) 2021
 *
 * 4. Inheritance
 * Создайте иерархию классов на основе класса Фигура.
 * Должны быть описаны классы Квадрат, Прямоугольник, Треугольник, Круг, Куб, Шар.
 * --Реализовать конструкторы,
 * --Методы, выводящие информацию о фигуре(название и тип),
 * --Методы, считающие площадь, периметр и объем(где он есть)
 */

#include <iostream>
 // #include <windows.h>
using namespace std;

class Figure //Базовый класс
{
protected:
	string name;
	string type;

public:
	Figure(string name, string type)
	{
		this->name = name;
		this->type = type;
	}

	//Реализуем виртуальные методы базового  класса
	string get_name()
	{
		std::cout << name << std::endl;
		return name;
	}
	string get_type()

	{
		std::cout << type << std::endl;
		return type;
	}
	void calc_area(double a)
	{ //Функция вычисления площади фигуры (квадрата)
		cout << "Сalc_square_area = " << a * a << endl;
	}
	void calc_perimeter(double a)
	{ //Функция вычисления периметра фигуры (квадрата)
		cout << "Сalc_square_perimeter = " << 4 * a << endl;
	}
};

/* 
class Shape2d : public Figure //Базовый класс
{
protected:
	// string name;
	string type;

public:
	Figure(string name, string type)
	{
		this->name = name;
		this->type = type;
	}

	//Реализуем виртуальные методы базового  класса
	string get_name()
	{
		std::cout << name << std::endl;
		return name;
	}
	string get_type()

	{
		std::cout << type << std::endl;
		return type;
	}
	void calc_area(double a)
	{ //Функция вычисления площади фигуры (квадрата)
		cout << "Сalc_square_area = " << a * a << endl;
	}
	void calc_perimeter(double a)
	{ //Функция вычисления периметра фигуры (квадрата)
		cout << "Сalc_square_perimeter = " << 4 * a << endl;
	}
};

class Shape3d{ //Базовый класс
 public:
   Shape3d(){};
   virtual double volume()=0;
};
class cube: public Shape3d{
 protected:
   double side;
 public:
   cube(double arg): side(arg)      {if (side<0) side=0;};
   double volume()                  {return side*side*side;}
   double getSide() const           {return side;}
   void setSide(double arg)         {if (arg>=0) side=arg;};
};
*/
class Square : public Figure //Класс-потомок (Квадрат)
{
private:
	double a;

public:
	Square(string name, string type, double side_a) : Figure(name, type)
	{
		std::cout << "/* Square */" << std::endl;
		this->a = side_a;
	};
	void calc_area()
	{
		Figure::calc_area(a);
	}
	void calc_perimeter()
	{
		Figure::calc_perimeter(a);
	}
};

class Rectangle : public Figure
{
private:
	double a, b;

public:
	Rectangle(string name, string type, double side_a, double side_b) : Figure(name, type)
	{
		std::cout << "/* Rectangle */" << std::endl;
		this->a = side_a;
		this->b = side_b;
	};

	void calc_area()
	{

		cout << a * b << endl;
	}


	void calc_perimeter()
	{
		cout << 2*(a + b) << endl;
	}
};
/*
class Triangle : Figure()
{
private:
	double a, b, c;


public:
	Triangle(string name, string type)
	{
		this->name = name;
		this->type = type;
	};
	~Triangle();
	string get_name()
	{
		return name;
	}

	double calcS();
	double calcP();
	double calcV();
};
class Circle : Figure()
{
private:
	string name;
	string type;

public:
	Circle(string name, string type)
	{
		this->name = name;
		this->type = type;
	};
	~Circle();
	string get_name()
	{
		return name;
	}

	double calcS();
	double calcP();
	double calcV();
};
class Cube : Figure()
{
private:
	string name;
	string type;

public:
	Cube(string name, string type)
	{
		this->name = name;
		this->type = type;
	};
	~Cube();
	string get_name()
	{
		return name;
	}

	double calcS();
	double calcP();
	double calcV();
};
class Ball : Figure()
{
private:
	string name;
	string type;

public:
	Ball(string name, string type)
	{
		this->name = name;
		this->type = type;
	};
	~Ball();
	string get_name()
	{
		return name;
	}

	double calcS();
	double calcP();
	double calcV();
};
*/

int main()
{
	system("chcp 1251");

	Square s("Фигура 1", "Квадрат", 1.1);
	s.get_name();
	s.get_type();
	s.calc_area();
	s.calc_perimeter();

	Rectangle r("Фигура 2", "Прямоугольник", 2.1, 2.2);
	r.get_name();
	r.get_type();
	r.calc_area();
	r.calc_perimeter();

	//s.calc_perimeter();
	std::cout << "/* finish */" << std::endl;
	return 0;
}