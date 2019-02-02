#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int n, m;
double v1, v2, l, eps = 1E-7;

bool check(double t){
	double posM = 0, posB = 0, t1, t2, t3;

	// cout << t << ' ';

	if(v1 * t >= l)
		return 1;

	for(int i = 0; i < m && t >= 0; i++){
		t1 = abs(posB - posM) / (v2 + v1);
		t2 = (l - posM - v1 * t) / (v2 - v1);
		
		t -= (t1 + t2);
		posM += (v1 * (t1 + t2));
		posB += (v2 * (t2 - t1));
	}

	// cout << t << '\n';

	if(t >= 0)
		return 1;
	else
		return 0;
}

double BinarySearch(){
	double x = 0, y = l / v1, z = y, mid, niter = (int) (log(l / eps) / log(2)) + 1;

	while(niter--){
		mid = x + (y - x) / 2;

		if(check(mid)){
			z = mid;
			y = mid - eps;
		}
		else
			x = mid + eps;
	}

	return z;
}

int main(){
	double ans;

	cin >> n >> l >> v1 >> v2 >> m;

	m = (n + m - 1) / m;

	ans = BinarySearch();

	printf("%.15lf\n", ans);

	return 0;
}
