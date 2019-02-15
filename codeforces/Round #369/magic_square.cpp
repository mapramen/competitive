#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 502

ll a[N][N];

int main(){
	ll n, i, j, k, r, c, s1, s2;

	cin >> n;

	if(n == 1){
		printf("1\n");
		return 0;
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cin >> a[i][j];

			if(a[i][j] == 0)
				r = i, c = j;
		}
	}

	for(i = 1; i <= n && i == r; i++);

	for(j = 1, s1 = 0, s2 = 0; j <= n; j++){
		s1 += a[i][j];
		s2 += a[r][j];
	}

	if(s2 >= s1){
		printf("-1\n");
		return 0;
	}

	a[r][c] = s1 - s2;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++){
			a[i][n + 1] += a[i][j];
			a[n + 1][j] += a[i][j];

			if(i == j)
				a[n + 1][n + 1] += a[i][j];

			if(i + j == n + 1)
				a[n + 1][0] += a[i][j];
		}

	k = 1;

	for(i = 2; i <= n + 1; i++)
		k = (k & (a[i][n + 1] == a[i - 1][n + 1]));

	for(j = 1; j <= n + 1; j++)
		k = (k & (a[n + 1][j] == a[n + 1][j - 1]));

	if(k == 0){
		printf("-1\n");
	}
	else
		cout << a[r][c] << '\n';

	return 0;
}
