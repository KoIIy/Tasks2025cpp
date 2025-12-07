#include <iostream>
#include <vector>

using namespace std;
class Shape {
	public:
		virtual double Area() = 0;
		virtual double Perimeter() = 0;
};
class Rectangle : public Shape {
	private:
		double length;
		double width;
	public:
		Rectangle(double _length, double _width) : length(_length), width(_width) {}
		double Area() override {
			return length * width;
		}
		double Perimeter() override {
			return 2 * (length + width);
		}
};
class Square : public Rectangle {
	public:
		Square(double side) : Rectangle(side, side) {}
		double Area() override {
			return Rectangle::Area();
		}
		double Perimeter() override {
			return Rectangle::Perimeter();
		}
};
class Circle : public Shape {
	private:
		double radius;
	public:
		Circle(double _radius) : radius(_radius) {}
		double Area() override {
			return 3.14 * radius * radius;
		}
		double Perimeter() override {
			return 2 * 3.14 * radius;
		}
};

class Animal {
protected:
	public:
		virtual void SayHello() = 0;
};
class Cat : public Animal {
private:
	string name, type;
	size_t age;
public:
	Cat(string _name, size_t _age) : name(_name), type("Кот"), age(_age) {}
	void SayHello() override {
		cout << type << ": Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
	}
};
class Dog : public Animal {
private:
	string name, type;
	size_t age;
public:
	Dog(string _name, size_t _age) : name(_name), type("Собака"), age(_age) {}
	void SayHello() override {
		cout << type << ": Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
	}
};
class Duck : public Animal {
private:
	string name, type;
	size_t age;
public:
	Duck(string _name, size_t _age) : name(_name), type("Утка"), age(_age) {}
	void SayHello() override{
		cout << type << ": Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
	}
};

int main()
{
	vector<shared_ptr<Shape>> shapes;
	vector<shared_ptr<Animal>> animals;
	animals.push_back(make_shared<Cat>("Мурзик", 5));
	animals[0]->SayHello();
}

