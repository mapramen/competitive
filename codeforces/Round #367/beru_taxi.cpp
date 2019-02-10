#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, a, b, i, j;
	double v, ans = 400, t;

	cin >> a >> b;

	cin >> n;

	while(n--){
		cin >> i >> j >> v;
		i -= a;
		j -= b;
		t = sqrt(i*i + j*j) / v;
		ans = min(ans, t);
	}

	printf("%.15lf\n", ans);

	return 0;
}
