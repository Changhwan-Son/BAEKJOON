#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int num;
	int *data = new int[1000000];

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> data[i];
	}

	std::sort(data, data + num);
	for (int i = 0; i < num; i++) {
		cout << data[i] << "\n";
	}


	return 0;
}
