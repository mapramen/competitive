#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 30
#define M 151
#define T 6
#define B 8

int n, a[N];
bool visited[2 * M][2 * M][B][T][N], s[2 * M][2 * M];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void DFS(int x, int y, int i, int t, int k){
	if(visited[x][y][i][t][k])
		return ;

	visited[x][y][i][t][k] = 1;
	s[x][y] = 1;

	if(t != 1)
		DFS(x + dx[i], y + dy[i], i, t - 1, k);
	else{
		if(k == n)
			return ;
		else{
			int i1 = (i + 1) % 8, i2 = (i + 7) % 8;
			DFS(x + dx[i1], y + dy[i1], i1, a[k], k + 1);
			DFS(x + dx[i2], y + dy[i2], i2, a[k], k + 1);
		}
	}
}

int main(){
	int ans = 0;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	DFS(M, M, 0, a[0], 1);

	for(int i = 0; i < 2 * M; i++)
		for(int j = 0; j < 2 * M; j++)
			ans += s[i][j];

	cout << ans << '\n';

	return 0;
}
