#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200010

vector< vector< pii > > A(N), B(N);
map< pii, int > p;
set< pii > s;
ll ans[N];

void QuerySensors(vector< pii >& v, int x, int y, ll d){
	for(int i = 0; i < v.size(); i++){
		ans[p[v[i]]] = d + abs(v[i].first - x);
		p[v[i]] = 0;
	}
}

int main(){
	int n, m, q, i, j, k, dir, x, y, z;
	ll t;

	scanf("%d%d%d", &n, &m, &q);

	for(x = 1; x <= q; x++){
		scanf("%d%d", &i, &j);
		A[i + j].PB(MP(i,j));
		B[n - i + j].PB(MP(i,j));
		p.insert(MP(MP(i,j),x));
		ans[x] = -1;
	}

	s.insert(MP(n,m));
	s.insert(MP(n,0));
	s.insert(MP(0,m));

	x = y = dir = 0;
	t = 0;

	while(s.find(MP(x,y)) == s.end()){
		s.insert(MP(x,y));
		if(dir == 0 || dir == 2){
			QuerySensors(B[n - x + y], x, y, t);

			if(dir == 0){
				z = min(n - x, m - y);
				x += z, y += z;
				t += z;
				
				if(y == m)
					dir = 3;
				else
					dir = 1;
			}
			else{
				z = min(x, y);
				x -= z, y -= z;
				t += z;
				
				if(x == 0)
					dir = 3;
				else
					dir = 1;
			}
		}
		else{
			QuerySensors(A[x + y], x, y, t);

			if(dir == 1){
				z = min(x, m - y);
				x -= z, y += z;
				t += z;
				
				if(x == 0)
					dir = 0;
				else
					dir = 2;
			}
			else{
				z = min(n - x, y);
				x += z, y -= z;
				t += z;
				
				if(y == 0)
					dir = 0;
				else
					dir = 2;
			}
		}
	}

	for(x = 1; x <= q; x++)
		printf("%lld\n", ans[x]);

	return 0;
}
