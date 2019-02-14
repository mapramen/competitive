#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 5

vector< vector<int> > ModuloList;
vector< int > num, currentNo;
int leftEnd[M], rightEnd[M], total;
ll inf = 1, B, C;

void initialize(int m){
	num.resize(m);
	currentNo.resize(m);
	ModuloList.resize(M);

	for(int i = 0; i < 18; i++)
		inf *= 10;
}

ll IncreaseLeftEnd(int current){
	ll maxDecrease = 0;
	int Index = M;

	for(int i = 0; i < M; i++){
		if(leftEnd[i] != rightEnd[i]){
			int x = current - ModuloList[i][leftEnd[i]];
			ll Decrease = B*(x/5) + C*(x%5);

			if(Decrease > maxDecrease){
				maxDecrease = Decrease;
				Index = i;
			}
		}
	}

	leftEnd[Index]++;
	total--;

	return maxDecrease;
}

ll compute(int m){
	for(int i = 0; i < M; i++)
		leftEnd[i] = rightEnd[i] = 0;

	total = 0;

	int current = currentNo[0], previous;
	ll ansx = 0, ans = inf;

	for(int k = 0; k < currentNo.size(); k++){
		previous = current;
		current = currentNo[k];

		ansx += (B*(total++)*((current - previous)/5) + C*(currentNo[k] - num[k]));

		if(total > m)
			ansx -= IncreaseLeftEnd(current);

		if(total == m)
			ans = min(ans, ansx);

		int j = num[k] % M;
		rightEnd[j]++;
	}

	return ans;
}

int main(){
	int n,m;
	ll ans;

	cin >> n >> m >> B >> C;

	initialize(n);
	ans = inf;

	B = min(B,M*C);

	while(n--)
		scanf("%d", &num[n]);

	sort(num.begin(), num.end());

	n = num[0];

	for(int i = 0; i < num.size(); i++){
		num[i] -= n;
		int j = num[i] % M;
		ModuloList[j].PB(num[i]);
		// cout << num[i] << ' ';
	}

	// cout << '\n';

	for(int k = 0; k < M; k++){
		for(int i = 0; i < num.size(); i++)
			for(currentNo[i] = num[i]; currentNo[i] % M != k; currentNo[i]++);

		total = 0;

		ans = min(ans, compute(m));
	}

	cout << ans << '\n';

	return 0;
}