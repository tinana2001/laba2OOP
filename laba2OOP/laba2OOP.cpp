// laba2OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Human
{
public:
	int age;
};
class Point
{
public:
	int x=5;
	void Print() {
		cout << "x="<<x<<endl << "y="<<y<<endl << "z="<<z << endl;
		PrintZ();
	}
private://хоть z и y private, но в методе print из можно использовать, а так как метод print публичный, то и в main его можно вывести не смотря на то что y и z приватные
	int y=9, z=7;
	void PrintZ() {
		cout << z << "\t";
		cout << "PrintZ" << endl; 
		//хоть метод printZ и приватный, но так как мы вызываем его в публичном методе Print,
		//то и в main'e он все равно выведется
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Human Artur;//статически
	Artur.age = 21;
	cout <<"возраст Артура "<< Artur.age<<endl;
	Human* Nastya = new Human;//динамически
	Nastya->age = 19;
	cout <<"возраст Насти "<< Nastya->age<<endl;
	cout << "___________________________" << endl;
	Point a;
	a.Print();
}


