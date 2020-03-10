/*
그리디 알고리즘
1120번 문자열 

문제
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B의 길이는 최대 50이고, A의 길이는 B의 길이보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
A와 B의 길이가 같으면서, A와 B의 차이를 최소가 되도록 했을 때, 그 차이를 출력하시오.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int max = 50;

    // 문자열 입력
	string A;
	string B;

	cin >> A >> B;

	// 문자열 길이 다른 경우 짧은 문자열이 긴 문자열 속에서 차이 가장 적은 경우 찾음
	if (A.length() < B.length()) {
		
		for (int i = 0; i <= B.length() - A.length(); i++) {
			int tmp = 0;
			for (int j = 0; j < A.length(); j++) {
				if (A[j] != B[j + i])
					tmp++;
			}
			if (max > tmp)
				max = tmp;
		}
	}
	else {
		int count = 0;
		for (size_t i = 0; i < A.length(); i++)
		{
			if (A[i] != B[i])
				count++;
		}
		max = count;
	}

	cout << max;

	return 0;
}