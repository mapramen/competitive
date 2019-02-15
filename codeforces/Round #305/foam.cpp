#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

vector< vector<int> > divisors(N);
int n, leastprime[N], mu[N], a[N], multiples[N];
bool isPresent[N];

void PreComputeDivisors(){
	leastprime[1] = 1;

	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i)
			divisors[j].PB(i);

		if(leastprime[i] == 0)
			for(int j = i; j < N; j += i)
				if(leastprime[j] == 0)
					leastprime[j] = i;
	}
}

void PreComputeMobiusInverse(){
	int i, j, k;
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
}

void UpdateDivisorCount(int i, int x){
	for(int j = 0; j < divisors[i].size(); j++){
		int k = divisors[i][j];
		multiples[k] += x;
	}
}

int GcdEqualOne(int i){
	int ans = 0;

	for(int j = 0; j < divisors[i].size(); j++){
		int k = divisors[i][j];
		ans += (mu[k] * multiples[k]);
	}

	return ans;
}

int Query(int i){
	if(isPresent[i]){
		UpdateDivisorCount(a[i],-1);
		n--;
		int ans = GcdEqualOne(a[i]);
		isPresent[i] = 0;
		return -ans;
	}
	else{
		int ans = GcdEqualOne(a[i]);
		UpdateDivisorCount(a[i],1);
		n++;
		isPresent[i] = 1;
		return ans;
	}
}

int main(){
	int i, k, q;
	ll ans = 0;

	PreComputeDivisors();
	PreComputeMobiusInverse();

	scanf("%d%d", &n, &q);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	n = 0;

	while(q--){
		scanf("%d", &i);
		ans += Query(i);
		printf("%I64d\n", ans);
	}

	return 0;
}