#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void initialise(vector< vector<int> >& divisor, vector< vector<int> >& indx, int m){
	divisor.resize(m);

	for(int i = 1; i < m; i++)
		for(int j = i; j < m; j += i)
			divisor[j].PB(i);

	indx.resize(m);
}

ll update(map< int, int >& T, int l, int r, int k){
	// cout << l << ' ' << r << ' ' << k << '\n';

	if(l > r)
		return 0;

	auto jt = T.lower_bound(k);
	auto it = jt;

	if(jt == T.begin() || jt == T.end())
		return 0;

	int i, x, z;
	int j = jt->first;
	int y = jt->second;

	if(y <= l)
		return 0;

	r = min(r + 1, y);
	z = r;

	ll ans = 0;
	queue<int> q;

	for(it--; it != T.begin() && it->second >= l; it--){
		q.push(it->first);
		ans += 1LL*(k - it->first)*(z - it->second);
		z = it->second;
	}

	if(it->second < l)
		ans += 1LL*(k - it->first)*(z - l);
	else{
		if(it->second == l){
			q.push(it->first);
			ans += 1LL*(k - it->first)*(z - l);
		}
	}

	while(!q.empty()){
		// cout << q.front() << '\n';
		T.erase(q.front());
		q.pop();
	}

	if(k == j)
		T.erase(j);

	T.insert(MP(k,l));

	// cout << "Map starts:\n";
	// for(it = T.begin(); it != T.end(); it++)
	// 	cout << it->first << ' ' << it->second << '\n';

	// cout << ans << '\n' << '\n';

	return ans;
}

int main(){
	int n, m;
	vector< int > a;
	vector< vector<int> > divisor, indx;
	vector< ll > H;
	map< int,int > T;
	ll ans = 0, ansx = 0;

	scanf("%d", &n);

	if(n < 3){
		printf("0\n");
		return 0;
	}

	a.resize(n + 1);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);

		while(H.size() < a[i] + 1)
			H.PB(0);
	}

	m = H.size() - 1;

	initialise(divisor, indx, m + 1);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < divisor[a[i]].size(); j++){
			int k = divisor[a[i]][j];
			indx[k].PB(i);
		}
	}

	H[m] = 1LL*(n + 1)*n / 2;
	T.insert(MP(n + 2, n + 1));
	T.insert(MP(0, 1));

	// for(auto it = T.begin(); it != T.end(); it++)
	// 	cout << it->first << ' ' << it->second << '\n';

	for( ; m > 0; m--){
		if(indx[m].size() < 2)
			H[m - 1] = H[m];
		else{
			// cout << m << '\n';
			// for(int i = 0; i < indx[m].size(); i++)
			// 	cout << indx[m][i] << ' ';
			// cout << '\n';

			int l, r, k;

			l = indx[m][1] + 1;
			r = n;
			k = n + 1;
			ansx += update(T, l, r, k);

			l = indx[m][0] + 1;
			r = indx[m][1];
			k = indx[m][indx[m].size() - 1];
			ansx += update(T, l, r, k);

			l = 1;
			r = indx[m][0];
			k = indx[m][indx[m].size() - 2];
			ansx += update(T, l, r, k);

			H[m - 1] = 1LL*n*(n + 1) - ansx;
			// cout << '\n';
			// cout << '\n';
		}
	}

	for(m = H.size() - 1; m > 0; m--){
		// cout << m << ' ' << H[m] << '\n';
		ans += m*(H[m] - H[m - 1]);
	}

	cout << ans << '\n';

	return 0;
}
