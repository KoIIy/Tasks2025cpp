
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int hours = 0, minutes = 0, seconds = 0;
public:
	bool setHour(int _h) {
		if (_h > 23 || _h < 0) {
			cout << "Часы в диапозоне 0-23" << endl;
			return false;
		}
		hours = _h;
		return true;
	}
	bool setMinuts(int _min) {
		if (_min > 59 || _min < 0) {
			cout << "Минуты в диапозоне 0-59" << endl;
			return false;
		}
		minutes = _min;
		return true;
	}
	bool setSeconds(int _sec) {
		if (_sec > 59 || _sec < 0) {
			cout << "Секунды в диапозоне 0-59" << endl;
			return false;
		}
		seconds = _sec;
		return true;
	}
	int getHour() { return hours; }
	int getMinuts() { return minutes; }
	int getSeconds() { return seconds; }
	bool setTime(int _h = 0, int _min = 0, int _sec = 0) {
		if (_h > 23 || _min > 59 || _sec > 59 || _h < 0 || _min < 0 || _sec < 0) {
			cout << "Время должно быть в диапозоне: часы 0-23, минуты 0-59, секунды 0-59" << endl;
			return false;
		}
		hours = _h;
		minutes = _min;
		seconds = _sec;
		return true;
	}
	void getTime() {
		string time="";
		if (hours < 10)
			time += "0";
		
		time += to_string(hours) + ":";
		if (minutes < 10)
			time += "0";
		time += to_string(minutes) + ":";
		if (seconds < 10)
			time += "0";
		time += to_string(seconds);
		cout << time;
	}
	Time(int _h=0, int _min=0, int _sec=0)
	{
		if (_h > 23||_min > 59||_sec>59|| _h < 0 || _min < 0 || _sec < 0) {
			cout<<"Время должно быть в диапозоне: часы 0-23, минуты 0-59, секунды 0-59"<<endl;
			return;
		}
		hours = _h;
		minutes = _min;
		seconds = _sec;
	}

};
class Date {
private:
	int day = 1, month = 1, year = 0;
public:
	bool setDay(int _day) {
		if (_day > 31 || _day < 1) {
			cout << "День в диапозоне 1-31" << endl;
			return false;
		}
		day = _day;
		return true;
	}
	bool setMonth(int _month) {
		if (_month > 12 || _month < 1) {
			cout << "Месяц в диапозоне 1-12" << endl;
			return false;
		}
		month = _month;
		return true;
	}
	bool setYear(int _year) {
		if (_year > 99 || _year < 0) {
			cout << "Год в диапозоне 0-99" << endl;
			return false;
		}
		year = _year;
		return true;
	}
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	bool setDate(int _day = 0, int _month = 0, int _year = 0) {
		if (_day > 31 || _month > 12 || _year > 99 || _day < 1 || _month < 1 || _year < 0) {
			cout << "Дата должна быть в диапозоне: дни 1-31, месяц 1-12, год 0-99" << endl;
			return false;
		}
		day = _day;
		month = _month;
		year = _year;
		return true;
	}
	void getDate() {
		string date = "";
		if (day < 10)
			date += "0";

		date += to_string(day) + "-";
		if (month < 10)
			date += "0";
		date += to_string(month) + "-";
		if (year < 10)
			date += "0";
		date += to_string(year);
		cout << date;
	}
	Date(int _day = 1, int _month = 1, int _year = 0)
	{
		if (_day > 31 || _month > 12 || _year > 99 || _day < 1 || _month < 1 || _year < 0) {
			cout << "Дата должна быть в диапозоне: дни 1-31, месяц 1-12, год 0-99" << endl;
			return;
		}
		day = _day;
		month = _month;
		year = _year;
	}

};
class Vector3D {
public:
	double x, y, z;
	Vector3D() {
		x = y = z = 0;
	}
	Vector3D(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	double Lenght() {
		return sqrt(pow(x,2) + pow(y,2)+pow(z,2));
	}
	void Sum(Vector3D other) {
		x += other.x;
		y += other.y;
		z += other.z;
	}
	void Sub(Vector3D other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}
	void Mul(double a) {
		x *= a;
		y *= a;
		z *= a;
	}
	void Div(double a) {
		if (a == 0) {
			cout << "На ноль делить нельзя"<<endl;
			return;
		}
			x /= a;
			y /= a;
			z /= a;
	}
	Vector3D Normalize() {
		double len = Lenght();
		return Vector3D(x / len,y / len,z/len);
	}
};
class Array {
private:
	int size;
	int* data;
public:
	Array(int _size) {
		if (_size <= 0) {
			cout << "Размер массива должен быть больше 0" << endl;
			return;
		}
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
	int getSize() {
		return size;
	}
};
int main()
{
	
	Vector3D vect(2,2,2);
	cout << vect.Lenght();
	Time time(10, 44, 55);
	time.getTime();
	Date date(10,12,3);
	date.getDate();

}
