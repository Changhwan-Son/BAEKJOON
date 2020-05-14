/*
9. 모두의 약수 (제한시간 1초)

자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하
세요. 만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4
개) 와 같이 각 숫자의 약수의 개수가 구해집니다.
출력은 다음과 같이 1부터 차례대로 약수의 개수만 출력하면 됩니다.
1 2 2 3 2 4 2 4 와 같이 출력한다.

▣ 입력설명
첫 번째 줄에 자연수 N(5<=N<=50,000)가 주어진다.

▣ 출력설명
첫 번째 줄에 1부터 N까지 약수의 개수를 순서대로 출력한다.

*/


#include <iostream>
//#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	



	
	// 처음 작성한 코드
	// 이건 Time limit 나는 경우가 생김 
	/*
	int num;

	cin >> num;
	int count = 0;

	for (int i = 1; i <= num; i++) {
		count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				count++;
		}

		printf("%d ", count);
	}
	*/

	

	/*
	num 크기 만큼의 배열에 0 으로 초기화
	1부터 자신을 약수로 가지는 수 인덱스로 들어가 cnt 값 + 1
	
	*/
	int num;
	cin >> num;

	int * arr = new int[num + 1]{ 0, };

	for (int i = 1; i <= num; i++) {
		for (int j = i; j <= num; j += i) {
			if (j % i == 0) {
				arr[j] += 1;
			}
		}
	}


	for (int i = 1; i <= num; i++) {
		cout << arr[i] << " ";
	}
	return 0; 

}
