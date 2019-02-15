#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int h[N];

int main(){
	int n, i, j, k, x, m;
	stack<int> a, l;

	scanf("%d", &n);

	a.push(0);
	l.push(0);

	for(k = 1; k <= n; k++){
		scanf("%d", &x);

		i = 0;

		while(a.top() >= x){
			i = k - l.top();
			h[i] = max(h[i], a.top());
			a.pop();
			l.pop();
		}

		a.push(x);
		l.push(k - i);
	}

	while(!a.empty()){
		i = k - l.top();
		h[i] = max(h[i], a.top());
		a.pop();
		l.pop();
	}

	for(i = n - 1; i > 0; i--)
		h[i] = max(h[i], h[i + 1]);

	for(i = 1; i <= n; i++)
		printf("%d ", h[i]);

	printf("\n");

	return 0;
}