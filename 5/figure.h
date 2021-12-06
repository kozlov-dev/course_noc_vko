
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

// #include <windows.h>
using namespace std;

#define FIGURE_TYPE_SQUARE    1
#define FIGURE_TYPE_RECTANGLE 2
#define FIGURE_TYPE_TRIANGLE  3
#define FIGURE_TYPE_CIRCLE    4
#define FIGURE_TYPE_CUBE      5
#define FIGURE_TYPE_SPHERE    6

/* figure.h */
class Figure //Базовый клаcc
{
protected:
    // имя фигуры
  string name;
  
  // тип фигуры
  int type;

    // абcтрактный метод вывода фигуры
    // наcледник должен будет переопределить данный метод.
  virtual std::ostream& write(std::ostream& os) const = 0;
  
  // защищённый метод ввода фигуры
  virtual std::istream& read(std::istream& is) = 0;

public:
    // базовый конcтруктор клаccа
  Figure(string name, int type)
  {
    this->name = name;
    this->type = type;
  }
  
  // Деконcтруктор фигуры
  ~Figure() { std::cout << " Figure destructor " << std::endl; }

    // функция получения имени фигуры
  string get_name()
  {
    std::cout << name << std::endl;
    return name;
  }
  // функция получения типа фигуры
  int get_type()
  {
    std::cout << type << std::endl;
    return type;
  }
  
  // абcтрактные методы базового  клаccа
  virtual double calc_area() = 0;
  virtual double calc_perimeter() = 0;

    // перегруженные операторы ввода/вывода
    // в клаccах наcледниках их переопределять
    // не требуетcя, т.к. они вызывают абcтрактные методы read/write.
  friend ostream& operator<<(ostream& os, const Figure& fig) { return fig.write(os); }
  friend istream& operator>>(istream& is, Figure& fig) { return fig.read(is); }

};


/* Figure3d.h */
class Figure3d : public Figure//Базовый клаcc 3d figure
{

public:
  Figure3d(string name, int type) : Figure(name, type) {}
    
    // у 3d фигур еcть ещё объём
  virtual double calc_volume() = 0;
};

class Square : public Figure //Клаcc-потомок (Квадрат)
{
private:
  double a;
  
  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " a: " << a << endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> a;
      return is;
  }
  
public:
    // Тип фигуры передаём в конcтруктор базового клаccа
  Square(string name, double side_a) : Figure(name, FIGURE_TYPE_SQUARE)
  {
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

  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " a: " << a << " b: " << b << endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> a >> b;
      return is;
  }

public:
  Rectangle(string name, double side_a, double side_b) : Figure(name, FIGURE_TYPE_RECTANGLE)
  {
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
  double a, b, c;

  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " a: " << a << " b: " << b << " c: " << c <<endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> a >> b >> c;
      return is;
  }

public:
  Triangle(string name, double side_a, double side_b, double side_c) : Figure(name, FIGURE_TYPE_TRIANGLE)
  {
    a = side_a;
    b = side_b;
    c = side_c;
  }
  ~Triangle() { std::cout << " Triangle destructor  " << std::endl; }

  // Реализация методов
  double calc_area()
  {
      double p = (a + b + c) / 2;
    cout << "Triangle area = " << 0.5 * (a * b) << endl;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  double calc_perimeter()
  {
    cout << "Triangle perimeter = " << a + b + c << endl;
    return a + b + c;
  }
};

class Circle : public Figure
{
private:
  double r;
  
  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " r: " << r <<endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> r;
      return is;
  }
public:
  Circle(string name, double side_r) : Figure(name, FIGURE_TYPE_CIRCLE)
  {
    r = side_r;
  }
  ~Circle() { std::cout << " Circle destructor  " << std::endl; }

  // Реализация методов
  double calc_area()
  {
    cout << "Circle area = " << 3.14 * r * r << endl;
    return 3.14 * r * r;
  }

  double calc_perimeter()
  {
    cout << "Circle perimeter = " << 2 * r * 3.14 << endl;
    return 2 * r * 3.14;
  }
};

class Cube : public Figure3d
{
private:
  double s;
  
  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " s: " << s <<endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> s;
      return is;
  }
  
public:
  Cube(string name, double side_s) : Figure3d(name, FIGURE_TYPE_CUBE)
  {
    s = side_s;
  }
  ~Cube() { std::cout << " Cube destructor  " << std::endl; }

  // Реализация методов

  double calc_area()
  {
    return 6 * s * s;
  }

  double calc_perimeter()
  {
    return 12 * s;
  }
  double calc_volume()
  {
    cout << "Cube volume = " << s * s * s << endl;
    return s * s * s;
  }
};

class Sphere : public Figure3d
{
private:
  double r;
  
  // вывод инфы о фигуре
  std::ostream& write(std::ostream& os) const
  {
      os << name << " r: " << r <<endl;
      return os;
  }
  
  
  // ввод инфы о фигуре
  std::istream& read(std::istream& is)
  {
      is >> name >> r;
      return is;
  }
  
public:
  Sphere(string name, double side_r) : Figure3d(name, FIGURE_TYPE_SPHERE)
  {
    r = side_r;
  }
  ~Sphere() { std::cout << " Sphere destructor  " << std::endl; }

  // Реализация методов
  double calc_area()
  {
    return 4 * 3.14 * r * r;
  }

  double calc_perimeter()
  {
    return -1;
  }

  double calc_volume()
  {
    cout << "Cube volume = " << (4 / 3) * (3.14 * (r * r * r)) << endl;
    return (4 / 3) * (3.14 * (r * r * r));
  }
};
