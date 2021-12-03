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
	Node* ptr_begin;  //Указатель на первый элемент списка "голова"
	Node* ptr_end;	  //Указатель на крайний элемент списка "хвост"
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
	void pop_front();		   //+Удаление первого элемента списка
	void pop_end();			   //+Удаление последнего элемента списка
	void insert(int, int);	   //Вставление элемента на указанную позицию
	void pop(int);			   //Удаление элемента на указанной позиции
};
void List::show() //+Вывод элементов списка
{
	std::cout << "/* show */" << std::endl;
	int idx = 0;
	Node* ptr = ptr_begin;
	if (ptr == nullptr)
	{
		std::cout << "list is empty" << std::endl;
	}
	else
	{
		while (ptr)
		{
			cout << "list[" << idx << "]" << " -> " << ptr->data << endl;
			ptr = ptr->next;
			idx++;
		}
	}
	std::cout << "/* show */" << std::endl;
}
int List::size() //+Получение количества элементов списка
{
	std::cout << "size = " << size_element << std::endl;
	return size_element;
}
void List::push_back(int val) //Добавление элементов в конец списка
{
	std::cout << "push_back " << val << std::endl;

	Node* new_Node = new Node;

	new_Node->data = val;
	new_Node->next = nullptr;

	if (ptr_begin == nullptr) //если создаем первый узел
	{
		ptr_begin = new_Node;
	}
	else //если не первый узел
	{
		Node* ptr = ptr_begin;

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

	Node* new_Node = new Node;

	new_Node->data = val;
	new_Node->next = ptr_begin; // новая нода ссылается на старое начало
	ptr_begin = new_Node;		// Делаем новую ноду новым началом
	size_element++;
}
void List::clear() //Удаление всех элементов
{
	cout << "/* clear */" << endl;
	Node* ptr = ptr_begin;
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
void List::pop_front() //+Удаление первого элемента списка
{
	std::cout << "pop_front" << std::endl;
	Node* ptr = ptr_begin;
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
	int t = 0;
	std::cout << "pop_end" << std::endl;
	Node* ptr = ptr_begin;
	Node* ptr_previous = ptr_begin;
	if (ptr != nullptr)
	{
		if ((ptr->next) == nullptr) // если один элемент
		{
			t = ptr->data;
			ptr_begin = nullptr;
			delete ptr;
			if (size_element >= 0)
			{
				size_element--;
			};
			cout << "pop_end:" << t;
			return;
		}
		while (ptr->next != nullptr) //ищем в цикле предшествующий последнему узел
		{
			ptr_previous = ptr; // запоминаем предпоследний элемент
			cout << "ptr_previous " << ptr->data << endl;
			ptr = ptr->next; // смещаемся в конец
		}
		//нашли предпоследний элемент
		t = ptr->data;
		cout << "pop_end:" << t;
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
void List::insert(int position, int val) //Вставление элемента на указанную позицию
{
	std::cout << "insert_pos = " << position << "->val " << val << std::endl;
	Node* ptr = ptr_begin;
	Node* ptr_previous = ptr_begin;

	if (ptr == nullptr) // исходный список пуст - вставка в начало
	{
		this->push_back(val);
	}
	else
	{
		Node* new_Node = new Node;
		new_Node->data = val;

		int index = 0;
		if (index == position) { // если добавит нужно в 0 позицию
			this->push_front(val);
			return;
		}
		while (index != position) //ищем в цикле предшествующий position узел
		{
			ptr_previous = ptr; // записали предшедствующий элемент в указатель предшествия
			ptr = ptr->next;
			index++;
		}
		//if (index == 1) // если list.size() = 1
		////if (ptr->next == nullptr) // если list.size() = 1
		//{
		//	ptr->next = new_Node; // привязали предшедствующий элемент к новой ноде
		//	new_Node->next = nullptr;
		//	size_element++;
		//	return;
		//}
		/**************--(→_→)--******************/
		//нашли предшествующий элемент
		//ptr_previous = ptr; // записали предшедствующий элемент в указатель предшествия
		//index++;
		//ptr = ptr->next;
		if (ptr->next == nullptr) // конец списка
		{
			this->push_back(val);
		}

		if (index == position)
		{

			new_Node->next = ptr;
			ptr_previous->next = new_Node; // привязали предшедствующий элемент к новой ноде
			//ptr_previous->next = new_Node; // привязали предшедствующий элемент к новой ноде
			size_element++;
		}
	}
}
/*
insert_pos = 1->val 1	insert_pos = 2->val 666		insert_pos = 0->val 0
0 -> 5					0 -> 5						0 -> 5
1 -> 1					1 -> 1						1 -> 1
2 -> 55					2 -> 666					2 -> 666
3 -> 555				3 -> 55						3 -> 55
4 -> 55555				4 -> 555					4 -> 555
5 -> 5555				5 -> 55555					5 -> 55555
6 -> 6					6 -> 5555					6 -> 5555
7 -> 4444				7 -> 6						7 -> 6
8 -> 444				8 -> 4444					8 -> 4444
9 -> 44					9 -> 444					9 -> 444
10 -> 4					10 -> 44					10 -> 44
show 					11 -> 4						11 -> 4
size = 11				size = 12					12 -> 0
													size = 13
*/


Node* get_ptr_prev(Node* ptr, int position)
{
	int counter = 0;

	while (counter < position && ptr->next != nullptr) //ищем в цикле предшествующий последнему узел
	{
		ptr = ptr->next;
		counter++;
	}
	return ptr;

}
//Node* getN_prev(Node* head, int n) {
//	int counter = 0;
//	while (counter < n && head) {
//		head = head->next;
//		counter++;
//	}
//	return head;
//}
void List::pop(int position) //Удаление элемента на указанной позиции
{
	std::cout << "pop_pos = " << position << std::endl;
	Node* ptr = ptr_begin;
	Node* ptr_previous = ptr_begin;

	int counter = 0;

	if (ptr == nullptr) // пустой список
	{
		std::cout << "list is empty" << std::endl;
		return;
	}
	if (position > size_element)
	{ // если запрашивается позиция вне диапозона списка
		std::cout << "out of range" << std::endl;
		return;
	}
	if (position == 0)
	{ // запрос первого элемента списока list.size > 1
		return this->pop_front();
	}
	else
	{
		while (ptr != nullptr && counter != position)
		{
			ptr = ptr->next;
			counter++;
		}
		std::cout << "counter = " << counter << std::endl;

		// list.size > 1
		//ptr_previous = get_ptr_prev(ptr_begin, position); // 1,2
		//Node* elm = ptr_previous->next;// нужный элемент
		//ptr_previous->next = elm->next; // ссылаемся на 
		//delete elm;
	}


};

int main()
{
	List list;

	///*******************************************************************************************/
	//std::cout << "*****push_back*****" << std::endl;

	//list.push_back(1);
	//list.push_back(11);
	//list.push_back(111);
	//list.push_back(1111);

	//list.show();
	//list.size();
	///*******************************************************************************************/
	//std::cout << "*****push_front*****" << std::endl;
	//list.push_front(2222);
	//list.push_front(222);
	//list.push_front(22);
	//list.push_front(2);

	//list.show();
	//list.size();

	///*******************************************************************************************/
	//std::cout << "*****clear*****" << std::endl;

	//list.clear();
	//list.show();
	//list.size();
	///*******************************************************************************************/
	//std::cout << "*****pop_front*****" << std::endl;
	//list.clear();
	//list.pop_front();
	//list.show();
	//list.size();

	//list.push_back(4444);
	//list.pop_front();
	//list.show();
	//list.size();

	//list.push_back(4444);
	//list.push_back(444);
	//list.pop_front();
	//list.show();
	//list.size();
	///*******************************************************************************************/
	//std::cout << "*****pop_end*****" << std::endl;
	//list.clear();
	//list.pop_end();
	//list.show();
	//list.size();

	//list.push_back(5555);
	//list.pop_end();
	//list.show();
	//list.size();

	//list.push_back(5555);
	//list.push_back(555);
	//list.push_back(55);
	//list.push_back(5);
	//list.push_back(5555);
	//list.push_back(555);
	//list.push_back(55);
	//list.push_back(5);
	//list.pop_end();
	//list.show();
	//list.size();

	///*******************************************************************************************/
	std::cout << "*****insert*****" << std::endl;
	list.clear();
	list.insert(3, 5);
	list.show();
	list.size();

	list.insert(0, 55);
	list.show();
	list.size();

	list.push_back(4444);
	list.push_back(444);
	list.push_back(44);
	list.push_back(4);
	list.size();
	list.insert(3, 5555);
	list.show();
	list.size();

	list.insert(3, 55555);
	list.show();
	list.size();

	list.insert(5, 6);
	list.show();
	list.size();

	list.insert(1, 1);
	list.show();
	list.size();

	list.insert(2, 666);
	list.show();
	list.size();

	list.insert(0, 0);
	list.show();
	list.size();
	///*******************************************************************************************/
	//std::cout << "*****pop_position*****" << std::endl;
	//list.clear();
	//list.pop(3);
	//list.show();
	//list.size();

	//list.push_back(1);
	//list.pop(2);
	//list.show();
	//list.size();

	//list.pop(0);
	//list.show();
	//list.size();

	//list.push_back(11);
	//list.pop(1);
	//list.show();
	//list.size();

	//list.push_back(1);
	//list.push_back(11);
	//list.pop(2);
	//list.show();
	//list.size();



}