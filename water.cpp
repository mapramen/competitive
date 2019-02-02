#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 102

int a[N][N], h[N][N], inf;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	int t, n, m, i, j, k, x, y, z, ans;

	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &m);

		for(i = 1, inf = 0; i <= n; i++)
			for(j = 1; j <= m; j++){
				scanf("%d", &a[i][j]);
				inf = max(inf, a[i][j]);
			}

		vector< vector< pii > > v(inf + 1);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(i == 1 || i == n || j == 1 || j == m){
					h[i][j] = a[i][j];
					v[a[i][j]].PB(MP(i,j));
				}
				else{
					h[i][j] = inf;
				}

		queue< pii > q;

		for(k = inf; k > 0; k--)
			for(x = 0; x < v[k].size(); x++)
				q.push(v[k][x]);

		while(!q.empty()){
			i = q.front().first;
			j = q.front().second;
			q.pop();

			if(i == 1 || i == n || j == 1 || j == m)
				continue;

			z = inf;

			for(k = 0; k < 4; k++){
				x = i + dx[k];
				y = j + dy[k];
				z = min(z, h[x][y]);
			}

			z = max(z, a[i][j]);

			if(z < h[i][j]){
				h[i][j] = z;
				q.push(MP(i,j));
			}
		}

		for(i = 1; i <= n; printf("\n"), i++)
			for(j = 1; j <= m; j++)
				printf("%d ", h[i][j]);

		for(i = 1, ans = 0; i <= n; i++)
			for(j = 1; j <= m; j++)
				ans += (h[i][j] - a[i][j]);

		printf("%d\n\n", ans);
	}

	return 0;
}
