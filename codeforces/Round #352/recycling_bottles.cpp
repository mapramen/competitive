#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000
#define inf 2E9

double max(double a, double b){
	if(a > b)
		return a;
	else
		return b;
}

double dis(int a, int b, int c, int d){
	return sqrt(1LL*(a - c)*(a - c) + 1LL*(b - d)*(b - d));
}

int main(){
	int n, ax, ay, bx, by, tx, ty, i, x, y, m1, m2, n1, n2;
	double ans = 0, ansx, d, d1, d2, max1, max2, nax1, nax2;

	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);

	scanf("%d", &n);

	max1 = max2 = nax1 = nax2 = -inf;

	for(i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		
		d = dis(x,y,tx,ty);
		ans += 2*d;
		
		d1 = d - dis(x,y,ax,ay);
		d2 = d - dis(x,y,bx,by);

		if(d1 >= max1){
			max2 = max1;
			m2 = m1;
			max1 = d1;
			m1 = i;
		}
		else if(d1 > max2){
			max2 = d1;
			m2 = i;
		}

		if(d2 >= nax1){
			nax2 = nax1;
			n2 = n1;
			nax1 = d2;
			n1 = i;
		}
		else if(d2 > nax2){
			nax2 = d2;
			n2 = i;
		}
	}

	if(n == 1)
		ans -= max(max1, nax1);
	else{
		if(m1 == n1)
			ansx = max(max1 + nax2, max2 + nax1);
		else
			ansx = max1 + nax1;

		ansx = max(ansx, max(max1, nax1));

		ans -= ansx;
	}

	printf("%.15lf\n", ans);

	return 0;
}
