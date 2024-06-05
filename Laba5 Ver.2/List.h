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
	void insert(const T& element, int position); // ДОБАВЛЕНИЕ ЭЛЕМЕНТА В СПИСОК
    void insert(const T& element);
	void remove(int position); // УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ СПИСКА
    void removeAll(); // УДАЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ ИЗ СПИСКА 
    bool contains(const T& element) const; // ПРОВЕРКА НА НАХОЖДЕНИЕ ЭЛЕМЕНТА В СПИСКЕ
	T& at(int position);  // ПОЛУЧЕНИЕ ССЫЛКИ НА ЭЛЕМЕНТ ПО ИНДЕКСУ 
	//void sort(); // СОРТИРОВКА ЭЛЕМЕНТОВ СПИСКА
	int getSize() const; // ПОЛУЧЕНИЕ РАЗМЕРА СПИСКА

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
    // Проверяем, что это не присваивание самому себе
    if (this != &other) {
        // Очищаем текущий список, чтобы избежать утечек памяти
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Копируем элементы из другого списка
        head = nullptr; // Устанавливаем голову нового списка в nullptr
        size = 0; // Сбрасываем размер

        // Копируем элементы из списка `other`
        Node* current = other.head; // Указатель для перебора элементов другого списка
        while (current) {
            insert(current->data, size); // Вставляем копируемый элемент в конец текущего списка
            current = current->next; // Перемещаемся к следующему элементу в другом списке
        }
    }
    return *this; // Возвращаем ссылку на текущий список
}


//Methods
template<typename T>
void List<T>::insert(const T& element, int position) {
    // Проверяем, что позиция в пределах списка
    if (position < 0 || position > size) {
        throw std::runtime_error("Invalid position");
    }

    // Создаем новый узел с заданным элементом
    Node* newNode = new Node(element);

    // Если позиция 0, вставляем элемент в начало списка
    if (position == 0) {
        newNode->next = head; // Новый узел указывает на текущую голову списка
        head = newNode; // Новый узел становится новой головой списка
    }
    else {
        Node* current = head; // Указатель для перемещения по списку, начинаем с головы
        // Перемещаемся к элементу, предшествующему позиции вставки
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        // Вставляем новый узел между текущим элементом и следующим элементом
        newNode->next = current->next;
        current->next = newNode;
    }
    ++size; // Увеличиваем размер списка на 1
}


template<typename T>
void List<T>::insert(const T& element) {
    Node* newNode = new Node(element); // Создаем новый узел с заданным элементом
    if (head == nullptr) { // Если список пуст (голова равна nullptr)
        head = newNode; // Устанавливаем новый узел как голову списка
    }
    else { // Если список не пуст
        Node* current = head; // Указатель для перемещения по списку, начинаем с головы
        while (current->next != nullptr) { // Пока не дойдем до последнего элемента
            current = current->next; // Перемещаемся к следующему элементу
        }
        current->next = newNode; // Устанавливаем связь между текущим последним элементом и новым элементом
    }
    ++size; // Увеличиваем размер списка на 1
}


template<typename T>
void List<T>::remove(int position) {
    if (position < 0 || position >= size) { // Проверяем, что позиция находится в пределах списка
        throw std::runtime_error("Invalid position"); // Если позиция некорректна, выбрасываем исключение
    }
    Node* temp; // Временный указатель для хранения удаляемого узла
    if (position == 0) { // Если удаляемый элемент - первый в списке
        temp = head; // Устанавливаем временный указатель на голову списка
        head = head->next; // Перемещаем голову на следующий элемент
    }
    else { // Если удаляемый элемент не первый в списке
        Node* current = head; // Указатель для перемещения по списку
        for (int i = 0; i < position - 1; ++i) { // Доходим до элемента перед удаляемым
            current = current->next; // Перемещаемся к следующему элементу
        }
        temp = current->next; // Запоминаем удаляемый элемент
        current->next = temp->next; // Устанавливаем связь между текущим элементом и следующим за удаляемым
    }
    delete temp; // Удаляем узел
    --size; // Уменьшаем размер списка
}


template<typename T>
void List<T>::removeAll() {
    while (head != nullptr) { // Пока список не пустой
        Node* temp = head; // Создаем временный указатель на голову списка
        head = head->next; // Перемещаем голову списка на следующий элемент
        delete temp; // Удаляем текущий элемент
    }
    size = 0; // Устанавливаем размер списка в ноль
}


template<typename T>
T& List<T>::at(int position) {
    if (position < 0 || position >= size) { throw std::runtime_error("Invalid position"); }
    Node* current = head; // Создаем указатель current и устанавливаем его на начало списка
    for (int i = 0; i < position; ++i) { // Проходим по списку до указанной позиции
        current = current->next; // Переходим к следующему узлу списка
    }
    return current->data; // Возвращаем данные текущего узла
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
    Node* current = head; // Создаем указатель current и устанавливаем его на начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == element) { // Если значение текущего узла равно искомому элементу
            return true; // Возвращаем true, так как элемент найден
        }
        current = current->next; // Переходим к следующему узлу списка
    }
    return false; // Если элемент не найден после проверки всех узлов, возвращаем false
}


template<typename T>
int List<T>::getSize() const {
    return size;
}