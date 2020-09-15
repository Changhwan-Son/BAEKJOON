/*
1196번 그림 
BFS

문제
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

입력
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 
두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 
단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

예제 입력 1 
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1

예제 출력 1 
4
9
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	int m;			// 가로
	int n;			// 세로
	int max = 0;
	int num = 0;
	
	bool visit[501][501];
	int board[501][501];
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	
	
	
	// 세로, 가로, 그림 정보 입력받기  
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0 ; j < m; j++)
			cin >> board[i][j];
	
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			if(visit[i][j] == 1 || board[i][j] == 0)
				continue;
			
			num++;
			visit[i][j] = 1;
			int count = 0;
			
			queue<pair<int, int>> visitQueue;
			visitQueue.push({i,j});
			
			while(!visitQueue.empty()){
				pair<int, int> cur = visitQueue.front();
				visitQueue.pop();
				count++;
				
				for(int k = 0 ; k < 4; k++){
					int px = cur.first + dx[k];
					int py = cur.second + dy[k];
					if(px < 0 || px >= n || py < 0 || py > m)
						continue;
					if(board[px][py] != 1 || visit[px][py] == 1)
						continue;

					visitQueue.push({px, py});
					visit[px][py] = 1;
				}
			}
			
			if (count > max)
				max = count;
			
		}
	}
	
	cout << num << "\n" << max;
}