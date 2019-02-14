#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ll a, min_x = 2E9, max_x = 0, sum_x = 0;

	for(int i = 1; i <= 5; i++){
		scanf("%lld", &a);
		min_x = min(a, min_x);
		max_x = max(a, max_x);
		sum_x += a;
	}

	printf("%lld %lld\n", sum_x - max_x, sum_x - min_x);

	return 0;
}
