#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 18

int ans[(1 << B)];

int main(){
	int t, i, j;
	ll a;
	char s[2];

	cin >> t;

	while(t--){
		cin >> s >> a;

		for(i = 0, j = 0; i < B; i++){
			j += ((a % 2) * (1 << i));
			a /= 10;
		}

		if(s[0] == '+')
			ans[j]++;
		else
			if(s[0] == '-')
				ans[j]--;
			else
				cout << ans[j] << '\n';
	}

	return 0;
}
