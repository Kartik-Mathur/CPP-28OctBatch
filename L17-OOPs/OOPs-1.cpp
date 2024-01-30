#include <iostream>
using namespace std;

// ----------------------------- BLUEPRINT -----------------------------
class Car {
public:
	char name[100];
	int price;
	int model;
	int seats;

	// 1. Default Constructor: it has same name as class
	Car() {
		cout << "Inside Default Constructor\n";
	}

	// 2. Parameterised Constructor: To assign values to the object
	// that is getting created
	Car(char* n, int p, int m, int s) {
		cout << "Inside Parameterised Constructor\n";
		strcpy(name, n);
		price = p;
		model = m;
		seats = s;
	}
	// 3. Parameterised Constructor: To assign values to the object
	Car(char* n, int p, int s) {
		cout << "Inside Parameterised Constructor - 2\n";
		strcpy(name, n);
		price = p;
		model = 2024;
		seats = s;
	}


	// Copy Constructor: Ek object se doosre object ki copy create krega
	// 1. Car B = A;
	// 2. Car B(A);
	Car(Car &X) {
		cout << "Inside Copy Constructor\n";
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

	Car a; // This will call default constructor
	strcpy(a.name, "BMW");
	a.price = 10;
	a.model = 2020;
	a.seats = 5;

	Car b("Maruti", 100, 2014, 5); // This will call parameterised constructor
	Car d("Audi", 100, 5); // This will call parameterised constructor

	// Car c = a; // This will call copy constructor
	Car c(a); // This will call copy constructor

	a.print();
	b.print();
	c.print();
	d.print();





	return 0;
}
















