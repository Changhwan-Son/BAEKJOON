#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502] = {...};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios:sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    vis[0][0] = 1;
    Q.push({0, 0});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            // 범위 내에 들어오는지 검사 
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            
            // 이미 방문했는지, 파란 칸인지 검사 
            if(vis[nx][ny] || board[nw][ny] != 1)
                continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

/*

유의사항 (자주 실수하는 경우)
1. 시작점에 방문했다는 표시를 남기지 않는다. 
- 시작점을 두 번 방문할 수 있음 

2. 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때 방문했다는 표시를 남겼다. 
- 같은 칸이 큐에 여러번 들어갈 수 있음 

3. 이웃한 원소가 범위를 벗어났는지에 대한 쳌를 잘못했다. 


*/