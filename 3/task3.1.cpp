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
        set_num(0);
        set_dim(1);
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
    double get_res()
    {
        return res;
    }
    void show()

    {
        std::cout << "num = " << num << std::endl;
        std::cout << "dim = " << dim << std::endl;
        std::cout << "res = " << get_res() << std::endl;
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

    Fr &operator+=(Fr c)
    {
        // Fr res(0, 1);
        // res.num = ((num * c.dim) + (c.num * dim));
        // res.dim = (dim * c.dim);
        num = ((num * c.dim) + (c.num * dim));
        dim = (dim * c.dim);
        // return res;
        return *this;
    }
    Fr &operator-=(Fr c)
    {
        // Fr res(0, 1);
        num = ((num * c.dim) - (c.num * dim));
        dim = (dim * c.dim);
        // return res;
        return *this;
    }
    Fr &operator*=(Fr c)
    {
        // Fr res(0, 1);
        num = (num * c.num);
        dim = (dim * c.dim);
        // return res;
        return *this;
    }

    Fr &operator/=(Fr c)
    {
        // n1*d2
        // d1*n2

        // Fr res(0, 1);
        num = (num * c.dim);
        dim = (dim * c.num);
        if (dim == 0)
        {
            cout << "Div 0!" << endl;
            exit(1);
        };
        // return res;
        return *this;
    }
};
int main()
{

    /*********************************************************************************/
    Fr n1(5, 116);
    Fr n2(1, 22);
    Fr res = n1 + n2;
    res.show();

    res = n1 - n2;
    res.show();

    res = n1 * n2;
    res.show();

    res = n1 / n2;
    res.show();

    n1.set_dim(0);

    res += n1;
    res.show();

    res -= n1;
    res.show();

    res *= n1;
    res.show();

    res /= n1;
    res.show();

    std::cout << "/* finish!!! */" << std::endl;

    return 0;
}