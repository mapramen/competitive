#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int x1, x2, x3;

	cin >> x1 >> x2 >> x3;

	cout << max(x1, max(x2, x3)) - min(x1, min(x2, x3)) << '\n';

	return 0;
}
