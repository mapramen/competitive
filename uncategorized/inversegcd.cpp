#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int leastprime[N], mu[N], num[N];
vector< vector<int> > divisor(N), a(N), b(N);

void updateBIT(vector<int>& T, int i, int x){
	for( ; i != 0 && i < T.size(); i += (i&-i))
		T[i] += x;
}

int queryBIT(vector<int>& T, int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans += T[i];

	return ans;
}

int binarysearch(int n, int d){
	int i = 0, j = a[d].size() - 1, k = 0, mid;

	while(i <= j){
		mid = i + (j - i) / 2;

		if(a[d][mid] < n){
			k = mid;
			i = mid + 1;
		}
		else
			j = mid - 1;
	}

	return k;
}

int query(int n){
	int j, k, d, ans = 0;

	for(j = 0; j < divisor[n].size(); j++){
		d = divisor[n][j];

		k = binarysearch(n,d);

		ans += (mu[d]*queryBIT(b[d],k));
	}

	return ans;
}

void update(int n){
	int j, k, d;

	for(j = 0; j < divisor[n].size(); j++){
		d = divisor[n][j];

		k = binarysearch(n,d);

		updateBIT(b[d], k + 1, 1);
	}
}

int main(){
	int n, i, j, k;
	ll ans = 0;
	
	leastprime[1] = 1;

	for(i = 1; i < N; i++){
		a[i].PB(0);
		b[i].PB(0);

		for(j = i; j < N; j += i){
			a[i].PB(j);
			b[i].PB(0);
			divisor[j].PB(i);
		}

		if(leastprime[i] == 0)
			for(j = i; j < N; j += i)
				if(leastprime[j] == 0)
					leastprime[j] = i;
	}

	mu[1] = 1;

	for(i = 2; i < N; i++){
		for(k = 0, j = i; leastprime[j] == leastprime[j / leastprime[j]]; j /= leastprime[j], k++);

		k++;
		j /= leastprime[j];

		if(k > 1)
			mu[i] = 0;
		else
			mu[i] = (-1)*mu[j];
	}

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for(i = n; i > 0; i--){
		ans += query(num[i]);
		update(num[i]);
	}

	printf("%lld\n", ans);

	return 0;
}
