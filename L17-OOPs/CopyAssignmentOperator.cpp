#include <iostream>
using namespace std;

// ----------------------------- BLUEPRINT -----------------------------
class Car {
public:
	char name[100];
	int price;
	int model;
	int seats;

	// Copy Assignment Operator:
	// Ek bane huye Object ki value update karna doosre object se
	void operator=(Car &X) {
		cout << "Inside Copy Assignment operator\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
		seats = X.seats;
	}

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
	Car b;

	strcpy(a.name, "BMW");
	a.price = 10;
	a.model = 2020;
	a.seats = 5;

	b = a;

	a.print();
	b.print();




	return 0;
}
















