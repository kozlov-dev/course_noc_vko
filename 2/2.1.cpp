#include <iostream>
using namespace std;

class Re
{
public:
    string name;
    int num;

    // Re(/* args */)
    // {
    //     cout << "/* Re */" << std::endl;
    //     // name = "abc";
    //     // num = 10;
    // };
    Re(string _name = "def", int _num= -1)
    {
        name = _name;
        num = _num;
    }
    void Show(){
        std::cout << "name = " << name<< std::endl;
        std::cout << "num = " << num<< std::endl;
    }
};

int main()
{
    Re r1;
    Re r2("bbb", 4);
    Re r3("d",5);

    r1.Show();
    r2.Show();
    r3.Show();

    std::cout << "/* message */" << std::endl;

    return 0;
}