/*
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
	string _name;
	int _type;

	virtual std::ostream& write(std::ostream& os) const = 0;
	virtual std::istream& read(std::istream& is) = 0;

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

class Figure3d : public Figure//Базовый класс 3d figure
{

public:
	Figure3d(string name, int type) : Figure("Square", type) { }

	virtual double calc_volume() const = 0;
};

class Square : public Figure //Класс-потомок (Квадрат)
{
private:
	double _size;

	std::ostream& write(std::ostream& os) const
	{
		os << _name << " with size: " << _size;
		return os;
	}

	istream& read(istream& in)
	{
		in >> _size;
		return in;
	}

public:
	Square(double size) : Figure("Square", FIGURE_TYPE_SQUARE) { _size = size; }
	double calc_area() const { return _size * _size; }
	double calc_perimeter() const { return 4 * _size; }
};

class Cube : public Figure3d //Класс-потомок (Куб)
{
private:
	double _size;

	ostream& write(ostream& os) const
	{
		os << _name << " with size: " << _size;
		return os;
	}

	istream& read(istream& in)
	{
		in >> _size;
		return in;
	}

public:
	Cube(double size) : Figure3d("Cube", FIGURE_TYPE_CUBE) { _size = size; }
	double calc_area() const { return 6 * _size * _size; }
	double calc_perimeter() const { return 12 * _size; }
	double calc_volume() const { return _size * _size * _size; }
};

int main()
{
	int n = 2;
	cout << "Input n: ";
	 cin >> n;
	Figure** figures = new Figure * [n];
	for (int i = 0; i < n; i++) {
		figures[i] = new Cube(i + 1); // todo random;
	}
	cout << *figures[0];

	return 0;
}