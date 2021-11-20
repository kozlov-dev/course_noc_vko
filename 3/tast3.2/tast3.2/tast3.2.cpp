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
	Node *ptr_begin;  //Указатель на первый элемент списка "голова"
	Node *ptr_end;	  //Указатель на крайний элемент списка "хвост"
	int size_element; //Счетчик элементов

public:
	List() // Конструктор списка
	{
		ptr_begin = nullptr;
		ptr_end = nullptr;
		size_element = 0;
	}
	~List()
	{
		cout << "destructor" << endl;
		clear();
	}
	void show();			   //+Вывод элементов списка
	int size();				   //+Получение количества элементов списка
	void push_back(int);	   //+Добавление элементов в конец списка
	void push_front(int);	   //+Добавление элементов в начало списка
	void clear();			   //+Удаление всех элементов
	void insert(int, int);	   //Вставление элемента на указанную позицию
	void pop_front();		   //Удаление первого элемента списка
	void pop_end();			   //Удаление последнего элемента списка
	void pop(int);			   //Удаление элемента на указанной позиции
	void pop_reange(int, int); //Удаление элементов в диапозоне между двумя указанными позициями
};
void List::show() //+Вывод элементов списка
{
	std::cout << "/* show */" << std::endl;
	Node *ptr = ptr_begin;
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
int List::size() //+Получение количества элементов списка
{
	std::cout << size_element << std::endl;
	return size_element;
}
void List::push_back(int val) //Добавление элементов в конец списка
{
	std::cout << "push_back " << val << std::endl;

	Node *new_Node = new Node;

	new_Node->data = val;
	new_Node->next = nullptr;

	if (ptr_begin == nullptr) //если создаем первый узел
	{
		ptr_begin = new_Node;
	}
	else //если не первый узел
	{
		Node *ptr = ptr_begin;

		while (ptr->next != nullptr) //ищем в цикле предшествующий последнему узел
		{
			ptr = ptr->next;
		}

		ptr->next = new_Node;
	}
	size_element++;
}
void List::push_front(int val) //Добавление элементов в начало списка--
{
	std::cout << "push_front " << val << std::endl;

	Node *new_Node = new Node;

	new_Node->data = val;
	new_Node->next = ptr_begin; // новая нода ссылается на старое начало
	ptr_begin = new_Node;		// Делаем новую ноду новым началом
	size_element++;
}
void List::clear() //Удаление всех элементов
{
	cout << "/* clear */" << endl;
	Node *ptr = ptr_begin;
	while (ptr)
	{
		ptr_begin = ptr->next;
		delete ptr;
		ptr = ptr_begin;
		if (size_element >= 0)
		{
			size_element--;
		};
	}

	std::cout << "size_element " << size_element << std::endl;
}
void List::insert(int position, int val) //Вставление элемента на указанную позицию
{
	std::cout << "insert_pos =" << position << std::endl;
	Node *ptr_current = ptr_begin;
	Node *ptr_previous = ptr_begin;

	if (ptr_current == nullptr) // исходный список пуст - \вставка в начало
	{
		this->push_back(val);
	}
	else
	{
		Node *new_Node = new Node;

		int index = 0;
		while (index != position - 1) // Выполнится до момента пока ind == pos
		{
			ptr_current = ptr_current->next;
			index++;
		}
		new_Node->data = val;
		new_Node->next = ptr_current->next;
		ptr_current->next = new_Node;

		/*cout << ptr_current->data << endl;*/

		//if (index == position)
		//{
		//	ptr_current = ptr_post; //смотрим на прошлую ноду

		//	new_Node->next = ptr_current->next; // новая нода ссылется на последующую ноду
		//	new_Node->data = val;

		//	ptr_current->next = new_Node; //старая нода ссылается на новую ноду
		//}
		//ptr_post = current;
	}
}
void List::pop_front() //+Удаление первого элемента списка
{
	std::cout << "pop_front" << std::endl;
	Node *ptr = ptr_begin;
	if (ptr != nullptr)
	{

		ptr_begin = ptr->next;
		delete ptr;
		ptr = ptr_begin;
		if (size_element >= 0)
		{
			size_element--;
		};
	}
	else
	{
		std::cout << "list is empty" << std::endl;
	}
};
void List::pop_end() //+Удаление последнего элемента списка
{
	std::cout << "pop_end" << std::endl;
	Node *ptr = ptr_begin;
	Node *ptr_previous = ptr_begin;
	if (ptr != nullptr)
	{
		if ((ptr->next) == nullptr) // если один элемент
		{
			ptr_begin = nullptr;
			delete ptr;
			if (size_element >= 0)
			{
				size_element--;
			};

			return;
		}
		while (ptr->next != nullptr) //ищем в цикле предшествующий последнему узел
		{
			ptr_previous = ptr; // запоминаем предпоследний элемент
			cout << "ptr_previous " << ptr->data << endl;
			ptr = ptr->next; // смещаемся в конец
		}
		//нашли предпоследний элемент
		ptr_previous->next = nullptr; // обрываем связь
		delete ptr;
		if (size_element >= 0)
		{
			size_element--;
		};
	}
	else
	{
		std::cout << "list is empty" << std::endl;
	}
};
void List::pop(int) //Удаление элемента на указанной позиции
	{

	};
void List::pop_reange(int begin, int stop) //Удаление элементов в диапозоне между двумя указанными позициями
	{

	};

int main()
{
	List list;

	/*******************************************************************************************/
	std::cout << "*****push_back*****" << std::endl;

	list.push_back(1);
	list.push_back(11);
	list.push_back(111);
	list.push_back(1111);

	list.show();
	list.size();
	/*******************************************************************************************/
	std::cout << "*****push_front*****" << std::endl;
	list.push_front(2222);
	list.push_front(222);
	list.push_front(22);
	list.push_front(2);

	list.show();
	list.size();

	/*******************************************************************************************/
	std::cout << "*****clear*****" << std::endl;

	list.clear();
	list.show();
	list.size();

	/*******************************************************************************************/

	// std::cout << "*****insert*****" << std::endl;
	// list.push_front(3);
	// list.push_front(33);
	// list.push_front(333);
	// list.insert(3, 3333);
	// list.show();

	/*******************************************************************************************/
	std::cout << "*****pop_front*****" << std::endl;
	list.clear();
	list.pop_front();
	list.show();
	list.size();

	list.push_back(4444);
	list.pop_front();
	list.show();
	list.size();

	list.push_back(4444);
	list.push_back(444);
	list.pop_front();
	list.show();
	list.size();
	/*******************************************************************************************/
	std::cout << "*****pop_end*****" << std::endl;
	list.clear();
	list.pop_end();
	list.show();
	list.size();

	list.push_back(5555);
	list.pop_end();
	list.show();
	list.size();

	list.push_back(5555);
	list.push_back(555);
	list.push_back(55);
	list.push_back(5);
	list.push_back(5555);
	list.push_back(555);
	list.push_back(55);
	list.push_back(5);
	list.pop_end();
	list.show();
	list.size();
}