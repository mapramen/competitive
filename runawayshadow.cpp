#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define pii pair<int,int>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair

double PI = 4*atan(1);
vector< pdd > s;

double dis(pdd b){
	return sqrt(b.first * b.first + b.second * b.second);
}

int main(){
	int n, i, j, k;
	double v, t, x, y, z, r, R;
	pdd p0, p;
	double ans, theta0, theta, theta1, theta2, angle1, angle2, d;

	scanf("%lf%lf%lf%lf", &p0.first, &p0.second, &v, &t);

	scanf("%d", &n);

	R = v * t;

	for(i = 1; i <= n; i++){
		scanf("%lf%lf%lf", &p.first, &p.second, &r);

		p.first -= p0.first;
		p.second -= p0.second;

		d = dis(p);

		if(d <= r){
			ans = 1;
			printf("%.15lf\n", ans);
			return 0;
		}

		// cout << d << '\n';

		if(R + r < d)
			continue;
			
		theta0 = atan2(p.second, p.first);

		if(R * R + r * r < d * d)
			theta = acos(abs(R*R + d * d - r * r) / (2 * R * d));
		else
			theta = abs(asin(r / d));

		theta1 = theta0 - theta;
		theta2 = theta0 + theta;

		// cout << i << ' ' << theta0 << ' ' << theta1 << ' ' << theta2 << '\n';

		if(theta1 < 0){
			theta1 += 2*PI;
			theta2 += 2*PI;
		}

		if(theta2 > 2*PI){
			s.PB(MP(theta1,2*PI));
			s.PB(MP(0,theta2 - 2*PI));
		}
		else
			s.PB(MP(theta1,theta2));
	}

	sort(s.begin(), s.end());

	// for(i = 0; i < s.size(); i++)
		// cout << s[i].first << ' ' << s[i].second << '\n';

	for(i = 0, ans = 0; i < s.size(); ){
		angle1 = s[i].first;
		angle2 = s[i].second;

		for(i++; i < s.size(); i++){
			if(s[i].first <= angle2)
				angle2 = max(angle2, s[i].second);
			else
				break;
		}

		ans += (angle2 - angle1);
	}

	ans /= (2*PI);

	ans = min(1.0,ans);

	printf("%.15lf\n", ans);

	return 0;
}