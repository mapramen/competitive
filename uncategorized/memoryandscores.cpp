#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 210000
#define MOD 1000000007
#define base_offset 100001

int A[N], B[N], temp[N];

void Compute_Next_Turn(int a[], int n, int k){
	for(int i = 1; i <= n; i++)
		a[i] = (a[i] + a[i - 1]) % MOD;

	for(int i = 1; i <= n; i++){
		int x = max(i - k, 1);
		int y = min(i + k, n);
		temp[i] = (a[y] + MOD - a[x - 1]) % MOD;
	}

	for(int i = 1; i <= n; i++)
		a[i] = temp[i];
}

int main(){
	int n, m, i, j, k, a, b, ans;

	scanf("%d%d%d%d", &a, &b, &k, &n);

	m = max(a,b) + n * k + base_offset;
	a += base_offset;
	b += base_offset;

	A[a] = 1;
	B[b] = 1;

	for(i = 1; i <= n; i++){
		Compute_Next_Turn(A, m, k);
		Compute_Next_Turn(B, m, k);
	}

	for(i = 1, ans = 0; i <= m; i++){
		ans = (ans + 1ll * A[i] * B[i - 1]) % MOD;
		B[i] = (B[i] + B[i - 1]) % MOD;
	}

	printf("%d\n", ans);

	return 0;
}
