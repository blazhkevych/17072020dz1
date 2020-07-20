Домашнее задание №21
Встреча №21
Тема : Абстрактный класс и виртуальный деструктор

Задание 1.
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.Создать производные классы : класс линейных уравнений и класс квадратных уравнений.Определить функцию вычисления корней уравнений.

#include <iostream>
using namespace std;

class BaseClass {
public:
	virtual ~BaseClass() = default;
	virtual void getroot() = 0;
};

class Linear : public BaseClass {
	double first;
	double second;
public:
	Linear(double f, double s) : first(f), second(s) { }
	void getroot() {
		double x3;
		x3 = (first && second) ? -second / first : 0;
		cout << x3 << endl;
	}
};

class Quadratic : public BaseClass {
private:
	double A;
	double B;
	double C;
public:
	Quadratic(double a, double b, double c) : A(a), B(b), C(c) {  }
	void getroot() {
		double x1, x2, d;
		if (A == 0.0) {
			cout << "Not root equation !\n";
		}
		d = B * B - 4 * A * C;
		cout << "d = " << d << "\n";
		if (d > 0) {
			x1 = (-B + sqrt(d)) / (2 * A);
			x2 = (-B - sqrt(d)) / (2 * A);
			cout << x1 << x2 << endl;
		}
		else if (d == 0.0) {
			x1 = (-B / (2 * A)); x2 = x1;
			cout << x1;
		}
		else {
			cout << "Equation roots not found\n";
		}
	}
};

int main() {
	BaseClass* line = new Linear(7, -7);
	BaseClass* quad = new Quadratic(4, -4, -8);
	line->getroot();
	quad->getroot();
	delete line;
	delete quad;
}
