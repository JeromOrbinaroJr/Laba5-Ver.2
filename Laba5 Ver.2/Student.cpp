#include "Student.h"

//Constructor
Student::Student(const std::string& surname, const std::string& name, const std::string& numberGroup) :
	m_surname(surname), m_name(name), m_numberGroup(numberGroup) {}

//Getters
const std::string& Student::getSurname() const { return m_surname; }
const std::string& Student::getName() const { return m_name; }
const std::string& Student::getNumberGroup() const { return m_numberGroup; }

//Setters
void Student::setSurname(const std::string& surname) { m_surname = surname; }
void Student::setName(const std::string& name) { m_name = name; }
void Student::setNumberGroup(const std::string& numberGroup) { m_numberGroup = numberGroup; }

//Operator Overloading
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getSurname() << " " << student.getName() << " " << student.getNumberGroup();
    return os;
}

bool Student::operator==(const Student& other) const {
	return m_surname == other.m_surname && m_name == other.m_name && m_numberGroup == other.m_numberGroup;
}
