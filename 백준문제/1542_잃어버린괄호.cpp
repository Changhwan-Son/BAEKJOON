/*
그리디 알고리즘
1541번 잃어버린 괄호 


문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

출력
첫째 줄에 정답을 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 식 입력
	string N;
	cin >> N;
	

	int sum = 0;				// 정답
	int point = -1;				// 기호 위치
	bool minus = false;			// 마이너스가 한번이라도 등장하며 true
	size_t last = 0;			// 마지막 기호 위치 

	for (size_t i = 0; i < N.length(); i++) {
		if (N[i] == '+' || N[i] == '-') {
			
			if (minus == false) {				// 마이너스 나오기 전이면 다 더해줌
				sum += stoi(N.substr(point + 1, i));
				point = i;
			}
			else { 
				sum -= stoi(N.substr(point + 1, i));
				point = i;
			}
			if (N[i] == '-')
				minus = true;
			last = i;
		}
		
	}

	if (last == 0){		// 기호가 없을 경우 
		cout << N;
	}
	else {
		// 기호가 다 '+' 일 경우 마지막 수 더해줌 
		if(minus == false)
			sum += stoi(N.substr(last + 1));
		else
			sum -= stoi(N.substr(last + 1));

		cout << sum;
	}
	
	

	return 0;
}