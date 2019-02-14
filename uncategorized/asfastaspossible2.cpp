#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, m;
	double v1, v2, k, l, ans;

	cin >> n >> l >> v1 >> v2 >> m;

	n = (n + m - 1) / m;
	k = v2 / v1;

	ans = (((2*n - 1)*k + 1) / ((2*n - 1) + k)) * (l / v2);

	printf("%.15lf\n", ans);

	return 0;
}
