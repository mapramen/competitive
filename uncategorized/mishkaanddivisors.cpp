#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair< int,ll >
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair
#define N 1002
#define M 6720

pil dp[N][M];
pii parent[N][M];
ll a[N];
int m;
vector< ll > divisors;

void PreProcess(ll k, int n){
	for(ll i = 1; i*i <= k; i++)
		if(k % i == 0){
			divisors.PB(i);

			if(i * i != k)
				divisors.PB(k / i);
		}

	m = divisors.size();

	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j < m; j++)
			dp[i][j].first = n + 1;

	sort(divisors.begin(), divisors.end());
	m--;
}

int GetCompressed(ll k){
	return lower_bound(divisors.begin(), divisors.end(), k) - divisors.begin();
}

ll GetOriginal(int k){
	return divisors[k];
}

ll GCD(ll b, ll c){
	if(c == 0)
		return b;
	else
		return GCD(c, b % c);
}

int main(){
	int n, i, j, k;
	ll K, x, y, z;

	cin >> n >> K;

	for(i = 1; i <= n; i++)
		cin >> a[i];

	if(K == 1){
		printf("1\n");

		for(i = 1, j = 1; i <= n; i++)
			if(a[i] < a[j]) j = i;

		printf("%d\n", j);

		return 0;
	}

	PreProcess(K, n);

	j = GetCompressed(K);
	dp[1][j].first = 0;

	for(i = 1; i <= n; i++){
		if(GCD(a[i],K) != 1){
			for(j = 0; j <= m; j++){
				x = GetOriginal(j);
				y = GCD(a[i], x);

				if(y == 1)
					continue;
				
				k = GetCompressed(x / y);

				if((dp[i][j].first + 1 < dp[i + 1][k].first) || (dp[i][j].first + 1 == dp[i + 1][k].first && dp[i][j].second + a[i] < dp[i + 1][k].second)){
					dp[i + 1][k].first = dp[i][j].first + 1;
					dp[i + 1][k].second = dp[i][j].second + a[i];
					parent[i + 1][k].first = i;
					parent[i + 1][k].second = j;
				}
			}
		}

		for(j = 0; j <= m; j++){
			if((dp[i][j].first < dp[i + 1][j].first) || (dp[i][j].first == dp[i + 1][j].first && dp[i][j].second < dp[i + 1][j].second)){
				dp[i + 1][j].first = dp[i][j].first;
				dp[i + 1][j].second = dp[i][j].second;
				parent[i + 1][j].first = parent[i][j].first;
				parent[i + 1][j].second = parent[i][j].second;
			}
		}
	}

	if(dp[n + 1][0].first > n)
		printf("-1\n");
	else{
		printf("%d\n", dp[n + 1][0].first);
		
		i = parent[n + 1][0].first, j = parent[n + 1][0].second;

		while(i != 0){
			printf("%d ", i);
			k = parent[i][j].second;
			i = parent[i][j].first;
			j = k;
		}

		printf("\n");
	}

	return 0;
}