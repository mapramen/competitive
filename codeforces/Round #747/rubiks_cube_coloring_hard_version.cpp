#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define K 100
#define MOD 1000000007

vector<char> colors {'w', 'y', 'r', 'b', 'g', 'o'};
int F[K];
map<char, vector<char>> adjColors;
map<pair<ll,char>,int> dp;
set<ll> S;
map<ll,char> nodeToColorMap;

void Initialise(){
  adjColors['w'] = {'r', 'b', 'g', 'o'};
  adjColors['y'] = {'r', 'b', 'g', 'o'};
  adjColors['g'] = {'w', 'y', 'r', 'o'};
  adjColors['b'] = {'w', 'y', 'r', 'o'};
  adjColors['r'] = {'w', 'y', 'b', 'g'};
  adjColors['o'] = {'w', 'y', 'b', 'g'};

  ll f = 1;
  for(int k = 1; k < K; ++k){
    F[k] = f;
    f = (f * f) % MOD;
    f = (16 * f) % MOD;
  }
}

int DP(int k, ll i, char color){
  if(S.count(i) == 0){
    return F[k]; 
  }

  auto ct = nodeToColorMap.find(i);
  if(ct != nodeToColorMap.end() && ct->second != color){
    return 0;
  }

  if(k == 1){
    return 1;
  }

  auto it = dp.find({i, color});
  if(it != dp.end()){
    return it->second;
  }

  ll ansLeft = 0, ansRight = 0;
  for(char childColor: adjColors[color]){
    ansLeft = (ansLeft + DP(k - 1, 2 * i, childColor)) % MOD;
    ansRight = (ansRight + DP(k - 1, 2 * i + 1, childColor)) % MOD;
  }

  int ans = (1ll * ansLeft * ansRight) % MOD;

  dp[{i, color}] = ans;
  return ans;
}

int main(){
  int k, m;
  cin >> k >> m;

  while(m--){
    ll v;
    string color;
    cin >> v >> color;
    nodeToColorMap[v] = color[0];

    for( ; v > 0; v /= 2){
      S.insert(v);
    }
  }

  Initialise();

  int ans = 0;
  for(char color: colors){
    ans = (ans + DP(k, 1, color)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}