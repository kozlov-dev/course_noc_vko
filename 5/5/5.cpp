/*
Для прошлого задания
(
	Создайте иерархию классов на основе класса Фигура.
	Должны быть описаны классы Квадрат, Прямоугольник, Треугольник, Круг, Куб, Шар.
	--Реализовать конструкторы,
	--Методы, выводящие информацию о фигуре(название и тип),
	--Методы, считающие площадь, периметр и объем(где он есть)
)
Добавьте следующие возможности:
--Базовый класс должен быть абстрактным
--Создать динамический массив на n элементов(вводится пользователем) и добавить в него набор различных фигур случайным образом
--Найти фигуру с самой большой площадью. Если таких фигур несколько вывести все
--Перегрузить операторы ввода и вывода для фигур
--Результат вывести в файл
--Классы разбить по файлам
*/
#include <iostream>
// #include <windows.h>
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
	Figure(string _name)
	{
		name = _name;
		type = FIGURE_TYPE_UNDEFINED;
	}
	~Figure() { std::cout << " Figure destructor " << std::endl; }

	//Реализуем методы базового  класса
	string get_name()
	{
		std::cout << name << std::endl;
		return name;
	}
	int get_type()
	{
		std::cout << type << std::endl;
		return type;
	}
};

class Square : public Figure //Класс-потомок (Квадрат)
{
private:
	double a;

public:
	Square(string _name, double side_a) : Figure(_name)
	{
		type = FIGURE_TYPE_SQUARE;
		a = side_a;
	}
	~Square() { std::cout << " Rectangle destructor  " << std::endl; }
	double calc_area()
	{
		cout << "Square area = " << a * a << endl;
		return a * a;
	}

	double calc_perimeter()
	{
		cout << "Square perimeter = " << 4 * a << endl;
		return 4 * a;
	}
};

class Rectangle : public Figure
{
private:
	double a, b;

public:
	Rectangle(string _name, double side_a, double side_b) : Figure(_name)
	{
		type = FIGURE_TYPE_RECTANGLE;
		a = side_a;
		b = side_b;
	}
	~Rectangle() { std::cout << " Rectangle destructor  " << std::endl; }

	// Реализация методов
	double calc_area()
	{
		cout << "Rectangle area = " << a * b << endl;
		return a * b;
	}

	double calc_perimeter()
	{
		cout << "Rectangle perimeter = " << a * b << endl;

		cout << 2 * (a + b) << endl;
		return 2 * (a + b);
	}
};
class Triangle : public Figure
{
private:
	double a, b, с;

public:
	Triangle(string _name, double side_a, double side_b, double side_с) : Figure(_name)
	{
		type = FIGURE_TYPE_TRIANGLE;
		a = side_a;
		b = side_b;
		с = side_с;
	}
	~Triangle() { std::cout << " Triangle destructor  " << std::endl; }

	// Реализация методов
	double calc_area()
	{
		cout << "Triangle area = " << 0.5 * (a * b) << endl;
		return 0.5 * (a * b);
	}

	double calc_perimeter()
	{
		cout << "Triangle perimeter = " << a + b + с << endl;
		return a + b + с;
	}
};

class Circle : public Figure
{
private:
	double r;

public:
	Circle(string _name, double side_r) : Figure(_name)
	{
		type = FIGURE_TYPE_CIRCLE;
		r = side_r;
	}
	~Circle() { std::cout << " Circle destructor  " << std::endl; }

	// Реализация методов
	double calc_area()
	{
		cout << "Circle area = " << 3.14 * r << endl;
		return 3.14 * r;
	}

	double calc_perimeter()
	{
		cout << "Circle perimeter = " << 2 * r * 3.14 << endl;
		return 2 * r * 3.14;
	}
};

class Cube : public Figure
{
private:
	double s;

public:
	Cube(string _name, double side_s) : Figure(_name)
	{
		type = FIGURE_TYPE_CUBE;
		s = side_s;
	}
	~Cube() { std::cout << " Cube destructor  " << std::endl; }

	// Реализация методов
	double calc_volume()
	{
		cout << "Cube volume = " << s * s * s << endl;
		return s * s * s;
	}
};

class Ball : public Figure
{
private:
	double r;

public:
	Ball(string _name, double side_r) : Figure(_name)
	{
		type = FIGURE_TYPE_CUBE;
		r = side_r;
	}
	~Ball() { std::cout << " Ball destructor  " << std::endl; }

	// Реализация методов
	double calc_volume()
	{
		cout << (4 / 3) * (3.14 * (r * r * r)) << endl;
		return (4 / 3) * (3.14 * (r * r * r));
	}
};
int main()
{
	Square s("Square 1", 1.1);
	s.get_name();
	s.get_type();
	s.calc_area();
	s.calc_perimeter();

	Rectangle r("Rectangle 2", 2.1, 2.2);
	r.get_name();
	r.get_type();
	r.calc_area();
	r.calc_perimeter();

	Triangle t("Triangle 3", 3.1, 3.2, 3.3);
	t.get_name();
	t.get_type();
	t.calc_area();
	t.calc_perimeter();

	Circle c("Circle 4", 4);
	c.get_name();
	c.get_type();
	c.calc_area();
	c.calc_perimeter();

	Cube cb("Cube 5", 5);
	cb.get_name();
	cb.get_type();
	cb.calc_volume();

	Ball b("Ball 6", 6);

	b.get_name();
	b.get_type();
	b.calc_volume();

	std::cout << "  finish " << std::endl;
	return 0;
}
