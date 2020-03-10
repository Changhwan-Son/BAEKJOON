/*
그리디 알고리즘
1946번 신입사원 

문제
언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.

그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.

출력
각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.
*/




/*
서류, 면접 점수 다 돌면서 비교했을 때 시간초과가 떠서 다른 방법 고안하려고 했음.

서류 점수 순으로 정렬하고 면접 점수만 위에서 부터 최소값 매기며 비교하는 방법 사용.
*/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
struct member {
	int rank1;
	int rank2;
};

bool compare(member a, member b) {
	return a.rank1 < b.rank1;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int test = 0;
	int member_count = 0;
	int rank1 = 0;
	int rank2 = 0;
	int count = 1;

	cin >> test;
	int *result = new int[test];
	for (int i = 0; i < test; i++) {
		vector<member> v;

		
		cin >> member_count;


			
		// 지원자 입력
		for (int j = 0; j < member_count; j++) {
			member m1;
			cin >> m1.rank1 >> m1.rank2;
			v.push_back(m1);
		}
		
		sort(v.begin(), v.end(), compare);

		int min = v[0].rank2;

		for (int j = 1; j < member_count; j++) {
			if (v[j].rank2 < min) {
				count++;
				min = v[j].rank2;
			}
				
		}
		
		v.clear();
		result[i] = count;
		count = 1;
	}

	for (int i = 0; i < test; i++) {
		cout << result[i] << "\n";
	}
	
	

	return 0;
}