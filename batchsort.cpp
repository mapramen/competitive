#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 21

int A[N][N], B[N][N], P[N];

void Fill_Matrix(int n, int m){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			B[i][j] = A[i][P[j]];
}

bool Check_Row(int i, int m){
	int ans = 0;

	for(int j = 1; j <= m; j++)
		ans += (B[i][j] != j);

	return (ans <= 2);
}

bool Check_Matrix(int n, int m){
	bool ans = 1;

	for(int i = 1; i <= n; i++)
		ans &= Check_Row(i, m);

	return ans;
}

int main(){
	int n, m, i, j, k;

	cin >> n >> m;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			cin >> A[i][j];

	for(i = 1; i <= m; i++)
		P[i] = i;

	for(i = 1; i <= m; i++){
		for(j = i; j <= m; j++){
			swap(P[i], P[j]);
			Fill_Matrix(n, m);
			if(Check_Matrix(n, m)){
				printf("YES\n");
				return 0;
			}
			swap(P[i], P[j]);
		}
	}

	printf("NO\n");

	return 0;
}
