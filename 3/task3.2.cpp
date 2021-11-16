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
    Node *next;
};
class List
{
private:
    Node *current;     //Указатель на текущую позицию списка
    // Node *ptr_begin;   //Указатель на первый элемент списка
    Node *ptr_end;     //Указатель на крайний элемент списка
    int count_element; //Счетчик элементов

public:
    List() // Конструктор списка
    {
        current = nullptr;
        count_element = 0;
        // ptr_begin = current;
        ptr_end = current;
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
    Node *temp = current;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    if (temp == nullptr && count_element == 0)
    {
        std::cout << "list is empty" << std::endl;
    }
}

int List::count() //Получение количества элементов списка
{
    std::cout << count_element << std::endl;
    return count_element;
}

void List::append(int val) //Добавление элементов в конец списка
{
    Node *new_Node = new Node;
    new_Node->data = val;
    new_Node->next = current;
    current = new_Node;
    ptr_end = new_Node; // Сохраняем адрес последнего элемента
    // ptr_begin = current;

    count_element++;
}

void List::appbegin(int val) //Добавление элементов в начало списка
{
    Node *new_Node = new Node;
    new_Node->data = val;
    new_Node->next = ptr_end;
    current = new_Node;
    count_element++;
    ptr_end = new_Node;
}

void List::clear() //Удаление всех элементов
{
    Node *temp = ptr_end;
    while (temp)
    {
        ptr_end = temp->next;
        delete temp;
        temp = ptr_end;
        count_element--;
    }
    current = nullptr;
    ptr_end = current;
    ptr_end = current;
    std::cout << "clear" << std::endl;
    std::cout << "count_element " << count_element << std::endl;
}
void insert(int, int); //Вставление элемента на указанную позицию
void pop_begin();      //Удаление первого элемента списка
void pop_end();        //Удаление последнего элемента списка
void pop(int);         //Удаление элемента на указанной позиции
void clear_reange();   //Удаление элементов в диапозоне между двумя указанными позициями

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
}