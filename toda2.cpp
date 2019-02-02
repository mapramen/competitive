#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

vector< vector<int> > v(N*N);
int a[N];

int main(){
	int n, m, t, p, i, j, k, s;

	scanf("%d", &n);

	for(i = 1, k = 101, m = 0, s = 0; i <= n; i++){
		scanf("%d", &a[i]);
		k = min(k, a[i]);
		m = max(m, a[i]);
		s += a[i];
	}

	s -= n * k;
	m -= k;

	for( ; k > 0 && 2 * m > s; k--, s += n, m++);

	t = p = 0;
	priority_queue< pii > q;

	for(i = 1; i <= n; i++)
		q.push(MP(a[i] - k, i));

	if(k != 0){
		while(!q.empty()){
			i = q.top().second;
			j = q.top().first;
			q.pop();

			for( ; j > 0 && p < t; p++, j--)
				v[p].PB(i);

			while(j--)
				v[t++].PB(i);
		}

		for(t--, i = 0; t > -1 && v[t].size() == 1; t--, i++){
			v[i].PB(v[t][0]);
			v[t].clear();
		}
	}
	else{
		while(!q.empty()){
			vector<int> u;
			m = 0;

			for(i = 0; i < 5 && q.size() > 0; i++){
				u.PB(q.top().second);
				m = max(m, q.top().first);
				q.pop();
			}

			while(m--){
				for(i = 0; i < u.size(); i++)
					v[p].PB(u[i]);
				p++;
			}
		}
	}

	printf("%d\n%d\n", k, p);

	for(i = 0; i < p; i++){
		for(j = 1; j <= n; j++)
			a[j] = 0;

		for(j = 0; j < v[i].size(); j++)
			a[v[i][j]] = 1;

		for(j = 1; j <= n; j++)
			printf("%d", a[j]);
		printf("\n");
	}

	return 0;
}
