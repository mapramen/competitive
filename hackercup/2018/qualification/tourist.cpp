#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Solve(){
  ll n, k, m;
  vector<string> attractions;
  vector< pii > v;

  cin >> n >> k >> m;

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    attractions.PB(s);
    v.PB(MP(0, i));
  }

  m = (m - 1) % n;

  while(m--){
    for(int i = 0; i < k; ++i){
      ++v[i].first;
    }
    sort(v.begin(), v.end());
  }

  vector<int> ans;
  for(int i = 0; i < k; ++i){
    ans.PB(v[i].second);
  }

  sort(ans.begin(), ans.end());

  for(auto i : ans){
    cout << ' ' << attractions[i];
  }

  cout << '\n';
}

int main(){
  int t;

  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ":";
    Solve();
  }

  return 0;
}
