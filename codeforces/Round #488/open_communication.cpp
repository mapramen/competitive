#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void TakeInputs(int n, vector<int>& v){
  while(n--){
    int x, y;
    cin >> x >> y;
    v.PB(((1 << x) | (1 << y)));
  }
}

int Solve(vector<int> v1, vector<int> v2){
  int n = v1.size(), m = v2.size(), ans = 0;

  set<int> S;
  for(int i = 0; i < n && ans >= 0; ++i){
    set<int> s;
    for(int j = 0; j < m && ans >= 0; ++j){
      int z = (v1[i] & v2[j]);
      if(__builtin_popcount(z) == 1){
        s.insert(z);
      }
    }
    if(s.size() == 2){
      ans = -100;
    }
    for(auto x : s)
      S.insert(x);
  }

  if(ans >= 0){
    ans = S.size() > 1 ? 0 : *S.begin();
  }

  return ans;
}

int main(){
  int n, m;
  vector<int> v1, v2;

  cin >> n >> m;
  TakeInputs(n, v1);
  TakeInputs(m, v2);

  int ans1 = Solve(v1, v2), ans2 = Solve(v2, v1);

  int ans = -1;

  if(ans1 > 0 && ans1 == ans2)
    ans = ans1;

  if(min(ans1, ans2) == 0)
    ans = 0;

  for(int x = ans, i = 1; ans > 0; ++i){
    if((1 << i) == ans){
      ans = i;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}
