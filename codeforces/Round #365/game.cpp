#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, i, j, ans = 0;

	cin >> n;

	while(n--){
		cin >> i >> j;

		ans += ((i > j) - (i < j));
	}

	if(ans == 0)
		cout << "Friendship is magic!^^\n";
	else
		if(ans > 0)
			cout << "Mishka\n";
		else
			cout << "Chris\n";

	return 0;
}
