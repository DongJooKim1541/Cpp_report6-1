#include <iostream>
using namespace std;
#define NAME_LEN 21
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
class NamedCircle :public Circle {
	char* name;
public:
	NamedCircle() {
		name = new char[NAME_LEN];
		name[0] = NULL;
	}
	NamedCircle(int radius, char* name1)
		:Circle(radius)
	{
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
	}
	void setName(char* name1) {
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
	}
	char* getName() {
		return name;
	}
	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
	~NamedCircle() {
		if (name) {
			delete[] name;
			name = NULL;
		}
	}
};
int main() {
	NamedCircle waffle(3,"waffle");
	waffle.show();

	NamedCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		int rad; char name[21];
		cout << i + 1 << ">> ";
		cin >> rad;
		cin.getline(name, 21, '\n');
		pizza[i].setRadius(rad);
		pizza[i].setName(name);
	}
	int temp1 = pizza[0].getRadius();
	int temp2;
	for (int i = 0; i < 5; i++) {
		if (temp1 < pizza[i].getRadius()) {
			temp1 = pizza[i].getRadius();
			temp2 = i;
		}
	}
	cout << "가장 면적이 큰 피자는 " << pizza[temp2].getName() << endl;
	return 0;
}