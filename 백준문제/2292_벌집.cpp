/* ¹úÁý ¹®Á¦ */

#include <iostream>
using namespace std;

int main() {
	long long N;
	int i = 1;

	cin >> N;

	if (N == 1) {
		cout << 1;
		return 0;
	}

	
	if (N > 5)
		N -= 2;
	
	while (1) {
		if (N / (6 * i) == 0) {
			cout << i + 1;
			break;
		}
		N -= 6 * i;
		i++;
	}

	system("pause");
	return 0;
}