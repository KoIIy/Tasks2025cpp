#include <iostream>

using namespace std;

class Animal {
private:
    static int count;
public:
    Animal() {
        count++;
    }
    ~Animal() {
        count--;
    }
    int GetCount() {
		return count;
    }
};

int Animal::count = 0;

class Point {
private:
		int x, y;
        Point(int _x, int _y) {
			x = _x;
			y = _y;
        }
public:
    static Point getPoint(int _x, int _y) {
		return Point(_x, _y);
    }
};

class Mous;

class Cat {
private:
    string name;
public:
    Cat(string _name) {
        name = _name;
    }
    void SayHello(const Mous& other);
	friend class Mous;
};

class Mous {
private:
    string name;
public:
    Mous(string _name) {
        name = _name;
    }
    void SayHello(const  Cat& other);
	friend class Cat;
};

void Cat::SayHello(const Mous& other) {
    cout << "Helloy, my name is " << name << " ,i am friend " << other.name << endl;
    return;
}
void Mous::SayHello(const  Cat& other) {
    cout << "Helloy, my name is " << name << " ,i am friend " << other.name << endl;
    return;
}

int main()
{
	Cat cat("Tom");
	Mous mous("Jerry");
	cat.SayHello(mous);
    mous.SayHello(cat);
}
