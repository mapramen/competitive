#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

string Compute(vector<int>& candies, vector<int>& stones, int MOD){
	int n = candies.size(), m = stones.size();
	string ans;

	if(n == 1 || m == 1){
		for(int i = 1; i < n; i++)
			ans.PB('C');

		for(int j = 1; j < m; j++)
		ans.PB('S');
	}
	else{
		int k = (n + m - 2) / 2;
		vector<int> dp(m), parent(m);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(j != 0 && dp[j - 1] >= dp[j])
					dp[j] = dp[j - 1], parent[j] = parent[j - 1];
				dp[j] += (candies[i] + stones[j]) % MOD;
				parent[j] = (i + j == k) ? j : parent[j];
			}
		}

		int n_mid = k - parent[m - 1], m_mid = parent[m - 1];
		vector<int> candies1(candies.begin(), candies.begin() + n_mid + 1), candies2(candies.begin() + n_mid, candies.end());
		vector<int> stones1(stones.begin(), stones.begin() + m_mid + 1), stones2(stones.begin() + m_mid, stones.end());

		ans = Compute(candies1, stones1, MOD) + Compute(candies2, stones2, MOD);

		dp.clear(), parent.clear();
		candies1.clear(), candies2.clear(), stones1.clear(), stones2.clear();
	}

	return ans;
}

int main(){
	int n, m, p, ans;
	vector<int> candies, stones;
	vector< pii > v;
	string s;

	scanf("%d%d%d", &n, &m, &p);

	while(n--){
		int candy;
		scanf("%d", &candy);
		candies.PB(candy);
	}

	while(m--){
		int stone;
		scanf("%d", &stone);
		stones.PB(stone);
	}

	s = Compute(candies, stones, p);

	ans = (candies[0] + stones[0]) % p;
	for(int i = 0, j = 0, k = 0; k < s.size(); k++){
		if(s[k] == 'C')
			i++;
		else
			j++;
		ans += (candies[i] + stones[j]) % p;
	}

	cout << ans << '\n' << s << '\n';

	return 0;
}
