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
protected:
	int x, y,z;
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

	Point(const Point &p) {
		x = p.x;
		y = p.y;
		z = p.z;
		cout << "Point(const Point &p)" << endl;
	}
	~Point() {
		cout << "~Point()" <<x<<" "<<y<<" "<<z<< endl;
	}

   //метод print
	void Print() 
	{ 
		cout << "метод Print()" << endl;
		cout << "x="<<x<<endl << "y="<<y<<endl << "z="<<z << endl;
		PrintZ();//вызываем метод PrintZ
	}
	private://хоть z и y protected, но в методе print иx можно использовать, а так как метод print публичный, то и в main его можно вывести
	
	void PrintZ() //приватный метод printZ
	{
		cout << "метод PrintZ" << endl;
		cout << z << endl;
		
		//хоть метод printZ и приватный, но так как мы вызываем его в публичном методе Print,
		//то и в main'e он все равно выведется
	}
public:
	void Sum();
};
void Point::Sum() {
	cout << "x+y+z =" << x + y + z << endl;
}

class WeightedPoint: public Point
{
protected:
	int weight;
public:

	WeightedPoint(): Point() {
		weight = 0;
		
		cout << "WeightedPoint()" << endl;
	}
	WeightedPoint(int x, int y, int z, int weight) : Point(x,y,z) {
		this->weight = weight;
		
		cout << "WeightPoint(int x, int y, int z)" << x << " " << y << " " << z << " " <<"weight= "<< weight<< endl;
	}

	WeightedPoint(const WeightedPoint& p) { //копируем все 4 поля вручную
		weight = p.weight;
		x = p.x;
		y = p.y;
		z = p.z;
		cout << "WeightPoint(const Point &p)" << endl;
	}
	~WeightedPoint() {
		cout << "~WeightPoint()" << x << " " << y << " " << z <<" "<<weight<< endl;
	}

	//метод print
	void WeightedPrint()
	{
		cout << "метод WaightPrint()" << endl;
		cout << "x=" << x << endl << "y=" << y << endl << "z=" << z<<endl <<"weight ="<<weight<< endl;
		
	}

};


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
		Point b(10, 20, 30);
		b.Sum(); //вызываем метод sum
		b.Print();//вызываем метод print 
		Point c(b);
		
	}
	//динамически
	cout << "______________________" << endl;
	Point* a = new Point;
	Point* b = new Point(100, 200, 300);
	Point* c = new Point(*b);
	b->Sum();
	
	delete a;
	delete b;
	delete c;
	cout << "______\n";
	cout << "помещение в объектов в переменные различных типов" << endl;
	Point* g = new WeightedPoint(100, 200, 300, 54);

	//вызовится деструктор только бзового класса 
	delete g;
	
	cout << "______________________" << endl;
	WeightedPoint* w = new WeightedPoint(1,2,3,54);
	w->WeightedPrint(); //для нас открывается доступ к методам класса weightedPrint 
	delete w;



}


