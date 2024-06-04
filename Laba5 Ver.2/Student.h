#pragma once
#include <string>

class Student {
public:
	//Constructors
	Student() = default;
	explicit Student(const std::string& surname, const std::string& name, const std::string& numberGroup);

	//Destructor  
	~Student() = default;

	//Getters
	const std::string& getSurname() const;
	const std::string& getName() const;
	const std::string& getNumberGroup() const;

	//Setters
	void setSurname(const std::string& surname);
	void setName(const std::string& name);
	void setNumberGroup(const std::string& numberGroup);

private:
	std::string m_surname;
	std::string m_name;
	std::string m_numberGroup;
};