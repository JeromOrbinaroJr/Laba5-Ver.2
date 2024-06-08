#include "Stack.h"
#include "Student.h"
#include <iostream>

int main() {
	Stack<Student> studentStack;
	Stack<Student> studentStackVer2;

	Student student1("Doe", "John", "IDB-23-12");
	Student student2("Dim", "Jone", "IDB-23-13");
	Student student3("Kane", "Gam", "IDB-23-14");

	studentStack.push(student1);
	studentStack.push(student2);
	studentStack.push(student3);
	studentStackVer2.push(student3);

	//studentStack.pop();

	//std::cout << studentStack.top() << std::endl;

	//studentStack.intersection(studentStackVer2).print();

	//studentStack.addition(studentStackVer2).print();

	//std::cout << "Stack is empty? : " << studentStack.isEmpty() << std::endl;

	studentStack.print();

	return 0;
}