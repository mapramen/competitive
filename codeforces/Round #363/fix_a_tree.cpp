#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], inDegree[N];
bool visited[N];

int main(){
	int n, i, j, k, x, y, z, ans = 0, root = 0;
	vector< int > cycleHead;

	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		inDegree[a[i]]++;
	}

	queue< int > q;

	for(i = 1; i <= n; i++){
		if(inDegree[i] == 0){
			q.push(i);
			visited[i] = 1;
		}
	}

	while(!q.empty()){
		i = q.front();
		q.pop();

		j = a[i];
		inDegree[j]--;

		if(inDegree[j] == 0){
			q.push(j);
			visited[j] = 1;
		}
	}

	for(i = 1; i <= n; i++){
		if(visited[i] == 0){
			visited[i] = 1;

			for(j = i; visited[a[j]] == 0; j = a[j])
				visited[a[j]] = 1;

			if(j == a[j])
				root = j;

			cycleHead.PB(j);
		}
	}

	if(root == 0)
		root = cycleHead[0];

	for(i = 0, ans = 0; i < cycleHead.size(); i++){
		j = cycleHead[i];
		ans += (a[j] != root);
		a[j] = root;
	}

	printf("%d\n", ans);

	for(i = 1; i <= n; i++)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}
