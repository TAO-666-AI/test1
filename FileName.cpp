#include <iostream>
using namespace std;
class Vector {
private:
	int x, y;
public:
	Vector(int a, int b);
	void display();
	int getx();
	int gety();
	Vector Add(const Vector& ob2);
	Vector Sub(const Vector& ob2);
	int Mult(const Vector& ob2);
};
Vector::Vector(int a, int b) :x(a), y(b) {}

void Vector::display(){
	cout << "(" << x << "," << y << ")" << endl;
}
int Vector::getx() {
	return x;
}
int Vector::gety() {
	return y;
}
Vector Vector::Add(const Vector& ob2) {
	return Vector(x + ob2.x, y + ob2.y);
}
Vector Vector::Sub(const Vector& ob2) {
	return Vector(x - ob2.x, y - ob2.y);
}
int Vector::Mult(const Vector& ob2) {
	return x * ob2.x + y * ob2.y;
}
int main() {
	Vector v1(1, 2);
	Vector v2(3, 4);
	
	cout << "Vector v1:";
	v1.display();
	
	cout << "Vector v2:";
	v2.display();
	
	Vector Add_ = v1.Add(v2);
	cout << "矢量相加得：";
	Add_.display();
	
	Vector Sub_ = v1.Sub(v2);
	cout << "矢量相减得：";
	Sub_.display();
	
	int Mult_ = v1.Mult(v2);
	cout << "矢量相乘得：";
	cout << Mult_ << endl;
	return 0;
}