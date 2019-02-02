#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< vector<int> > v;
vector<int> dp;
int c;

void Update_Interval(int i, int j, int x){
	dp[i] += x;
	dp[j + 1] -= x;
}

void Update(int i, int j, int x){
	if(j < c)
		Update_Interval(i, j, x);
	else{
		Update_Interval(i, c - 1, x);
		Update_Interval(0, j % c, x);
	}
}

void Solve(int k, int n1, int n2){
	for( ; n1 <= n2 && v[n1].size() <= k; n1++);

	if(n1 > n2)
		return ;

	int i, j;

	for(i = n1; i <= n2 && k < v[i].size(); i++);

	if(i <= n2)
		return ;

	int m = (1 - v[n1][k] + c) % c;

	for(i = n1; i <= n2; i++)
		v[i][k] = (v[i][k] + m - 1) % c + 1;

	for(i = n1 + 1; i <= n2 && v[i - 1][k] <= v[i][k]; i++);

	if(i <= n2)
		return ;

	Update(m, m + c - v[n2][k], n2 - n1 + 1);

	for(i = n1; i <= n2; i = j){
		for(j = i; j <= n2 && v[j][k] == v[i][k]; j++);
		Solve(k + 1, i, j - 1);
	}
}

int main(){
	int n, i, j, k, s = 0;

	scanf("%d%d", &n, &c);

	while(n--){
		vector<int> u;
		
		scanf("%d", &k);
		s += k;
		
		while(k--){
			scanf("%d", &i);
			u.PB(i);
		}
		
		v.PB(u);
	}

	dp.resize(c + 1);
	Solve(0, 0, v.size() - 1);

	for(i = 1; i <= c; i++)
		dp[i] += dp[i - 1];

	for(i = 0; i < c; i++){
		if(dp[i] == s){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}
