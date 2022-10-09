#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> C;

int Solve(){
  int n;
  scanf("%d", &n);

  C.clear();
  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  while(C.size() != 1){
    vector<pii> a;
    for(auto [k, v]: C){
      a.push_back({k, v});
    }
    C.clear();

    for(auto [k, v]: a){
      if(v != 1){
        C[0] += (v - 1);
      }
    }

    for(int i = 1; i < a.size(); ++i){
      ++C[a[i].first - a[i - 1].first];
    }
  }

  return C.begin()->second != 1 ? 0 : C.begin()->first;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}