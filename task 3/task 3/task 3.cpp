
#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	size_t size;
	int* data;
public:
	~Array() {
		delete[] data;
	}
	Array(size_t _size) {
		size = _size;
		data = new int[_size];
		
	}
	bool setElement(int index, int value) {
		if (index >= size || index < 0)
		{
			cout << "Индекс должен быть в диапозоне от 0 до " + to_string(size - 1) << endl;
			return false;
		}
		data[index] = value;
	}
	int getElement(int index) {
		if (index >= size || index < 0)
		{
			cout << "Индекс должен быть в диапозоне от 0 до " + to_string(size - 1) << endl;
			return false;
		}
		return data[index];
	}
	size_t getSize() {
		return size;
	}
};
class String {
public:
	size_t size=0;
	char* data;
	String(const char* _data) {
		size = strlen(_data);
		data = new char[size + 1];
		strcpy_s(data, size + 1, _data);
	}
	String(const String& other) {
		size = other.size;
		data = new char[size + 1];
		strcpy_s(data, size + 1, other.data);
	}
	String() {
		data = new char[1];
	}
	~String() {
		delete[] data;
	}
	const char* getStartCharArray() {
		return data;
	}
	char getChar(size_t index) {
		if (index > size - 1)
		{
			cout << "Выход за пределы массива" << endl;
			return NULL;
		}
		return data[index];
	}
	
};
class Stack {
public:
	size_t size;
	size_t capacity;
	int* data;
	Stack() {
		data = new int[100];
		capacity = 100;
		size = 0;
	}
	~Stack() {
		delete[] data;
	}
	int Pop() {
		return data[size - 1];
	}
	void Push(int value) {
		if (size == capacity) {
			size_t newCapacity = capacity + 100;
			int* newData = new int[newCapacity];
			for (int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			capacity = newCapacity;
		 }
		data[size++] = value;
	}
	bool Empty() {
		return size == 0;
	}


};
class Vector2D {
public:
	double x, y;
	Vector2D() {
		x = y  = 0;
	}
	Vector2D(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	double Lenght() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	Vector2D& Sum(const Vector2D& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2D& Sub(const Vector2D& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vector2D& Mul(double a) {
		x *= a;
		y *= a;
		return *this;
	}
	Vector2D& Div(double a) {
		if (a == 0) {
			throw(runtime_error("На ноль делить нельзя"));
		}
		x /= a;
		y /= a;
		return *this;
	}
	Vector2D Normalize() {
		double len = Lenght();
		return Vector2D(x/len,y/len);
	}
};
int main()
{
	Vector2D vec(2, 3);
	vec.Mul(3).Div(3);
	cout << vec.x << " " << vec.y;
	
}
