#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, k, r;

	cin >> k >> r;

	for(n = 1; n < 10; n++){
		if((n * k) % 10 == 0 || (n * k) % 10 == r)
			break;
	}

	cout << n << '\n';

	return 0;
}
