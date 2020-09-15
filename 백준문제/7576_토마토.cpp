#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    int box[1001][1001];
    int vis[1001][1001];

    int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};

    queue<pair<int, int> >Q;

    cin >> M >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> box[i][j];

            if(box[i][j] == 1)
                Q.push({i,j});

            if(box[i][j] == 0)
                vis[i][j] = -1;
        }
    }

    

    while(!Q.empty()){
        pair<int, int> cur = Q.front();  Q.pop();


        for(int dir = 0 ; dir < 4; dir++){
            int px = cur.first + dx[dir];
			int py = cur.second + dy[dir];

			if(px < 0 || px >= N || py < 0 || py>= M)
				continue;

			if(vis[px][py] >= 0)
				continue;

            vis[px][py] = vis[cur.first][cur.second] + 1;
			Q.push({px, py});
			
        }
    }

    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M; j++){
            if(vis[i][j] == -1){
                cout << -1;
                return 0;
            }

            ans = max(ans, vis[i][j]);
        }
    }

    cout << ans;








}
