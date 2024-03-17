#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {

	// unordered_map<string, int> h;
	map<string, int> h;
	// Insertion
	h.insert({"Mango", 100}); // hashmap ke andar hum pair ko insert krte hai
	// key value ke
	h.insert({"Kiwi", 50});
	h.insert({"Watermelon", 80});
	h.insert({"Grapes", 800});
	h.insert(make_pair("Guava", 30));

	h["Pineapple"] = 120;
	h["Apple"] = 150;

	// Read
	// cout << h["Pineapple"] << endl;
	// cout << h["Mango"] << endl;

	// Find
	// if (h.count("mango") == 1) {
	// 	cout << "Mango Price: " << h["mango"] << endl;
	// }
	// else {
	// 	cout << "Mango Nahi Hai" << endl;
	// }

	// unordered_map<string, int> :: iterator it;

	// auto it = h.find("mango");
	// if (it != h.end()) {
	// 	cout << it->first << "," << it->second << endl;
	// }
	// else {
	// 	cout << "Not Found\n";
	// }

	// cout << p.first << "," << p.second << endl;

	// Printing the hashmap
	// 1. For Each Loop
	// For all the pair<string,int> that belongs to hashmap h
	// for (pair<string, int> x : h) {
	// 	cout << x.first << ", " << x.second << endl;
	// }

	for (auto x : h) {
		cout << x.first << ", " << x.second << endl;
	}
	// 2. Poori Hashtable: Only Available with unordered_map
	// Hashtable ka size: h.bucket_count()
	// for (int i = 0 ; i < h.bucket_count() ; i++) {
	// 	cout << i << "-->";
	// 	for (auto it = h.begin(i) ; it != h.end(i) ; it++) {
	// 		cout << "(" << it->first << ", " << it->second << ")";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}
















