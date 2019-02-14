#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define piiii pair< pii, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

vector< vector< piii > > garlands(N);
queue< int > garlandQuery[N];
vector< piiii > queries;
ll T[N][N], ans[N];
bool isGarlandOn[N];

void Update(int i, int j, int n, int m, int x){
	int k = j;
	for( ; i <= n; i += (i&-i))
		for(j = k; j <= m; j += (j&-j))
			T[i][j] += x;
}

ll Query(int i, int j){
	int k = j;
	ll ans = 0;

	for( ; i > 0; i -= (i&-i))
		for(j = k; j > 0; j -= (j&-j))
			ans += T[i][j];

	return ans;
}

ll QueryRect(int x1, int y1, int x2, int y2){
	return Query(x2, y2) + Query(x1 - 1, y1 - 1) - (Query(x1 - 1, y2) + Query(x2, y1 - 1));
}

int main(){
	int n, m, k, q, len, i, j, w, x1, y1, x2, y2;
	char s[10];

	scanf("%d%d%d", &n, &m, &k);

	for(int t = 1; t <= k; t++){
		scanf("%d", &len);

		while(len--){
			scanf("%d%d%d", &i, &j, &w);
			garlands[t].PB(MP(MP(i,j),w));
		}
	}

	for(i = 1; i <= k; i++)
		isGarlandOn[i] = 1;

	scanf("%d", &q);
	int askqueryNo = 1;
	queries.PB(MP(MP(0,0), MP(0,0)));

	while(q--){
		scanf("%s", s);

		if(s[0] == 'S'){
			scanf("%d", &i);
			isGarlandOn[i] ^= 1;
		}
		else{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

			for(i = 1; i <= k; i++)
				if(isGarlandOn[i])
					garlandQuery[i].push(askqueryNo);

			queries.PB(MP(MP(x1, y1), MP(x2, y2)));
			askqueryNo++;
		}
	}

	for(int x = 1; x <= k; x++){
		for(int y = 0; y < garlands[x].size(); y++){
			i = garlands[x][y].first.first;
			j = garlands[x][y].first.second;
			w = garlands[x][y].second;
			Update(i, j, n, m, w);
		}

		while(!garlandQuery[x].empty()){
			i = garlandQuery[x].front();
			garlandQuery[x].pop();
			
			x1 = queries[i].first.first;
			y1 = queries[i].first.second;
			x2 = queries[i].second.first;
			y2 = queries[i].second.second;

			ans[i] += QueryRect(x1, y1, x2, y2);
		}

		for(int y = 0; y < garlands[x].size(); y++){
			i = garlands[x][y].first.first;
			j = garlands[x][y].first.second;
			w = garlands[x][y].second;
			Update(i, j, n, m, -w);
		}
	}

	for(i = 1; i < askqueryNo; i++)
		cout << ans[i] << '\n';

	return 0;
}