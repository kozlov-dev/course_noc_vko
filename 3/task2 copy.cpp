#include <iostream>
#include <string>
using namespace std;

class Fr
{
private:
    double num;
    double dim;

public:
    Fr(double _num = 0, double _dim = 1)
    {
        set_num(_num);
        set_dim(_dim);
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

    string show()

    {
        double res = 0;
        res = num / dim;
        std::cout << "num = " << num << std::endl;
        std::cout << "dim = " << dim << std::endl;
        return to_string(num) + "/" + to_string(dim) + " = " + to_string(res);
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
};
int main()
{
    Fr n1(5, 10);
    Fr n2(1, 2);

    Fr res = n1.add(n2);
    res.show();;

    res = n1.sub(n2);
    res.show();;

    res = n1.mul(n2);
    res.show();;

    res = n1.div(n2);
    res.show();;

    n1.set_dim(0);

    std::cout << "/* finish!!! */" << std::endl;

    return 0;
}