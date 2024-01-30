#include <iostream>
using namespace std;

// ----------------------------- BLUEPRINT -----------------------------
class Car {
public:
	char name[100];
	int price;
	int model;
	int seats;

	void print() {
		cout << "Name   : " << name << endl;
		cout << "Price  : " << price << endl;
		cout << "Model  : " << model << endl;
		cout << "Seats  : " << seats << endl << endl;
	}
};
// ----------------------------- BLUEPRINT -----------------------------


int main() {
	Car a;
	// a.name = "BMW";
	strcpy(a.name, "BMW");
	// a.name[0] = 'B';
	// a.name[1] = 'M';
	// a.name[2] = 'W';
	// a.name[3] = '\0';
	a.price = 100;
	a.model = 2014;
	a.seats = 4;

	Car b;
	strcpy(b.name, "Maruti");
	b.price = 200;
	b.model = 2020;
	b.seats = 10;

	a.print();
	b.print();

	// cout << "Name   : " << a.name << endl;
	// cout << "Price  : " << a.price << endl;
	// cout << "Model  : " << a.model << endl;
	// cout << "Seats  : " << a.seats << endl;

	// Creating a Dynamic Object
	// int* a = new int;
	// float* a = new float;
	Car* c = new Car;

	// strcpy((*c).name, "Audi");
	// (*c).price = 300;
	// (*c).model = 2021;
	// (*c).seats = 2;

	(*c).print();

	delete c;
	c = NULL;



	return 0;
}
















