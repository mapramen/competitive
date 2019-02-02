#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define PF push_front
#define POPB pop_back
#define POPF pop_front
#define MP make_pair
#define N 100010
#define B 320

int n, a[N], freq[N], cnt[N], ans[N], nodeInd[N], nextInd[2 * B], prevInd[2 * B], val[2 * B];
vector< vector< pair< pii, int > > > blocks(B);
queue<int> freeInd;

void CreateNode(int x){
	int i, j;
	if(nodeInd[x + 1] != 0){
		j = nodeInd[x + 1];
		i = prevInd[j];
	}
	else{
		i = nodeInd[x - 1];
		j = nextInd[i];
	}

	int k = freeInd.front();
	freeInd.pop();

	val[k] = x;
	nodeInd[x] = k;

	prevInd[k] = i;
	nextInd[k] = j;

	nextInd[i] = k;
	prevInd[j] = k;
}

void EraseNode(int x){
	int k = nodeInd[x];
	int j = nextInd[k];
	int i = prevInd[k];

	nextInd[i] = j;
	prevInd[j] = i;

	freeInd.push(k);
	nodeInd[x] = 0;
}

void Increment(int i){
	freq[i]++;

	i = freq[i];
	cnt[i]++;
	cnt[i - 1]--;

	if(cnt[i] == 1)
		CreateNode(i);

	if(cnt[i - 1] == 0)
		EraseNode(i - 1);
}

void Decrement(int i){
	freq[i]--;

	i = freq[i];
	cnt[i]++;
	cnt[i + 1]--;

	if(cnt[i] == 1)
		CreateNode(i);

	if(cnt[i + 1] == 0)
		EraseNode(i + 1);
}

int SingleCountPush(pii a, deque< pii >& Q1, deque< pii >& Q2){
	pii b = Q1.front();
	Q1.POPF();

	if(--b.second)
		Q1.PF(b);

	Q2.PB(MP(a.first + b.first, 1));
	return a.first + b.first;
}

int MultiCountPush(deque< pii >& Q1, deque< pii >& Q2){
	pii a = Q1.front();
	Q1.POPF();

	if(a.second % 2)
		Q1.PF(MP(a.first, 1));

	Q2.PB(MP(a.first + a.first, a.second / 2));
	return (a.first + a.first) * (a.second / 2);
}

int Query(){
	deque< pii > Q1, Q2;
	int ans = 0;

	for(int x = nextInd[0]; x != 0; x = nextInd[x])
		Q1.PB(MP(val[x], cnt[val[x]]));

	if(Q1.size() == 1 && Q1.front().second == 1)
		return 0;

	if(Q1.front().second == 1){
		pii a = Q1.front();
		Q1.POPF();
		ans += SingleCountPush(a, Q1, Q2);
	}
	else
		ans += MultiCountPush(Q1, Q2);

	while(!Q1.empty()){
		if(Q1.front().first <= Q2.front().first){
			if(Q1.front().second == 1){
				pii a = Q1.front();
				Q1.POPF();

				if(!Q1.empty() && (Q1.front().first <= Q2.front().first))
					ans += SingleCountPush(a, Q1, Q2);
				else
					ans += SingleCountPush(a, Q2, Q2);
			}
			else
				ans += MultiCountPush(Q1, Q2);
		}
		else{
			if(Q2.front().second == 1){
				pii a = Q2.front();
				Q2.POPF();

				if(!Q2.empty() && (Q2.front().first < Q1.front().first))
					ans += SingleCountPush(a, Q2, Q2);
				else
					ans += SingleCountPush(a, Q1, Q2);
			}
			else
				ans += MultiCountPush(Q2, Q2);
		}
	}

	while(!(Q2.size() == 1 && Q2.front().second == 1)){
		if(Q2.front().second == 1){
			pii a = Q2.front();
			Q2.POPF();
			ans += SingleCountPush(a, Q2, Q2);
		}
		else
			ans += MultiCountPush(Q2, Q2);
	}

	return ans;
}

void MO(vector< pair< pii, int > >& block){
	if(block.size() == 0)
		return ;

	int i, j, k, x, l, r;
	sort(block.begin(), block.end());

	for(i = 1; i <= N; i++)
		freq[i] = cnt[i] = nodeInd[i] = 0;

	cnt[0] = n + 1;

	while(!freeInd.empty())
		freeInd.pop();

	for(i = 0; i < 2 * B; i++){
		nextInd[i] = prevInd[i] = 0;
		freeInd.push(i);
	}

	freeInd.pop();

	for(x = 0, i = j = 0; x < block.size(); x++){
		r = block[x].first.first;
		l = block[x].first.second;
		k = block[x].second;

		if(j != r){
			if(j < r){
				for(j++; j <= r; j++)
					Increment(a[j]);
				j--;
			}
			else{
				for( ; j > r; j--)
					Decrement(a[j]);
			}
		}

		if(i != l){
			if(i < l){
				if(i == 0) i = 1;

				for( ; i < l; i++)
					Decrement(a[i]);
			}
			else{
				for(i--; i >= l; i--)
					Increment(a[i]);
				i++;
			}
		}

		ans[k] = Query();
	}
}

int main(){
	int m, q, i, j, k, x, y, z;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &q);

	for(x = 1; x <= q; x++){
		scanf("%d%d", &i, &j);
		blocks[i / B].PB(MP(MP(j, i), x));
	}

	for(x = 0; x < B; x++)
		MO(blocks[x]);

	for(x = 1; x <= q; x++)
		printf("%d\n", ans[x]);

	return 0;
}