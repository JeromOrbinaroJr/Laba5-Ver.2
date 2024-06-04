#pragma once
#include <stdexcept>
#include <algorithm>

template <typename T>
class List {
public:
	//Constructors
	List();
	List(const List<T>& other);
	~List();

	//Operators Overloading
	List<T>& operator=(const List<T>& other);
    friend std::ostream& operator<<(std::ostream& os, const List<T>& list);

	void insert(const T& element, int position);
	void remove(int position);
	T& at(int position);
	void sort();
	int getSize() const;

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

template<typename T>
List<T>::~List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        // Clear current list
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        // Copy elements from other list
        head = nullptr;
        size = 0;
        Node* current = other.head;
        while (current) {
            insert(current->data, size);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    typename List<T>::Node* current = list.head;
    while (current) {
        os << current->data.getSurname() << " " << current->data.getName() << " " << current->data.getNumberGroup();
        current = current->next;
    }
    return os;
}


template<typename T>
void List<T>::insert(const T& element, int position) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Invalid position");
    }
    Node* newNode = new Node(element);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    ++size;
}

template<typename T>
void List<T>::remove(int position) {
    if (position < 0 || position >= size) {
        throw std::out_of_range("Invalid position");
    }
    Node* temp;
    if (position == 0) {
        temp = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    delete temp;
    --size;
}

template<typename T>
T& List<T>::at(int position) {
    if (position < 0 || position >= size) {
        throw std::out_of_range("Invalid position");
    }
    Node* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void List<T>::sort() {
    // Implement sorting algorithm, e.g., bubble sort, quicksort, etc.
}

template<typename T>
int List<T>::getSize() const {
    return size;
}