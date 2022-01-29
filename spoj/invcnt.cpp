#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> a, C, T;

void CoordinateCompress(){
  C.clear(), T.clear();

  C.push_back(0);
  for(int x: a){
    C.push_back(x);
  }
  sort(C.begin(), C.end());

  for(int &x: a){
    x = lower_bound(C.begin(), C.end(), x) - C.begin();
  }

  T.resize(C.size());
}

void Update(int i){
  for( ; i < T.size(); i += (i & -i)){
    ++T[i];
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  a.resize(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  CoordinateCompress();
  reverse(a.begin(), a.end());

  ll ans = 0;
  for(int x: a){
    ans += Query(x - 1);
    Update(x);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}