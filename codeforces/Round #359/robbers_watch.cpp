#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 7

int n, m, N, M, K, a[B], cnt = 0;
vector<int> s;

void fun(int i){
	if(i == s.size()){
		int hr = 0;
		int mn = 0;

		for(int j = 0; j < N; j++)
			hr = 7*hr + s[j];

		for(int j = N; j < K; j++)
			mn = 7*mn + s[j];

		if(hr < n && mn < m)
			cnt++;
	}
	else{
		for(int j = 0; j < B; j++){
			if(a[j] == 1){
				s[i] = j;
				a[j] = 0;
				fun(i + 1);
				a[j] = 1;
			}
		}
	}
}

int main(){
	int i, j, k, x, y, z;

	scanf("%d%d", &n, &m);

	x = n;
	y = m;

	for(N = 1, x = n - 1; x > 6; N++, x /= B);

	for(M = 1, x = m - 1; x > 6; M++, x /= B);

	K = N + M;

	if(K > 7){
		printf("0\n");
		return 0;
	}

	s.resize(K);

	for(i = 0; i < B; i++)
		a[i] = 1;

	fun(0);

	printf("%d\n", cnt);

	return 0;
}