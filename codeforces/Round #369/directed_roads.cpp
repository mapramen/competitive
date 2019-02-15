#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

int a[N], inDegree[N];
bool visited[N];

int main(){
	int n, i, j, k;
	ll ansx, ans = 1;

	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		inDegree[a[i]]++;
	}

	queue<int> q;

	for(i = 1; i <= n; i++){
		if(inDegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()){
		ans = (ans * 2) % MOD;
		i = q.front();
		q.pop();
		
		visited[i] = 1;
		
		j = a[i];
		
		inDegree[j]--;
		if(inDegree[j] == 0)
			q.push(j);
	}

	for(i = 1; i <= n; i++){
		if(visited[i] == 1)
			continue;

		for(visited[i] = 1, j = a[i], ansx = 0; j != i; j = a[j]){
			visited[j] = 1;
			ansx = (2*ansx + 2) % MOD;
		}

		ans = (ans * ansx) % MOD;
	}

	cout << ans << '\n';

	return 0;
}
