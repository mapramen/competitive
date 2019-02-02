#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

char s[N + 1][N + 1];
bool visited[N][N];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
	int n, m, k, i, j, l, x, y, z, ans;
	priority_queue< piii, vector< piii >, greater< piii > > q;

	scanf("%d%d%d", &n, &m, &k);

	for(i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);

	for(i = 2; i < n; i++){
		for(j = 2; j < m; j++){
			if(s[i][j] == '*' || visited[i][j] == 1)
				continue;

			queue< pii > p;

			z = 0;
			p.push(MP(i,j));

			while(!p.empty()){
				x = p.front().first;
				y = p.front().second;
				p.pop();

				if(x < 0 || x > n || y < 0 || y > m || s[x][y] == '*' || visited[x][y] == 1)
					continue;
				
				visited[x][y] = 1;

				if(x == 1 || x == n || y == 1 || y == m)
					z += n*m;
				else
					z++;

				for(l = 0; l < 4; l++)
					p.push(MP(x + dx[l], y + dy[l]));
			}

			if(z < n*m)
				q.push(MP(z, MP(i,j)));
		}
	}

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			visited[i][j] = 0;

	ans = 0;

	while(q.size() > k){
		ans += q.top().first;
		queue< pii > p;
		p.push(q.top().second);
		q.pop();

		while(!p.empty()){
			x = p.front().first;
			y = p.front().second;
			p.pop();

			if(s[x][y] == '*' || visited[x][y] == 1)
				continue;
			
			s[x][y] = '*';
			visited[x][y] = 1;

			for(l = 0; l < 4; l++)
				p.push(MP(x + dx[l], y + dy[l]));
		}
	}

	printf("%d\n", ans);

	for(i = 1; i <= n; i++)
		printf("%s\n", s[i] + 1);

	return 0;
}
