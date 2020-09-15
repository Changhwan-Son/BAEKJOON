/*
2178번 미로탐색
BFS

문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1 
4 6
101111
101010
101011
111011

예제 출력 1 
15


*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	int n;
	int m;
	
	int count = 0;
	int max = 0;
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	string temp[101];
	int miro[101][101];
	int visit[101][101] = {0};
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> temp[i];
	
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			miro[i][j] = temp[i][j];
		}
	}
	
	
	queue<pair<int, int>> visitQueue;
	visitQueue.push({0,0});

	while(!visitQueue.empty()){
		pair<int, int> cur = visitQueue.front();
		visitQueue.pop();


		for(int k = 0 ; k < 4; k++){
			int px = cur.first + dx[k];
			int py = cur.second + dy[k];

			if(px < 0 || px >= n || py < 0 || py>= m)
				continue;

			if(miro[px][py] == '0' || visit[px][py] > 0)
				continue;
			visitQueue.push({px, py});
			visit[px][py] = visit[cur.first][cur.second] + 1;
		}
			
	}
	
	cout << visit[n-1][m-1] + 1;
}