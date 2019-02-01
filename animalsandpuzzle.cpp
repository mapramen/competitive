#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define LOGN 10

int a[N][N], T[LOGN][LOGN][N][N], lg[N];

void Build_2D_Sparse_Table(int n, int m){
	int i, j, k1, k2;

	for(i = 2; i < N; i++)
		lg[i] = 1 + lg[i/2];

	for(i = 1; i <= n; i++)
		for(k2 = 1; (1 << k2) <= m; k2++)
			for(j = 1; j <= m - (1 << k2) + 1; j++)
				T[0][k2][i][j] = max(T[0][k2 - 1][i][j], T[0][k2 - 1][i][j + (1 << (k2 - 1))]);

	for(k1 = 1; (1 << k1) <= n; k1++)
		for(i = 1; i <= n - (1 << k1) + 1; i++)
			for(k2 = 0; (1 << k2) <= m; k2++)
				for(j = 1; j <= m - (1 << k2) + 1; j++)
					T[k1][k2][i][j] = max(T[k1 - 1][k2][i][j], T[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
}

int Query(int x1, int y1, int x2, int y2){
	int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
	x2 = x2 - (1 << k1) + 1;
	y2 = y2 - (1 << k2) + 1;
	return max(max(T[k1][k2][x1][y1],T[k1][k2][x1][y2]),max(T[k1][k2][x2][y1],T[k1][k2][x2][y2]));
}

int Binary_Search(int x1, int y1, int x2, int y2){
	int i = 0, j = min(x2 - x1, y2 - y1) + 1, k = 0, mid;

	while(i <= j){
		mid = i + (j - i) / 2;

		if(Query(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid){
			k = mid;
			i = mid + 1;
		}
		else
			j = mid - 1;
	}

	return k;
}

int main(){
	int n, m, q, i, j, k, x1, y1, x2, y2;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i][j] != 0)
				T[0][0][i][j] = 1 + min(T[0][0][i - 1][j - 1], min(T[0][0][i - 1][j], T[0][0][i][j - 1]));

	Build_2D_Sparse_Table(n,m);

	scanf("%d", &q);

	while(q--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", Binary_Search(x1, y1, x2, y2));
	}

	return 0;
}
