#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

typedef struct node{
	int l;
	int r;
	ll minval;
	ll upval;	
}nod;

vector< vector<int> > adj(N), pathstart(N), pathend(N);
ll dp[N], inf = 1E18;
int parent[N], start[N], finish[N];
int timer = 0;
vector<nod> T;

void initialize(int n){
	int B = 1;

	for( ; B < n; B = (B << 1));

	T.resize(2*B);

	for(int i = B; i < 2*B; i++){
		T[i].l = T[i].r = i - B + 1;
		T[i].minval = inf;
		T[i].upval = 0;
	}

	for(int i = B - 1; i > 0; i--){
		T[i].l = T[2*i].l;
		T[i].r = T[2*i + 1].r;
		T[i].minval = inf;
		T[i].upval = 0;
	}
}

void update(int k, int i, int j, ll x){
	if(j < T[k].l && i > T[k].l){
		T[k].minval += T[k/2].upval;
		T[k].upval += T[k/2].upval;
		return ;
	}

	i = max(i, T[k].l);
	j = min(j, T[k].r);

	if(i == T[k].l && j == T[k].r){
		T[k].minval += (T[k/2].upval + x);
		T[k].upval += (T[k/2].upval + x);
		return ;
	}


}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



	return 0;
}
