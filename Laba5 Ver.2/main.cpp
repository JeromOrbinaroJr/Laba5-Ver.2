#include "List.h"
#include "Student.h"
#include <iostream>

int main() {
	List<Student> studentList;

	Student student1("Doe", "John", "IDB-23-12");
	Student student2("Dim", "Jone", "IDB-23-13");
	Student student3("Kane", "Gam", "IDB-23-14");

	studentList.insert(student1);
	studentList.insert(student2);
	studentList.insert(student3);

	for (int i = 0; i < studentList.getSize(); ++i) {
		std::cout << studentList.at(i) << std::endl;
	}

	std::cout << studentList.contains(student1);
	return 0;
}