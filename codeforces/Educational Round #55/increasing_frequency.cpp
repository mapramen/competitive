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
#define PB push_back
#define MP make_pair
#define N 500002

int a[N], suffixAns[N], dp[N];

int main(){
	int n, m;

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}

	for(int i = n, c = 0; i > 0; --i){
		int k = a[i];
		suffixAns[i] = 1 + max(c, dp[k]);
		dp[k] = max(dp[k], suffixAns[i]);
		c += (k == m);
	}

	int ans = 0;
	for(int i = 1, c = 0; i <= n + 1; ++i){
		ans = max(ans, c + suffixAns[i]);
		c += (a[i] == m);
	}

	printf("%d\n", ans);

	return 0;
}