#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define plli pair< pll, int > 
#define PB push_back
#define MP make_pair

vector<ll> compressedX;

int Get_Compressed_Value(ll a){
	return lower_bound(compressedX.begin(), compressedX.end(), a) - compressedX.begin();
}

void BIT_Update(vector<int>& T, int i, int x){
	for( ; i < T.size(); i += (i&-i))
		T[i] += x;
}

int BIT_Query(vector<int>& T, int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans += T[i];

	return ans;
}

int main(){
	int n, i, j, k, x, y, z, id;
	ll start, finish;
	vector< plli > a;
	vector<int> T;
	vector< pii > ans;

	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d%lld%lld", &id, &start, &finish);
		a.PB(MP(MP(finish, start), id));
		compressedX.PB(start);
		compressedX.PB(finish);
	}

	compressedX.PB(-1);
	sort(compressedX.begin(), compressedX.end());

	T.resize(compressedX.size());

	sort(a.begin(), a.end());

	for(i = j = n - 1; i > -1; i--){
		for(j = min(j, i); j > - 1; j--){
			if(a[j].first.first > a[i].first.second)
				BIT_Update(T, Get_Compressed_Value(a[j].first.second), 1);
			else
				break;
		}

		BIT_Update(T, Get_Compressed_Value(a[i].first.second), -1);

		k = BIT_Query(T, Get_Compressed_Value(a[i].first.first)) - BIT_Query(T, Get_Compressed_Value(a[i].first.second));
		ans.PB(MP(k, a[i].second));
	}

	sort(ans.begin(), ans.end());

	for(i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].second, ans[i].first);

	return 0;
}
