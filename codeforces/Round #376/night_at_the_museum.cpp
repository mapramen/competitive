#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int ans = 0, i = 0;
	string s;

	cin >> s;

	for(int j = 0; j < s.size(); j++){
		int k = 0;
		for( ; i != s[j] - 'a'; i = (i + 1) % 26, k++);
		ans += min(k, 26 - k);
	}

	cout << ans << '\n';
	
	return 0;
}
