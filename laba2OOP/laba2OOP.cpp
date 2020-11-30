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
		cout << "Point()" << endl;
		x = 0;
		y = 0;
		z = 0;
		
	}
	Point(int x, int y, int z) { 
		cout << "Point(int x, int y, int z)" << endl;
		this->x = x;
		this->y = y;
		this->z = z;
		
	}

	Point(const Point &p) {
		cout << "Point(const Point &p)" << endl;
		x = p.x;
		y = p.y;
		z = p.z;
		
	}
	virtual ~Point() {
		cout << "~Point()" <<x<<" "<<y<<" "<<z<< endl;
	}

   //метод print
   
	void Print() 
	{ 
		cout << "метод Print()" << endl;
		cout << "x="<<x<<endl << "y="<<y<<endl << "z="<<z << endl;
	}
public:
	void Add();
};
void Point::Add() {
	x = x + 1;
	y = y + 1;
	z = z + 1;
	cout <<"метод Add" << endl;
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
	WeightedPoint(int x, int y, int z, int weight) : Point(x,y,z) { //для конструктора явно указали какой конструктор предка должен вызываться
		this->weight = weight;
		
		cout << "WeightPoint(int x, int y, int z)" << x << " " << y << " " << z << " " <<"weight= "<< weight<< endl;
	}

	WeightedPoint(const WeightedPoint& p) { //копируем все 4 поля вручную
		cout << "WeightPoint(const Point &p)" << endl;
		weight = p.weight;
		x = p.x;
		y = p.y;
		z = p.z;
		
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

class Triangle
{
protected:
	Point* p1; //указатели на объект класса Point 
	Point* p2;
	Point* p3;
public:

	Triangle() {

		cout << "Triangle()" << endl;
		p1 = new Point;
		p2 = new Point;
		p3 = new Point;
		
	}
	Triangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
		cout << "Triangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3)" << endl;
		p1 = new Point(x1,y1,z1);
		p2 = new Point(x2,y2,z2);
		p3 = new Point(x3,y3,z3);
		
	}
	 //нужен чтобы у нас появилась возможность копировать данные из одного объекта в другой
	//из объекта t в наш конкретный объект  
	//для копирования объекта t нужно создать 2 новых объекта P
	Triangle(const Triangle& t) {  //создаем копию уже существующего треугольника 
		cout << "Triangle(const Triangle &p)" << endl;
		p1 = new Point(*(t.p1));//t-объект класса Point
		p2 = new Point(*(t.p2));
		p3 = new Point(*(t.p3));
		
	}
	~ Triangle() {
		
		delete p1;
		delete p2;
		delete p3;
		cout << "~Triangle()" << endl;
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
	Human Artur;
	//Artur.weight; //не можем использовать, так как weight private
	
	//статически
	{
		Point a; 
		Point b(10, 20, 30);
		b.Add(); //вызываем метод sum
		b.Print();//вызываем метод print 
		Point c(b);
		
	}
	//динамически
	cout << "______________________" << endl;
	Point* a = new Point;
	Point* b = new Point(100, 200, 300);
	Point* c = new Point(*b);
	b->Print();
	b->Add(); 
	delete a;
	delete b;
	delete c;
	cout << "______\n";
	cout << "помещение в объектов в переменные различных типов" << endl;
	Point* g = new WeightedPoint(100, 200, 300, 54);
	cout << "******************\n";
	//если бы мы не использовали виртуальный деструктор 
	//вызовался бы деструктор только бзового класса 
	delete g;
	
	cout << "______________________" << endl;
	WeightedPoint* w = new WeightedPoint(1,2,3,54);
	w->WeightedPrint(); //для нас открывается доступ к методам класса weightedPoint
	delete w;
	cout << "_________\n";

	Triangle* t1 = new Triangle;
	Triangle* t2 = new Triangle(*t1); //копия первого
	Triangle* t3 = new Triangle (1,2,3,4,5,6,4,5,4);
	delete t1;
	delete t2;
	delete t3;


}


