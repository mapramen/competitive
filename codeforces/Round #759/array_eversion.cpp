#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<pii> a;
map<int,int> S;

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a.push_back({x, i});
    S[i] = x;
  }
  sort(a.begin(), a.end(), greater<pii>());

  int ans = 0;
  while(!S.empty()){
    int x = S.rbegin()->second;
    while(!a.empty() && a.back().first <= x){
      S.erase(a.back().second);
      a.pop_back();
    }
    ++ans;
  }

  return ans - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}