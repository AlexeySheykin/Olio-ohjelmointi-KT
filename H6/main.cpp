#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student {
private:
    std::string Name;
    int Age;

public:

    Student(std::string name, int age) : Name(name), Age(age) {}


    void setAge(int age) {
        Age = age;
    }

    void setName(std::string name) {
        Name = name;
    }


    std::string getName() const {
        return Name;
    }

    int getAge() const {
        return Age;
    }


    void printStudentInfo() const {
        std::cout << "Student Name: " << Name << "\nAge: " << Age << std::endl;
    }
};

int main() {
    int selection = 0;
    std::vector<Student> studentList;

    do {
        std::cout << "\nSelect:" << std::endl;
        std::cout << "Add students = 0" << std::endl;
        std::cout << "Print all students = 1" << std::endl;
        std::cout << "Sort and print students according to Name = 2" << std::endl;
        std::cout << "Sort and print students according to Age = 3" << std::endl;
        std::cout << "Find and print student = 4" << std::endl;
        std::cin >> selection;

        switch (selection) {
        case 0: {
            std::string name;
            int age;
            std::cout << "Enter student name: ";
            std::cin >> name;
            std::cout << "Enter student age: ";
            std::cin >> age;
            studentList.emplace_back(name, age);
            break;
        }
        case 1: {
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            std::sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            std::sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getAge() < b.getAge();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            std::string searchName;
            std::cout << "Enter student name to search: ";
            std::cin >> searchName;
            auto it = std::find_if(studentList.begin(), studentList.end(), [&searchName](const Student& student) {
                return student.getName() == searchName;
            });
            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                std::cout << "Student not found." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Wrong selection, stopping..." << std::endl;
            break;
        }
    } while (selection < 5);

    return 0;
}

