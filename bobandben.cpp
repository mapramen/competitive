#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int t, n, m, k, ans;

	scanf("%d", &t);

	while(t--){
		ans = 0;

		scanf("%d", &n);

		while(n--){
			scanf("%d%d", &m, &k);
			if(m < 3)
				m = m % 2;
			else
				m = (m % 2 == 0) + 1;

			ans ^= m;
		}

		if(ans == 0)
			printf("BEN\n");
		else
			printf("BOB\n");
	}

	return 0;
}
