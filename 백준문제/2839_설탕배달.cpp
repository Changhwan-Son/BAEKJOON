#include <iostream>
using namespace std;

int main() {
	long long A;
	long long B;
	long long C;
	int k = 0;

	cin >> A >> B >> C;

	if (C <= B) {
		cout << -1 << endl;
		return 0;
	}

	k = A / (C - B) + 1;


	cout << k << endl;

	return 0;
}