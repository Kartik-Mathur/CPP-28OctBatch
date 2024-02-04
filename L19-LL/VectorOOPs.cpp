#include <iostream>
using namespace std;

class Vector {
private:
	int *a;
	int ms;
	int cs;
public:
	Vector(int s = 2) {
		a = new int[s];
		ms = s; // maximum values that we can insert inside vector
		cs = 0; // currently kitni values user ne insert kari
	}

	void push_back(int d) {
		if (cs == ms) {
			// size of double karna padega
			int* newA = new int[2 * ms];
			for (int i = 0; i < ms; ++i)
			{
				newA[i] = a[i];
			}
			ms *= 2;
			delete []a;
			a = newA;
		}
		a[cs] = d;
		cs++;
	}

	void pop_back() {
		if (cs > 0) {
			cs--;
		}
	}

	int size() {
		return cs;
	}

	int capacity() {
		return ms;
	}

	int operator[](int indx) {
		return a[indx];
	}

	void print() {
		for (int i = 0; i < cs; ++i)
		{
			cout << a[i] << " ";
		}
	}

};

int main() {


	Vector v;

	for (int i = 1; i <= 5; ++i)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;
	v.print();
	cout << endl;

	return 0;
}

















