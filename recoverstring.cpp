#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ll a0, a1, b0, b1, n, m, s1, s2;

	cin >> a0 >> b0 >> b1 >> a1;

	if(a0 == 0 && b0 == 0 && b1 == 0 && a1 == 0){
		printf("1\n");
		return 0;
	}

	for(s1 = n = 0; s1 + n <= a0; s1 += n, n++);

	for(s2 = m = 0; s2 + m <= a1; s2 += m, m++);

	if(s1 != a0 || s2 != a1){
		printf("Impossible\n");
		return 0;
	}

	if(a0 == 0 && b0 == 0 && b1 == 0)
		n = 0;

	if(b0 == 0 && b1 == 0 && a1 == 0)
		m = 0;

	if(b0 + b1 != n * m){
		printf("Impossible\n");
		return 0;
	}

	for( ; n > 0 && m > 0; ){
		if(b0 >= m){
			printf("0");
			n--;
			b0 -= m;
		}
		else{
			printf("1");
			m--;
		}
	}

	while(n--)
		printf("0");

	while(m--)
		printf("1");

	printf("\n");



	return 0;
}
