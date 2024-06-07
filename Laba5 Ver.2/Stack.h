#pragma once
#include "List.h"
#include <iostream>

template<typename T>
class Stack {
public:
	//Constructor
	Stack() {}

	//Destructor
	~Stack() {}

	//Methods
	void push(const T& element); // днаюбкемхе щкелемрю б ярей

	void pop(); // сдюкемхе онякедмецн щкелемрю хг ярейю

	T& top(); // онксвемхе бепумецн щкелемрю ярейю

	bool isEmpty() const;

	int size() const;

	bool contains(const T& element) const; // опнбепйю мю опхясрярбхе щкелемрю б ярейе

	void merge(const Stack& other); // назедхмемхе дбсу ярейнб

	Stack<T> intersection(const Stack<T>& other) const; // оепеяевемхе дбсу ярейнб

	Stack<T> addition(const Stack<T>& other) const; // днонкмемхе ярейнб (щкелемрш, бундъыхе б нямнбмни ярей, мн ме бундъыхе б ярей OTHER)

	void print() const;

private:
	List<T> list;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Methods

template<typename T>
void Stack<T>::push(const T& element) {
	list.insert(element);
}

template<typename T>
void Stack<T>::pop() {
	if (isEmpty()) { throw std::runtime_error("Stack is empty."); }
	list.remove(list.getSize() - 1);
}

template<typename T>
T& Stack<T>::top() {
	if (isEmpty()) { throw std::runtime_error("Stack is empty."); }
	return list.at(list.getSize() - 1);
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return list.getSize() == 0;
}

template<typename T>
int Stack<T>::size() const {
	return list.getSize();
}

template<typename T>
bool Stack<T>::contains(const T& element) const {
	return list.contains(element);
}

template<typename T>
void Stack<T>::merge(const Stack& other) {
	if (other.isEmpty()) { throw std::runtime_error("Other stack is empty."); }
	for (int i = 0; i < other.size(); ++i) {
		push(other.top());
		other.pop();
	}
}

template<typename T>
Stack<T> Stack<T>::intersection(const Stack<T>& other) const {
	if (other.isEmpty()) { throw std::runtime_error("Other stack is empty."); }
	if (isEmpty()) { throw std::runtime_error("Main stack is empty."); }
	Stack<T> intersectionStack;
	Stack<T> tempStack(*this);

	while (!tempStack.isEmpty()) {
		T topElement = tempStack.top();
		if (other.contains(topElement)) {
			intersectionStack.push(topElement);
		}
		tempStack.pop();
	}
	return intersectionStack;
}

template<typename T>
Stack<T> Stack<T>::addition(const Stack<T>& other) const {
	if (other.isEmpty()) { throw std::runtime_error("Other stack is empty."); }
	if (isEmpty()) { throw std::runtime_error("Main stack is empty."); }
	Stack<T> additionStack;
	Stack<T> tempStack(*this);

	while (!tempStack.isEmpty()) {
		T element = tempStack.top();
		tempStack.pop();
		if (!other.contains(element)) {
			additionStack.push(element);
		}
	}
	return additionStack;
}

template<typename T>
void Stack<T>::print() const {
	if (isEmpty()) { throw std::runtime_error("Main stack is empty."); }
	Stack<T> tempStack(*this);
	std::cout << "Stack elements: " << std::endl;
	while (!tempStack.isEmpty()) {
		std::cout << tempStack.top() << std::endl;
		tempStack.pop();
	}
}