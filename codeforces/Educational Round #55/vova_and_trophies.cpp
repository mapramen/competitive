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
#define N 100001

char s[N];

int GoldCount(int n){
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (s[i] == 'G');
	}
	return ans;
}

int MaxConsecutiveGoldCount(int n){
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'S'){
			continue;
		}
		int ansx = 0;
		for( ; i < n && s[i] == 'G'; ++i){
			++ansx;
		}
		ans = max(ans, ansx);
	}
	return ans;
}

int main(){
	int n;

	scanf("%d%s", &n, s);

	int m = GoldCount(n), l = MaxConsecutiveGoldCount(n);
	int ans = l + (l != m);

	for(int i = 0; i < n; ++i){
		if(!(s[i] == 'S' && i > 0 && i < n - 1 && s[i - 1] == 'G' && s[i + 1] == 'G')){
			continue;
		}

		int j = i - 1, k = i + 1;
		for( ; j > -1 && s[j] == 'G'; --j);
		for( ; k < n && s[k] == 'G'; ++k);

		int ansx = k - j - 1;
		ans = max(ans, ansx - (ansx > m));
	}

	printf("%d\n", ans);

	return 0;
}