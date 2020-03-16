/*문제 설명

숫자 야구 게임이란 2명이 서로가 생각한 숫자를 맞추는 게임입니다. 게임해보기
각자 서로 다른 1~9까지 3자리 임의의 숫자를 정한 뒤 서로에게 3자리의 숫자를 불러서 결과를 확인합니다. 그리고 그 결과를 토대로 상대가 정한 숫자를 예상한 뒤 맞힙니다.
* 숫자는 맞지만, 위치가 틀렸을 때는 볼 * 숫자와 위치가 모두 맞을 때는 스트라이크 * 숫자와 위치가 모두 틀렸을 때는 아웃
예를 들어, 아래의 경우가 있으면
A : 123
B : 1스트라이크 1볼.
A : 356
B : 1스트라이크 0볼.
A : 327
B : 2스트라이크 0볼.
A : 489
B : 0스트라이크 1볼.
이때 가능한 답은 324와 328 두 가지입니다.
질문한 세 자리의 수, 스트라이크의 수, 볼의 수를 담은 2차원 배열 baseball이 매개변수로 주어질 때, 가능한 답의 개수를 return 하도록 solution 함수를 작성해주세요.

 
제한사항
- 질문의 수는 1 이상 100 이하의 자연수입니다.
- baseball의 각 행은 [세 자리의 수, 스트라이크의 수, 볼의 수] 를 담고 있습니다.

 
입출력 예
baseball                                             return
[[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]	2
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int strike(int num1, int num2){
    int count = 0;
    while(num1 > 0){
        if(num1 % 10 == num2 % 10){
            count++;
        }
        num1 /= 10;
        num2 /= 10;
    }
    return count;
}

int ball(int num1, int num2){
    int count = 0;
    
    int arr1[3];
    int arr2[3];
    for(int i = 0 ; i < 3; i++){
        arr1[i] = num1 % 10;
        arr2[i] = num2 % 10;
        
        num1 /= 10;
        num2 /= 10;
    }
    
    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr1[i] == arr2[j] && i != j)
                count++;
        }
    }
    
    return count;
}


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    
    vector<bool> arr(1000, true);
    
    int s = 0;
    int b = 0;
   
    
    for(int i = 123 ; i < 987; i++){
        string str = to_string(i);
        if(str[1] == '0' || str[2] == '0' || str[0] == str[1] || str[1] == str[2] || str[2] == str[0])
            continue;
        
        for(int j = 0; j < baseball.size(); j++){
            if(strike(i, baseball[j][0]) == baseball[j][1] && ball(i, baseball[j][0]) == baseball[j][2]){
               
            }else{
                break;
            }
            
            if(j == baseball.size() - 1)
                answer++;
        }
    }
    
   
    return answer;
}