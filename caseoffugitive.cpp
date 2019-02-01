#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair< ll, int >
#define plli pair< pll, int > 
#define PB push_back
#define MP make_pair
#define N 200001

plli a[N];
map< ll , stack<int> > b;
int ans[N];

int main(){
	int n, m, i, j, k;
	ll x;

	cin >> n >> m;

	for(i = 1; i <= n; i++)
		cin >> a[i].first.first >> a[i].first.second;

	for(i = 1; i <= m; i++){
		cin >> x;

		auto it = b.find(x);

		if(it != b.end())
			it->second.push(i);
		else{
			stack<int> s;
			s.push(i);

			b.insert(MP(x,s));
		}		
	}

	for(i = 1; i < n; i++)
		a[i] = MP(MP(a[i + 1].first.second - a[i].first.first, a[i + 1].first.first - a[i].first.second), i);

	sort(a + 1, a + n);

	for(i = 1; i < n; i++){
		auto it = b.lower_bound(a[i].first.second);

		if(it == b.end() || it->first > a[i].first.first)
			break;

		ans[a[i].second] = it->second.top();

		it->second.pop();

		if(it->second.empty())
			b.erase(it->first);
	}

	if(i != n)
		printf("No\n");
	else{
		printf("Yes\n");

		for(i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}
