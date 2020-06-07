#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student
{
	std::string name{};
	int grade{};
};

using class_student = std::vector<Student>;

bool isInvalid()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return true;
	}
	return false;
}

int getNumberOfStudents()
{
	int students{};
	do {
		std::cout << "How many students do you want to enter: ";
		std::cin >> students;
	} while (isInvalid() || students <= 0);
	return students;
}

std::string getStudentName(int &number)
{
	std::string name{};
	do {
		std::cout << "Name #" << number << ": ";
		std::cin >> name;
	} while (isInvalid());
	return name;
}

int getStudentGrade(int &number)
{
	int grade{};
	do {
		std::cout << "Grade #" << number << ": ";
		std::cin >> grade;
	} while (isInvalid() || (grade < 0 || grade > 100));
	return grade;
}


class_student getStudentsData(int &number)
{
	class_student classStudent(static_cast<class_student::size_type>(number));
	int studentNumber{ 1 };
	for (auto &student : classStudent)
	{
		student.name = getStudentName(studentNumber);
		student.grade = getStudentGrade(studentNumber);
		studentNumber++;
	}
	return classStudent;
}

bool highestGrade(Student a, Student b)
{
	return (a.grade > b.grade);
}

void printStudents(class_student &classStudent)
{
	for (Student student : classStudent)
		std::cout << student.name << " got a grade of " << student.grade << "\n";
}

int main()
{
	int numberOfStudents{ getNumberOfStudents() };
	auto classStudent{ getStudentsData(numberOfStudents) };
	std::sort(classStudent.begin(), classStudent.end(), highestGrade);
	printStudents(classStudent);
	return 0;
}