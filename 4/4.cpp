/*
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
private:
	// double x, y; // начальные координаты

protected:
	string name;
	string type;

public:
	Figure(string _name, string _type)
	{
		name = _name;
		type = _type;
	}
	~Figure() { std::cout << " Figure destructor " << std::endl; }

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
	// В данный момент непонятно, что за фигура и какие у нее параметры, поэтому функции возвращают 0
	double calc_area() const { return 0; }
	double calc_perimeter() const { return 0; }
	double calc_volume() const { return 0; }
};

class Square : public Figure //Класс-потомок (Квадрат)
{
private:
	double a;

public:
	Square(string _name, double side_a) : Figure(name, type)
	{
		std::cout << "  Square " << std::endl;
		string type = "Квадрат";
		this->a = side_a;
	};

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return name;
	}
	double calc_area()
	{
		cout << a * a << endl;
		return a * a;
		// Figure::calc_area(a);
	}
	double calc_perimeter()
	{
		cout << 4 * a << endl;
		return 4 * a;
		// Figure::calc_perimeter(a);
	}
};
/*
class Rectangle : public Figure
{
private:
	double a, b;

public:
	Rectangle( string name, string type, double side_a, double side_b) : Figure(name, type)
	{
		std::cout << " Rectangle " << std::endl;
		this->a = side_a;
		this->b = side_b;
	};
	~Rectangle() { std::cout << " Rectangle destructor  " << std::endl; }

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return name;
	}
	// Реализация методов
	double calc_area()
	{
		cout << a * b << endl;
		return a * b;
	}

	double calc_perimeter()
	{
		cout << 2 * (a + b) << endl;
		return 2 * (a + b);
	}
};

class Triangle : Figure
{
private:
	double a, b, c;

public:
	Triangle( string name, string type, double side_a, double side_b, double side_c) : Figure(name, type)
	{
		std::cout << "Triangle" << std::endl;
		this->a = side_a;
		this->b = side_b;
		this->c = side_c;
	};
	~Triangle() { std::cout << " Triangle destructor " << std::endl; }

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return type;
	}
	// Реализация методов
	double calc_area()
	{
		cout << 0.5 * (a * b) << endl;
		return 0.5 * (a * b);
	}

	double calc_perimeter()
	{
		cout << a + b + c << endl;
		return a + b + c;
	}
};
class Circle : Figure
{
private:
	double r;

public:
	Circle( string name, string type, double side_r) : Figure(name, type)
	{
		std::cout << "  Circle " << std::endl;
		this->r = side_r;
	};
	~Circle() { std::cout << " Circle destructor " << std::endl; }

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return type;
	}
	// Реализация методов
	double calc_area()
	{
		cout << 3.14 * r << endl;
		return 3.14 * r;
	}

	double calc_perimeter()
	{
		cout << 2 * r * 3.14 << endl;
		return 2 * r * 3.14;
	}
};

class Cube : Figure
{
private:
	double s;

public:
	Cube( string name, string type, double side_s) : Figure(name, type)
	{
		std::cout << "  Circle " << std::endl;
		this->s = side_s;
	};
	~Cube() { std::cout << " Circle destructor " << std::endl; }

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return type;
	}
	// Реализация методов
	double calc_volume()
	{
		cout << s * s * s << endl;
		return s * s * s;
	}
};

class Ball : Figure
{
private:
	double r;

	Ball( string name, string type, double side_r) : Figure(name, type)
	{
		std::cout << "  Ball " << std::endl;
		this->r = side_r;
	};
	~Ball() { std::cout << " Ball destructor " << std::endl; }

	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return type;
	}
	// Реализация методов
	double calc_volume()
	{
		cout << (4 / 3) * (3.14 * (r * r * r)) << endl;
		return (4 / 3) * (3.14 * (r * r * r));
	}
};
 */
int main()
{
	system("chcp 1251");

	Square s("Фигура 1", 1.1);
	s.get_name();
	s.get_type();
	s.calc_area();
	s.calc_perimeter();
	
	/*

	Rectangle r("Фигура 2", "Прямоугольник", 2.1, 2.2);
	r.get_name();
	r.get_type();
	r.calc_area();
	r.calc_perimeter();

	Triangle t("Фигура 3", "Треугольник", 3.1, 3.2, 3.3);
	t.get_name();
	t.get_type();
	t.calc_area();
	t.calc_perimeter();

	Circle c("Фигура 4", "Круг", 4);
	r.get_name();
	r.get_type();
	r.calc_area();
	r.calc_perimeter();
	*/

		std::cout << "  finish " << std::endl;
	return 0;
}