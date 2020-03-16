/*문제 설명

한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
- numbers는 길이 1 이상 7 이하인 문자열입니다
- numbers는 0~9까지 숫자만으로 이루어져 있습니다.
- 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.


입출력 예
numbers    return
17	3
011	2
 
입출력 예 설명

예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkNumber(int i, string numbers);        // numbers 에서 만들수 있는 수인지 체크

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());       // 큰 수부터 오도록 정렬
    vector<bool> temp(stoi(numbers)+1);                         // default로 false로 초기화 
    for (int i = 2; i <= stoi(numbers); i++) {
        if (temp[i]==false && checkNumber(i,numbers)) {
            answer++;
        }
        if (temp[i] == false) {
            for (int j = i; j <= stoi(numbers); j += i) {
                temp[j] = true;
            }
        }
    }
    
    return answer;
}
 
bool checkNumber(int i,string numbers) {
    bool flag = false;
    vector<bool> visit(numbers.length());
    while (i != 0) {
        flag = false;
        int temp = i % 10;
        for (int j = 0; j <= numbers.length(); j++) {
            if (temp == numbers[j]-'0'&&visit[j]==0) {
                flag = true;
                visit[j] = 1;
                break;
            }
        }
        if (flag == false)
            return false;
 
        i /= 10;
    }
 
    return true;
}