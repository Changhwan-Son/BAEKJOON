/*
그리디 알고리즘 
11047번 동전 0

문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
*/


#include <iostream>

using namespace std;

int main()
{
	int coin_type = 0;			// 동전 종류 수 
	int target_price = 0;		// 목표 가치 합 
	int sum_count = 0;			// 동전 개수 

	// 동전 종류, 목표 가치 입력합니다. 
	cin >> coin_type >> target_price;

	// 동전 가치 배열 생성합니다. 
	int * coins = new int[coin_type];

	// 동전 가치 입력 
	for (int i = 0; i < coin_type; i++) {
		cin >> coins[i];
	}

	for (int i = 1; i <= coin_type; i++) {
		while (target_price / coins[coin_type - i] != 0) {
			target_price -= coins[coin_type - i];
			sum_count++;
		}
		
	}

	cout << sum_count ;
}