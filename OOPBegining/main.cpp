#include <iostream>
#include <string>
int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	class Student {
		std::string name;
		int* marks;
		size_t marks_number;
		int age;
	public:
		Student() { // Конструктор
			std::cout << "Конструктор по умолчанию.\n";
			name = "noname";
			marks = nullptr;
			marks_number = 0;
			age = 0;
		}
		Student(std::string other_name, int other_age = 0) { // Параметрический конструктор
			std::cout << "Параметрический конструктор.\n";
			name = other_name;
			marks = nullptr;
			marks_number = 0;
			setAge(other_age);
		}
		~Student() {
			std::cout << "Деструктор.\n"; // Деструктор
			delete[]marks;
		}
		void sayName() { // Метод класса
			std::cout << "My name is " << name;
		}
		void setMark(int mark) { //  метод класса, Свойства (сеттер), передать значения класса
			if (marks == nullptr) {
				marks = new int[1] {mark};
				marks_number = 1;
				return;
			}
			int* tmp = new int[marks_number + 1];
			for (size_t i = 0; i < marks_number; ++i)
				tmp[i] = marks[i];
			tmp[marks_number] = mark;
			delete[]marks;
			marks = tmp;
			++marks_number;
		}
		int getMark(size_t index) { 
		}
		void setAge(int other_age) {
			if (other_age >= 5 && other_age <= 55) {
				age = other_age;
				return;
			}
		age = 0;
		}
		int getAge() {
			return age;
		}
		

	};

	// Блок проверки деструктора
	if (true) {
		Student tmp;
	}


	Student s1("Tom Smith", 55); // Вызов конструктора каждый раз когда создается объект.

	//s1.name = "tom smith"; // ОШИБКА! (инкапсуляция)
	s1.sayName(); // Вызов метода
	s1.setMark(6); // Вызов метода
	s1.setMark(12); // Вызов метода
	std::cout << '\n';
	std::cout << s1.getMark(0) << std::endl;
	std::cout << s1.getMark(1) << std::endl;
	
	std::cout << "Возраст: " << s1.getAge() << std::endl;
	

	return 0;
}