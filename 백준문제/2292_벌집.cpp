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


/* 간단하게 코드를 맞출 수 있었는데 복잡하게 짠 듯
int main(void)
{
	int N;
	cin >> N;
	int cur = 1;
	int result = 1;
	int inc = 6;

	while (1)
	{
		if (N <= cur)
			break;
		result++;
		cur += inc;
		inc += 6;
	}

	cout << result << "\n";
	system("pause");
	return 0;

}

// 뒷 번호 기준으로 맞춘 코드 
*/
