#include <iostream>
using namespace std;

class hashmap {
public:
	int hashFunction(string key) {
		int ans = 0;
		int x = 1;
		for (int i = 0; i < key.size(); ++i)
		{
			ans += x * key[i];
			x *= 27;
		}
		return ans % size;
	}
};

int main() {


	return 0;
}
















