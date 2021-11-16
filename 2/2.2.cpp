#include <iostream>
using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    Human(string _name, int _age)
    {
        set_name(_name);
        set_age(_age);
    }

    void show()
    {
        std::cout << "name = " << name << std::endl;
        std::cout << "age = " << age << std::endl;
    }

    string get_name()
    {
        return name;
    }

    void set_name(string _name)
    {
        name = _name;
    }
    int get_age()
    {
        return age;
    }
    void set_age(int _age)
    {
        if (_age >= 0)
        {
            age = _age;
        }
        else
        {
            age = 0;
        }
    }
};

int main()
{
    Human jack("Jack", 20);
    jack.show();
    std::cout << jack.get_age() << std::endl;
    // jack.set_name("BBBBBBB");
    std::cout << jack.get_name() << std::endl;
    std::cout << jack.show();;

    std::cout << "/* message */" << std::endl;

    return 0;
}