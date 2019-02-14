#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], parent[N + 1];
ll sum[N + 1], ans;
stack<ll> s;

int Find_Set(int i){
	if(parent[i] == i)
		return i;
	
	parent[i] = Find_Set(parent[i]);
	return parent[i];
}

void Union_Set(int i, int j){
	i = Find_Set(i);
	j = Find_Set(j);

	if(sum[i] >= 0 && sum[j] >= 0){
		parent[j] = i;
		sum[i] += sum[j];
	}

	ans = max(ans, max(sum[i], sum[j]));
}

void Query(int n){
	if(n != 0){
		int i;
		scanf("%d", &i);
		
		Query(n - 1);

		sum[i] = a[i];
		Union_Set(i - 1, i);
		Union_Set(i, i + 1);
	}
	s.push(ans);
}

int main(){
	int n, i;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 0; i <= n + 1; i++){
		sum[i] = -1;
		parent[i] = i;
	}

	Query(n);

	s.pop();

	while(!s.empty()){
		printf("%lld\n", s.top());
		s.pop();
	}

	return 0;
}
