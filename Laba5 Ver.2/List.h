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
	void insert(const T& element, int position); // днаюбкемхе щкелемрю б яохянй
    void insert(const T& element);

	void remove(int position); // сдюкемхе щкелемрю хг яохяйю

    void removeAll(); // сдюкемхе бяеу щкелемрнб хг яохяйю 

    bool contains(const T& element) const; // опнбепйю мю мюунфдемхе щкелемрю б яохяйе

	T& at(int position);  // онксвемхе яяшкйх мю щкелемр он хмдейяс 

	int getSize() const; // онксвемхе пюглепю яохяйю

    bool isEmpty() const;

    bool operator==(const List<T>& other) const;

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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
    if (this != &other) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

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
bool List<T>::operator==(const List<T>& other) const {
    if (this->size != other.size) {
        return false;
    }

    Node* current1 = this->head;
    Node* current2 = other.head;

    while (current1 && current2) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

//Methods
template<typename T>
void List<T>::insert(const T& element, int position) {
    if (position < 0 || position > size) { throw std::runtime_error("Invalid position"); }

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
void List<T>::insert(const T& element) {
    Node* newNode = new Node(element);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}


template<typename T>
void List<T>::remove(int position) {
    if (isEmpty()) { throw std::runtime_error("Is empty"); }
    if (position < 0 || position >= size) { throw std::runtime_error("Invalid position"); }

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
void List<T>::removeAll() {
    if (isEmpty()) { throw std::runtime_error("Is empty"); }
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}


template<typename T>
T& List<T>::at(int position) {
    if (position < 0 || position >= size) { throw std::runtime_error("Invalid position"); }
    Node* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
bool List<T>::contains(const T& element) const {
    Node* current = head;
    while (current != nullptr) {
        if (element == current->data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
int List<T>::getSize() const {
    return size;
}

template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

