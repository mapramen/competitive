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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, d, x, y, ans = INT_MAX;
		cin >> n >> x >> y >> d;
		
		if(abs(x - y) % d == 0){
			ans = abs(x - y) / d;
		}

		if((y - 1) % d == 0){
			ans = min(ans, (x + d - 2) / d + (y - 1) / d);
		}

		if((y - n) % d == 0){
			ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
		}

		if(ans == INT_MAX){
			ans = -1;
		}

		cout << ans << '\n';
	}
	return 0;
}