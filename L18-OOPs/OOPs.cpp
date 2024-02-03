#include <iostream>
using namespace std;

// ----------------------------- BLUEPRINT -----------------------------
class Car {
public:
	char* name;
	int price;
	int model;
	int seats;

	Car() {
		name = NULL;
		cout << "Inside Default Constructor\n";
	}

	Car(char* n, int p, int m, int s) {
		cout << "Inside Parameterised Constructor\n";
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		price = p;
		model = m;
		seats = s;
	}

	Car(Car &X) {
		cout << "Inside Copy Constructor\n";
		name = new char[strlen(X.name) + 1];
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

	~Car() {
		cout << "Deleting Object " << name << endl;
	}

	void setName(char* n) {
		if (name != NULL) {
			// Agar name kisi ko point kar rha h, toh usse delete kardo
			// kyunki naya name n[] mei hai vo assign krna hai
			delete []name;
			name = NULL;
		}

		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
};
// ----------------------------- BLUEPRINT -----------------------------

int main() {

	Car a;
	// strcpy(a.name, "BMW");
	a.setName("BMW");
	a.price = 10;
	a.model = 2020;
	a.seats = 5;

	Car b("Maruti", 100, 2014, 5); // This will call parameterised constructor
	b.setName("Tata");
	Car c(a);

	a.print();
	b.print();
	c.print();





	return 0;
}
















