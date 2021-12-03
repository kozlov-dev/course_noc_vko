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
#include "classes.h"
#include <fstream>

using namespace std;

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

	Figure* ptr;
	ptr = &s;
	ptr->calc_area();
	ptr = &r;
	ptr->calc_area();




	std::cout << "  finish " << std::endl;
	return 0;
}
