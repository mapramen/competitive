#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

vector< vector<int> > v(N);
int a[N];

int main(){
	int n, m, i, j, k, x, y;
	queue<int> q;

	cin >> n >> m;

	for(i = 1; i <= n; i++){
		cin >> a[i];

		if(a[i] <= m)
			v[a[i]].PB(i);
		else
			q.push(i);
	}

	x = n / m;

	for(i = 1, y = 0; i <= m; i++){
		if(v[i].size() > x){
			for(j = x; j < v[i].size(); j++){
				k = v[i][j];
				q.push(k);
			}
		}
		else
			y += (x - v[i].size());
	}

	for(i = 1; i <= m; i++){
		if(v[i].size() < x){
			for(j = v[i].size(); j < x; j++){
				k = q.front();
				q.pop();
				a[k] = i;
			}
		}
	}

	cout << x << ' ' << y << '\n';

	for(i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}
