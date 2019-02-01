#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 210
#define M 26

char s[N][N];
int a[N], b[N];
ll A[N][N], B[N][N], temp[N][N];
ll inf = 4E18;

//-------------------- Aho-Corasick Automation --------------------//
int tr[N][M], au[N][M], f[N], nx = 1;

void AddString(char *s, int a){
	int i, j, k;

	for(k = 0, i = 0; s[i] != '\0'; i++){
		j = s[i] - 'a';

		if(tr[k][j] == 0)
			tr[k][j] = nx++;

		k = tr[k][j];
	}

	b[k] += a;
}

void ComputeFailure(){
	queue<int> q;

	q.push(0);

	while(!q.empty()){
		int v = q.front();
		q.pop();
	
		if(f[v] != v)
			b[v] += b[f[v]];
		
		for(int i = 0; i < M; i++){
			int u = tr[v][i];
			if(u){
				au[v][i] = u;
				if(v)
					f[u] = au[f[v]][i];
				q.push(u);
			}
			else
				au[v][i] = au[f[v]][i];
		}
	}
}
//-------------------- Aho-Corasick Automation Ends --------------------//

void MatMul(ll A[][N], ll B[][N], ll C[][N], int n){
	int i, j, k;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			temp[i][j] = -inf;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				temp[i][j] = max(temp[i][j], A[i][k] + B[k][j]);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			C[i][j] = temp[i][j];
}

void MatExp(ll A[][N], ll B[][N], int m, ll n){
	while(n > 0){
		if(n % 2 == 1)
			MatMul(A, B, B, m);

		MatMul(A, A, A, m);
		n /= 2;
	}
}

int main(){
	int n, m, i, j, k, x, y, z;
	ll l, ans;

	cin >> n >> l;

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++)
		scanf("%s", s[i]);

	for(i = 1; i <= n; i++)
		AddString(s[i], a[i]);

	ComputeFailure();
	m = nx;

	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
			A[i][j] = -inf;

	for(i = 0; i < m; i++)
		for(j = 0; j < M; j++){
			k = au[i][j];
			A[i][k] = b[k];
		}

	MatExp(A, B, m, l);

	for(j = 0, ans = -inf; j < m; j++)
		ans = max(ans, B[0][j]);

	cout << ans << '\n';

	return 0;
}
