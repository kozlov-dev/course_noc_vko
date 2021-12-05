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
#include <fstream>

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

	//virtual std::ostream& write(std::ostream& os) const = 0;
	//virtual std::istream& read(std::istream& is) = 0;

public:
	Figure(string _name)
	{
		name = _name;
		type = FIGURE_TYPE_UNDEFINED;
	}
	~Figure() { std::cout << " Figure destructor " << std::endl; }

	// абстрактные методы базового  класса
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
	virtual double calc_area() = 0;
	virtual double calc_perimeter() = 0;

	friend ostream& operator<<(ostream&, Figure*&);
	friend istream& operator>>(ostream&, Figure*&);

};
class Figure3d : public Figure//Базовый класс 3d figure
{

public:
	Figure3d(string name) : Figure(name) {}

	virtual double calc_volume() = 0;
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

	double Figure::calc_area()
	{
		cout << "Square area = " << a * a << endl;
		return a * a;
	}

	double Figure::calc_perimeter()
	{
		cout << "Square perimeter = " << 4 * a << endl;
		return 4 * a;
	}

	friend ostream& operator<<(ostream&, Figure*&);
	friend istream& operator>>(ostream&, Figure*&);
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

	friend ostream& operator<<(ostream&, Figure*&);
	friend istream& operator>>(istream&, Figure*&);

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


	friend ostream& operator<<(ostream&, Figure*&);
	friend istream& operator>>(istream&, Figure*&);
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


	friend ostream& operator<<(ostream&, Figure*&);
	friend istream& operator>>(istream&, Figure*&);
};
class Cube : public Figure3d
{
private:
	double s;

public:
	Cube(string _name, double side_s) : Figure3d(_name)
	{
		// type = FIGURE_TYPE_CUBE;
		s = side_s;
	}
	~Cube() { std::cout << " Cube destructor  " << std::endl; }

	// Реализация методов

	double calc_area()
	{
		return 0;
	}

	double calc_perimeter()
	{
		return 0;
	}
	double calc_volume()
	{
		cout << "Cube volume = " << s * s * s << endl;
		return s * s * s;
	}


	friend ostream& operator<<(ostream&, Figure3d*&);
	friend istream& operator>>(istream&, Figure3d*&);
};
class Ball : public Figure3d
{
private:
	double r;

public:
	Ball(string _name, double side_r) : Figure3d(_name)
	{
		type = FIGURE_TYPE_CUBE;
		r = side_r;
	}
	~Ball() { std::cout << " Ball destructor  " << std::endl; }

	// Реализация методов
	double calc_area()
	{
		return 0;
	}

	double calc_perimeter()
	{
		return 0;
	}

	double calc_volume()
	{
		cout << "Cube volume = " << (4 / 3) * (3.14 * (r * r * r)) << endl;
		return (4 / 3) * (3.14 * (r * r * r));
	}

	friend ostream& operator<<(ostream&, Figure3d*&);
	friend istream& operator>>(istream&, Figure3d*&);
};
void generate_data(string file_name)
{
	const int number_of_names = 9;
	string names[number_of_names]{ "Jack", "Tom", "Ivan", "Peter", "Anna", "Kate", "Lisa", "Alex", "John" };
	string types[]{ "t", "s" };

	int number_of_people = rand() % (10 + 1);
	ofstream out(file_name);

	for (int i = 0; i < number_of_people; i++)
	{
		int type = rand() % 2;
		out << types[type] << " " << names[rand() % number_of_names] << " " << rand() % 100 << " ";
		if (types[type] == "t")
		{
			out << rand() % 100 << endl;
		}
		else
		{
			out << rand() % 6 << endl;
		}
	}
	out.close();
	//return number_of_people;
}

double calc_max_perimert(Figure*& f, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result < f->calc_perimeter())
		{
			result = f->calc_perimeter();
		}
	}
	return result;

}
ostream& operator<<(ostream& out, Figure*& f)
{
	out << f->get_name() << " " << f->get_type() << f->calc_perimeter() << endl;
	if (dynamic_cast<Square*>(f))
	{
		out << (dynamic_cast<Square*>(f))->calc_perimeter() << endl;
	}
	else if (dynamic_cast<Rectangle*>(f))
	{
		out << (dynamic_cast<Rectangle*>(f))->calc_perimeter() << endl;
	}
	else if (dynamic_cast<Triangle*>(f))
	{
		out << (dynamic_cast<Triangle*>(f))->calc_perimeter() << endl;
	}
	else if (dynamic_cast<Circle*>(f))
	{
		out << (dynamic_cast<Circle*>(f))->calc_perimeter() << endl;
	}
	return out;
}
istream& operator>>(istream& in, Figure*& f) {
	if (dynamic_cast<Square*>(f))
	{
		//in >> (dynamic_cast<Square*>(f))->;
		return in;
	}
	else if (dynamic_cast<Rectangle*>(f))
	{
		in >> (dynamic_cast<Rectangle*>(f))->a >> (dynamic_cast<Rectangle*>(f))->b;
		return in;
	}
}
int main()
{

	Square s("Square 1", 1.1);
	Rectangle r("Rectangle 2", 2.1, 2.2);
	Triangle t("Triangle 3", 3.1, 3.2, 3.3);
	Circle c("Circle 4", 4);
	Cube cb("Cube 5", 5);
	Ball b("Ball 6", 6);

	Figure* ptr;
	ptr = &s;
	ptr->get_name();
	ptr->calc_perimeter();
	ptr = &r;
	ptr->get_type();
	ptr->calc_perimeter();
	ptr = &cb;
	dynamic_cast<Figure3d*>(ptr)->calc_volume();
	ptr = &b;
	dynamic_cast<Figure3d*>(ptr)->calc_volume();
	std::cout << "  finish " << std::endl;

	int n = 2;
	//cout << "Input n: ";
	//cin >> n;
	Figure** figures = new Figure * [n];
	for (int i = 0; i < n; i++) {
		figures[i] = new Rectangle("rec1", i + 10, i * 3.3);// (i + 1); // todo random;
		cout << figures[i];
	}


	//calc_max_perimert(figures, n);


	generate_data("ff");
	return 0;
}
