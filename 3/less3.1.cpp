/*
1) Модифициоровать класс для работы с дробными числами.
Он должен содержать:
-Числитель
-Знаменатель
-Конструктор, Деструктор
-Перегруженнные операторы для сложения, вычитания, умножения, деления, сравнения дробных чисел,
операторов +=, -=, *=, /=
*/

#include <iostream>
#include <string>
using namespace std;

class Fr
{
private:
    double num;
    double dim;

    double res;
    double _res(double num, double dim)
    {
        if (dim > 0)
        {
            res = num / dim;
        }
        else
        {
            std::cout << "/* Div 0! */" << std::endl;
            dim = 1;
        }
        return res;
    }

public:
    Fr(double _num = 0, double _dim = 1)
    {
        set_num(_num);
        set_dim(_dim);
    }
    ~Fr()
    {
        // delete ;
    }

    double get_num()
    {
        return num;
    }
    void set_num(double _num)
    {
        num = _num;
    }
    double get_dim()
    {
        return dim;
    }
    void set_dim(double _dim)
    {
        if (_dim > 0)
        {
            dim = _dim;
        }
        else
        {
            std::cout << "/* Div 0! */" << std::endl;
            dim = 1;
        }
    }

    void show()

    {
        std::cout << "num = " << num << std::endl;
        std::cout << "dim = " << dim << std::endl;
        std::cout << "res = " << (_res(num, dim)) << std::endl;
    }
    Fr operator+(Fr c)
    // (n1*d2)+(n2*d1)
    // d1*d2
    {
        return Fr((num * c.dim) + (c.num * dim), (dim * c.dim));
    }
    Fr operator-(Fr c)
    // (n1*d2)-(n2*d1)
    // d1*d2
    {
        return Fr((num * c.dim) - (c.num * dim), (dim * c.dim));
    }
    Fr operator*(Fr c)
    // n1*n2
    // d1*d2
    {
        return Fr((num * c.num), (dim * c.dim));
    }
    Fr operator/(Fr c)
    // n1*d2
    // d1*n2
    {
        Fr res(0, 1);
        res.num = num * c.dim;
        res.dim = dim * c.num;
        if (res.dim == 0)
        {
            cout << "Div 0!" << endl;
            exit(1);
        };
        return res;
    }

    bool operator==(Fr c)
    {
        if (num == c.num && dim == c.dim)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Fr c)
    {
        if (num > c.num && dim > c.dim)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>=(Fr c)
    {
        if (num >= c.num && dim >= c.dim)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(Fr c)
    {
        if (num < c.num && dim < c.dim)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(Fr c)
    {
        if (num <= c.num && dim <= c.dim)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Fr operator+=(Fr c)
    {
        Fr res(0, 1);
        res.num = ((num * c.dim) + (c.num * dim));
        res.dim = (dim * c.dim);
        return res;
    }
    Fr operator-=(Fr c)
    {
        Fr res(0, 1);
        res.num = ((num * c.dim) - (c.num * dim));
        res.dim = (dim * c.dim);
        return res;
    }
    Fr operator*=(Fr c)
    {
        Fr res(0, 1);
        res.num = (num * c.num);
        res.dim = (dim * c.dim);
        return res;
    }

    Fr operator/=(Fr c)
    {
        // n1*d2
        // d1*n2

        Fr res(0, 1);
        res.num = (num * c.dim);
        res.dim = (dim * c.num);
        if (res.dim == 0)
        {
            cout << "Div 0!" << endl;
            exit(1);
        };
        return res;
    }
};

class SafeArray
{
private:
    const static int size = 10;
    int arr[size];

public:
    void set(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error.index is out of a range" << std::endl;
        }
        arr[index] = value;
    }
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error.index is out of a range" << std::endl;
            exit(1);
        }
        return arr[index];
    }
    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error.index is out of a range" << std::endl;
            exit(1);
        }
        return arr[index];
    }
};

class ExampleEquality
{
public:
    char *data;
    int langth;

    ExampleEquality() {}

    ExampleEquality(const char *_data, int _langth)
    {
        data = new char[_langth];
        for (int i = 0; i < _langth; i++)
        {
            data[i] = _data[i];
        }
        langth = _langth;
    }
    ~ExampleEquality()
    {
        delete[] data;
    }
    ExampleEquality &operator=(ExampleEquality &c)
    {
        langth = c.langth;
        data = new char[c.langth];
        for (int i = 0; i < c.langth; i++)
        {
            data[i] = c.data[i];
        }
        langth = c.langth;
        return *this;
    };

    void show()
    {
        std::cout << data << std::endl;
    }
};
int main()
{

    ExampleEquality ex("jack black", 11);
    ExampleEquality ex_copy;
    ex_copy = ex;

    ex.data[1] = 'o';

    ex.show();
    ex_copy.show();
    /*********************************************************************************/
    SafeArray s;
    s.set(3, 5);
    std::cout << s.get(3) << std::endl;
    std::cout << s[3] << std::endl;
    /*********************************************************************************/
    // Fr n1(5, 16);
    // Fr n2(1, 22);
    // Fr res = n1 + n2;
    // res.show();

    // res = n1 - n2;
    // res.show();

    // res = n1 * n2;
    // res.show();

    // res = n1 / n2;
    // res.show();

    // n1.set_dim(0);

    // res += n1;
    // res.show();

    // res -= n1;
    // res.show();

    // res *= n1;
    // res.show();

    // res /= n1;
    // res.show();

    std::cout << "/* finish!!! */" << std::endl;

    return 0;
}