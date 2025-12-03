#include <iostream>

using namespace std;

class Integer {
public:
    int i;
    Integer(int value) {
        i = value;
    }
    Integer& operator+(Integer value) {
        value.i += i;
        return value;
    }
    Integer& operator-(Integer value) {
        value.i -= i;
        return value;
    }
    Integer& operator*(Integer value) {
        value.i *= i;
        return value;
    }
    Integer& operator/(Integer value) {
        value.i /= i;
        return value;
    }
    Integer& operator++() {
        ++i;
        return *this;
    }
    Integer& operator++(int) {
        Integer temp = *this;
        ++i;
        return temp;
    }
    Integer& operator--() {
        --i;
        return *this;
    }
    Integer& operator--(int) {
        Integer temp = *this;
        --i;
        return temp;
    }

};

class Vector2D {
public:
    double x, y;
    Vector2D() {
        x = y = 0;
    }
    Vector2D(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double Lenght() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x+other.x,y+other.y);
    }
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }
    Vector2D operator*(double a) {
        return Vector2D(x * a, y + a);
    }
    Vector2D operator/(double a) {
        if (a == 0) {
            throw(runtime_error("На ноль делить нельзя"));
        }
        return Vector2D(x / a, y / a);
    }
    Vector2D Normalize() {
        double len = Lenght();
        if (len == 0) {
            throw(runtime_error("На ноль делить нельзя"));
        }
        return Vector2D(x / len, y / len);
    }
};
ostream& operator << (ostream& os, const Vector2D& other) {
    return os << "x: " << other.x << endl << "y: " << other.y;
}

class Matrix {
public:
    int** value;
    int row, column;
    Matrix(int _row, int _column) {
        value = new int*[_row];
        for (int i = 0; i < _row; i++) {
            value[i] = new int[_column] {0};
        }
        row = _row;
        column = _column;
    }
    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] value[i];
        }
        delete[] value;
    }
    int GetItem(int i, int j) {
        if (i >= row || j >= column)
        {
            throw(runtime_error("Выход за пределы матрицы"));
        }
        return value[i][j];

    }
    Matrix& operator+(const Matrix& other) {
        if (row != other.row || column != other.column) {
            throw(runtime_error("Размерность матриц не совпадает"));
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                value[i][j] += other.value[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-(const Matrix& other) {
        if (row != other.row || column != other.column) {
            throw(runtime_error("Размерность матриц не совпадает"));
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                value[i][j] -= other.value[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*(int t) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                value[i][j] *= t;
            }
        }
        return *this;
    }
    Matrix& operator/(int t) {
        if (t==0) {
            throw(runtime_error("На ноль делить нельзя"));
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                value[i][j] /= t;
            }
        }
        return *this;
    }
    Matrix operator*(const Matrix& other) {
        if (row != other.column) {
            throw(runtime_error("количество строк в первой матрице должно совпадать с количеством колонн во второй"));
        }
        Matrix temp(other.row, column);
        for (int i = 0; i < other.row; i++) {
            for (int j = 0; j < column; j++) {
                int tempValue = 0;
                for (int s = 0; s < other.column; s++) {
                    tempValue += value[s][j] * other.value[i][s];
                }
                temp.value[i][j] = tempValue;
            }
        }
        return temp;
    }

};

ostream& operator << (ostream& os, const Matrix& other) {
    for (int i = 0; i < other.row; i++){
        os << "[";
        for (int j = 0; j < other.column; j++) {
            os << " " << other.value[i][j] << " ";
        }
        os << "]" << endl;;
    }
    return os;
}

class Complex {
public:
    double a, b;
    Complex(int _a = 0, int _b = 0) {
        a = _a;
        b = _b;
    }
    Complex operator+(const Complex& other) {
        return Complex(a + other.a, b + other.b);
    }
    Complex operator-(const Complex& other) {
        return Complex(a - other.a, b - other.b);
    }
    Complex operator*(const Complex& other) {
        return Complex(a * other.a - b * other.b, a * other.b + b * other.a);
    }
    Complex operator/(const Complex& other) {
        double del = pow(other.a, 2) + pow(other.b, 2);
        if (del == 0) {
            throw(runtime_error("На ноль делить нельзя"));
        }
        return Complex((a * other.a + b * other.b)/del, (b * other.a - a * other.b)/del);
    }
    bool operator==(const Complex& other) {
        return (a == other.a && b == other.b);
    }
};

int main()
{
    try {

    //Integer a(2), b(5);
    //cout << (a++).i;
    //cout << (a).i;

    //Vector2D vec(1, 2);
    //cout << vec;
    //Matrix matr(2, 4);
    //for (int i = 0; i < matr.row; i++) {
    //    for (int j = 0; j < matr.column; j++) {
    //        matr.value[i][j] = j;
    //    }
    //}
    //Matrix matt(4, 2);
    //for (int i = 0; i < matt.row; i++) {
    //    for (int j = 0; j < matt.column; j++) {
    //        matt.value[i][j] = j;
    //    }
    //}
    //    cout << (matr * matt);

    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

