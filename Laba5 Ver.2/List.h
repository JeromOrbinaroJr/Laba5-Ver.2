#pragma once
#include <stdexcept>
#include <algorithm>

template <typename T>
class List {
public:
	//Constructors
	List();
	List(const List<T>& other);

    //Destructor
	~List();

	//Operators Overloading
	List<T>& operator=(const List<T>& other);

    //Methods
	void insert(const T& element, int position); // ���������� �������� � ������
    void insert(const T& element);
	void remove(int position); // �������� �������� �� ������
    void removeAll(); // �������� ���� ��������� �� ������ 
    bool contains(const T& element) const; // �������� �� ���������� �������� � ������
	T& at(int position);  // ��������� ������ �� ������� �� ������� 
	//void sort(); // ���������� ��������� ������
	int getSize() const; // ��������� ������� ������

private:
	struct Node
	{
		T data;
		Node* next;
		Node(const T& newData) : data(newData), next(nullptr) { }
	};
	Node* head;
	int size;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructors
template<typename T>
List<T>::List() : head(nullptr), size(0) {}

template<typename T>
List<T>::List(const List<T>& other) {
    head = nullptr;
    size = 0;
    Node* current = other.head;
    while (current) {
        insert(current->data, size);
        current = current->next;
    }
}

//Destructor
template<typename T>
List<T>::~List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//Operators Overloading
template<typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    // ���������, ��� ��� �� ������������ ������ ����
    if (this != &other) {
        // ������� ������� ������, ����� �������� ������ ������
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // �������� �������� �� ������� ������
        head = nullptr; // ������������� ������ ������ ������ � nullptr
        size = 0; // ���������� ������

        // �������� �������� �� ������ `other`
        Node* current = other.head; // ��������� ��� �������� ��������� ������� ������
        while (current) {
            insert(current->data, size); // ��������� ���������� ������� � ����� �������� ������
            current = current->next; // ������������ � ���������� �������� � ������ ������
        }
    }
    return *this; // ���������� ������ �� ������� ������
}


//Methods
template<typename T>
void List<T>::insert(const T& element, int position) {
    // ���������, ��� ������� � �������� ������
    if (position < 0 || position > size) {
        throw std::runtime_error("Invalid position");
    }

    // ������� ����� ���� � �������� ���������
    Node* newNode = new Node(element);

    // ���� ������� 0, ��������� ������� � ������ ������
    if (position == 0) {
        newNode->next = head; // ����� ���� ��������� �� ������� ������ ������
        head = newNode; // ����� ���� ���������� ����� ������� ������
    }
    else {
        Node* current = head; // ��������� ��� ����������� �� ������, �������� � ������
        // ������������ � ��������, ��������������� ������� �������
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        // ��������� ����� ���� ����� ������� ��������� � ��������� ���������
        newNode->next = current->next;
        current->next = newNode;
    }
    ++size; // ����������� ������ ������ �� 1
}


template<typename T>
void List<T>::insert(const T& element) {
    Node* newNode = new Node(element); // ������� ����� ���� � �������� ���������
    if (head == nullptr) { // ���� ������ ���� (������ ����� nullptr)
        head = newNode; // ������������� ����� ���� ��� ������ ������
    }
    else { // ���� ������ �� ����
        Node* current = head; // ��������� ��� ����������� �� ������, �������� � ������
        while (current->next != nullptr) { // ���� �� ������ �� ���������� ��������
            current = current->next; // ������������ � ���������� ��������
        }
        current->next = newNode; // ������������� ����� ����� ������� ��������� ��������� � ����� ���������
    }
    ++size; // ����������� ������ ������ �� 1
}


template<typename T>
void List<T>::remove(int position) {
    if (position < 0 || position >= size) { // ���������, ��� ������� ��������� � �������� ������
        throw std::runtime_error("Invalid position"); // ���� ������� �����������, ����������� ����������
    }
    Node* temp; // ��������� ��������� ��� �������� ���������� ����
    if (position == 0) { // ���� ��������� ������� - ������ � ������
        temp = head; // ������������� ��������� ��������� �� ������ ������
        head = head->next; // ���������� ������ �� ��������� �������
    }
    else { // ���� ��������� ������� �� ������ � ������
        Node* current = head; // ��������� ��� ����������� �� ������
        for (int i = 0; i < position - 1; ++i) { // ������� �� �������� ����� ���������
            current = current->next; // ������������ � ���������� ��������
        }
        temp = current->next; // ���������� ��������� �������
        current->next = temp->next; // ������������� ����� ����� ������� ��������� � ��������� �� ���������
    }
    delete temp; // ������� ����
    --size; // ��������� ������ ������
}


template<typename T>
void List<T>::removeAll() {
    while (head != nullptr) { // ���� ������ �� ������
        Node* temp = head; // ������� ��������� ��������� �� ������ ������
        head = head->next; // ���������� ������ ������ �� ��������� �������
        delete temp; // ������� ������� �������
    }
    size = 0; // ������������� ������ ������ � ����
}


template<typename T>
T& List<T>::at(int position) {
    if (position < 0 || position >= size) { throw std::runtime_error("Invalid position"); }
    Node* current = head; // ������� ��������� current � ������������� ��� �� ������ ������
    for (int i = 0; i < position; ++i) { // �������� �� ������ �� ��������� �������
        current = current->next; // ��������� � ���������� ���� ������
    }
    return current->data; // ���������� ������ �������� ����
}


//template<typename T>
//void List<T>::sort() {
//    if (size <= 1) return;
//    bool swapped;
//    Node* ptr1;
//    Node* lptr = nullptr;
//    do {
//        swapped = false;
//        ptr1 = head;
//        while (ptr1->next != lptr) {
//            if (ptr1->data > ptr1->next->data) {
//                T temp = ptr1->data;
//                ptr1->data = ptr1->next->data;
//                ptr1->next->data = temp;
//                swapped = true;
//            }
//            ptr1 = ptr1->next;
//        }
//        lptr = ptr1;
//    } while (swapped);
//}

template<typename T>
bool List<T>::contains(const T& element) const {
    Node* current = head; // ������� ��������� current � ������������� ��� �� ������ ������
    while (current != nullptr) { // ���� �� ��������� ����� ������
        if (current->data == element) { // ���� �������� �������� ���� ����� �������� ��������
            return true; // ���������� true, ��� ��� ������� ������
        }
        current = current->next; // ��������� � ���������� ���� ������
    }
    return false; // ���� ������� �� ������ ����� �������� ���� �����, ���������� false
}


template<typename T>
int List<T>::getSize() const {
    return size;
}