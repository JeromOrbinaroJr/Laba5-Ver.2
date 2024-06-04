#include "List.h"
#include "Student.h"
#include <iostream>

int main() {
	List<Student> list;

	Student student1("Doe", "John", "IDB-23-12");
	list.insert(student1, 0);
	std::cout << list;

	return 0;
}