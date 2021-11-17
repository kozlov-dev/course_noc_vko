/*2) Реализовать односвязный список, обладающим следующим функционалом
-Добавление элементов в конец списка
-Добавление элементов в начало списка
-Вывод элементов списка
-Получение количества элементов списка
-Вставление элемента на указанную позицию
-Удаление всех элементов
-Удаление первого элемента списка
-Удаление последнего элемента списка
-Удаление элемента на указанной позиции
-Удаление элементов в диапозоне между двумя указанными позициями
*/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class List
{
private:
    //Node* current;     //Указатель на текущую позицию списка
    Node* ptr_begin;   //Указатель на первый элемент списка
    Node* ptr_end;     //Указатель на крайний элемент списка
    int count_element; //Счетчик элементов

public:
    List() // Конструктор списка
    {
        //current = nullptr;
        ptr_begin = nullptr;
        ptr_end = nullptr;
        count_element = 0;
    }
    // ~List()
    // {
    // }
    void show();           //Вывод элементов списка
    int count();           //Получение количества элементов списка
    void append(int);      //Добавление элементов в конец списка
    void appbegin(int);    //Добавление элементов в начало списка
    void clear();          //Удаление всех элементов
    void insert(int, int); //Вставление элемента на указанную позицию
    void popbegin();       //Удаление первого элемента списка
    void popend();         //Удаление последнего элемента списка
    void pop(int);         //Удаление элемента на указанной позиции
    void clearreange();    //Удаление элементов в диапозоне между двумя указанными позициями
};
void List::show() //Вывод элементов списка
{
    std::cout << "/* show */" << std::endl;
    Node* ptr = ptr_begin;
    if (ptr == nullptr)
    {
        std::cout << "list is empty" << std::endl;
    }
    else
    {
        while (ptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

}
int List::count() //Получение количества элементов списка
{
    std::cout << count_element << std::endl;
    return count_element;
}
void List::append(int val) //Добавление элементов в конец списка
{
    Node* new_Node = new Node;

    new_Node->data = val;

    if (ptr_begin == nullptr) {
        ptr_begin = new_Node;
        ptr_end = new_Node;
        return;
    }
    ptr_end->next = new_Node;
    ptr_end = new_Node;

    //if (new_Node->next == nullptr)
    //{
    //    ptr_begin = new_Node;
    //}
    //current = new_Node;
    //ptr_end = new_Node; // Сохраняем адрес последнего элемента
    //// ptr_begin = current;

    count_element++;
}
void List::appbegin(int val) //Добавление элементов в начало списка--
{
    Node* new_Node = new Node;

    
    new_Node->data = val;
    new_Node->next = ptr_begin; // новая нода ссылается на старое начало

    //current->next = ptr_begin->next;
    //current = new_Node->;// текущий указатель становиться новым указателем

    ptr_begin = new_Node;
    
    count_element++;
}
void List::clear() //Удаление всех элементов
{
    Node* temp = ptr_end;
    while (temp)
    {
        ptr_end = temp->next;
        delete temp;
        temp = ptr_end;
        count_element--;
    }
    //current = nullptr;
    //ptr_end = current;
    //ptr_end = current;
    std::cout << "clear" << std::endl;
    std::cout << "count_element " << count_element << std::endl;
}
void List::insert(int position, int val) //Вставление элемента на указанную позицию
{
    std::cout << "/* insert_pos = */" << position << std::endl;
    // struct Data
    // {
    //     int a;
    // };
    // struct List
    // {
    //     Data d;
    //     List *next;
    // };
    // if (*u == 0) // исходный список пуст - вставка в начало
    // {
    //     p->next = 0;
    //     *u = p;
    // return;

    if (position <= count_element && !(position < 0))
    {

    //    Node* new_Node = new Node;

    //    //Node* ptr_current = current;
    //    Node* ptr_post = current;

    //    int index = 0;
    //    while (ptr_current)
    //    {
    //        ptr_current = ptr_current->next;

    //        if (index == position)
    //        {
    //            ptr_current = ptr_post; //смотрим на прошлую ноду

    //            new_Node->next = ptr_current->next; // новая нода ссылется на последующую ноду
    //            new_Node->data = val;

    //            ptr_current->next = new_Node; //старая нода ссылается на новую ноду
    //        }
    //        ptr_post = current;
    //        index++;
    //    }
    //}
    //else
    //{
    //    std::cout << "/* выход за диапозон*/" << std::endl;
    }

    void pop_begin();    //Удаление первого элемента списка
    void pop_end();      //Удаление последнего элемента списка
    void pop(int);       //Удаление элемента на указанной позиции
    void clear_reange(); //Удаление элементов в диапозоне между двумя указанными позициями
}
int main()
{
    List list;

    /*******************************************************************************************/
    std::cout << "*****append*****" << std::endl;

    list.append(1);
    list.append(11);
    list.append(111);
    list.append(1111);

    list.show();
    list.count();
    /*******************************************************************************************/
    std::cout << "*****appbegin*****" << std::endl;
    list.appbegin(2222);
    list.appbegin(222);
    list.appbegin(22);
    list.appbegin(2);

    list.show();
    list.count();

    /*******************************************************************************************/
    std::cout << "*****clear*****" << std::endl;

    list.clear();
    list.show();
    list.count();
    /*******************************************************************************************/
    list.appbegin(2222);
    list.appbegin(2222);

    std::cout << "*****insert*****" << std::endl;

    list.insert(2, 555);
    list.show();
}