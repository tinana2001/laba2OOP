// laba2OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Human
{
public:
	int age;
private:
	int weight;
};

class Point
{
public:
	
	Point (){
		x = 0;
		y = 0;
		z = 0;
		cout << "Point()" << endl;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
		cout << "Point(int x, int y, int z)" << endl;
	}

	~Point() {
		cout << "~Point()" <<x<<" "<<y<<" "<<z<< endl;
	}
public:
	void Sum() {
		cout << "x+y+z =" << x + y + z << endl;
	}
public:
	void Print() {
		cout << "x="<<x<<endl << "y="<<y<<endl << "z="<<z << endl;
		PrintZ();//вызываем метод PrintZ
	}
	private://хоть z и y private, но в методе print из можно использовать, а так как метод print публичный, то и в main его можно вывести не смотря на то что y и z приватные
	int x,y, z;
	void PrintZ() {
		cout << z << endl;
		cout << "PrintZ" << endl; 
		//хоть метод printZ и приватный, но так как мы вызываем его в публичном методе Print,
		//то и в main'e он все равно выведется
	}
};
/*class Point
{
private:
	int x, y;
public:
	Point(int valueX, int valueY) {
		x = valueX;
		y = valueY;
	}
 };*/
int main()
{
	setlocale(LC_ALL, "rus");
	Human Artur;//статически
	Artur.age = 21;
	//Artur.weight; //не можем использовать, так как weight private
	cout <<"возраст Артура "<< Artur.age<<endl;
	Human* Nastya = new Human;//динамически
	Nastya->age = 19;
	cout <<"возраст Насти "<< Nastya->age<<endl;
	cout << "___________________________" << endl;
	//статически
	{
		Point a; 
		a.Print(); //вызываем метод print
		Point b(10, 20, 30);
		b.Sum(); //вызываем метод sum
	}
	//динамически
	Point* a = new Point;
	Point* b = new Point(100, 200, 300);
	delete a;
	delete b;
	
}


