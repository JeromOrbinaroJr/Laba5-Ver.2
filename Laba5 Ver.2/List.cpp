//#include "List.hpp"
//
////Constructors
//template<typename T>
//List<T>::List() : head(nullptr), size(0) {}
//
//template<typename T>
//List<T>::List(const List<T>& other) {
//    head = nullptr;
//    size = 0;
//    Node* current = other.head;
//    while (current) {
//        insert(current->data, size);
//        current = current->next;
//    }
//}
//
////Destructor
//template<typename T>
//List<T>::~List() {
//    while (head) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//}
//
////Operators Overloading
//template<typename T>
//List<T>& List<T>::operator=(const List<T>& other) {
//    if (this != &other) {
//        // Clear current list
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        // Copy elements from other list
//        head = nullptr;
//        size = 0;
//        Node* current = other.head;
//        while (current) {
//            insert(current->data, size);
//            current = current->next;
//        }
//    }
//    return *this;
//}
//
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const List<T>& list) {
//    typename List<T>::Node* current = list.head;
//    while (current) {
//        os << current->data.getSurname() << " " << current->data.getName() << " " << current->data.getNumberGroup();
//        current = current->next;
//    }
//    return os;
//}
//
////Methods
//template<typename T>
//void List<T>::insert(const T& element, int position) {
//    if (position < 0 || position > size) {
//        throw std::out_of_range("Invalid position");
//    }
//    Node* newNode = new Node(element);
//    if (position == 0) {
//        newNode->next = head;
//        head = newNode;
//    }
//    else {
//        Node* current = head;
//        for (int i = 0; i < position - 1; ++i) {
//            current = current->next;
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//    }
//    ++size;
//}
//
//template<typename T>
//void List<T>::insert(const T& element) {
//    Node* newNode = new Node(element);
//    if (head == nullptr) {
//        head = newNode;
//    }
//    else {
//        Node* current = head;
//        while (current->next != nullptr) {
//            current = current->next;
//        }
//        current->next = newNode;
//    }
//    ++size;
//}
//
//template<typename T>
//void List<T>::remove(int position) {
//    if (position < 0 || position >= size) {
//        throw std::out_of_range("Invalid position");
//    }
//    Node* temp;
//    if (position == 0) {
//        temp = head;
//        head = head->next;
//    }
//    else {
//        Node* current = head;
//        for (int i = 0; i < position - 1; ++i) {
//            current = current->next;
//        }
//        temp = current->next;
//        current->next = temp->next;
//    }
//    delete temp;
//    --size;
//}
//
//template<typename T>
//void List<T>::removeAll() {
//    while (head != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//    size = 0;
//}
//
//template<typename T>
//T& List<T>::at(int position) {
//    if (position < 0 || position >= size) {
//        throw std::out_of_range("Invalid position");
//    }
//    Node* current = head;
//    for (int i = 0; i < position; ++i) {
//        current = current->next;
//    }
//    return current->data;
//}
//
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
//
//template<typename T>
//bool List<T>::contains(const T& element) const {
//    Node* current = head;
//    while (current != nullptr) {
//        if (current->data == element) {
//            return true;
//        }
//        current = current->next;
//    }
//    return false;
//}
//
//
//template<typename T>
//int List<T>::getSize() const {
//    return size;
//}