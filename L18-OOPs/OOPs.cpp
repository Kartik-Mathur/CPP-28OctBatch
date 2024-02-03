#include <iostream>
using namespace std;

// ----------------------------- BLUEPRINT -----------------------------
class Car {
private:
	int price;

public:
	char* name;
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


	// Operator Overloading
	void operator+=(Car &X) {
		price += X.price;
		model += X.model;
		seats += X.seats;
		char *newName = new char[strlen(name) + strlen(X.name) + 1];
		strcpy(newName, name);
		strcat(newName, X.name);
		delete []name;
		name = newName;
	}


	// GETTER AND SETTER
	void setPrice(int p) {
		if (p >= 100 and p <= 500) price = p;
		else price = 350;
	}

	int getPrice() {
		return price;
	}
};
// ----------------------------- BLUEPRINT -----------------------------

int main() {

	Car a;
	// strcpy(a.name, "BMW");
	char name[] = "BMW";
	a.setName(name);
	// a.price = 10;
	a.setPrice(-1000);
	cout << a.getPrice() << endl;
	a.model = 2020;
	a.seats = 5;

	Car b = a;
	// Car b("Maruti", 100, 2014, 5); // This will call parameterised constructor
	Car c(a);
	Car d = a;

	c.name[0] = 'T';

	a += b;
	a.print();
	b.print();
	c.print();
	d.print();







	return 0;
}
















