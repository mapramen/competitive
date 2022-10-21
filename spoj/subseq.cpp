#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<ll,int> C;

ll Solve(){
  C.clear();
  C[0] = 1;

  int n;
  scanf("%d", &n);

  ll s = 0, ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    s += x;

    auto it = C.find(s - 47);
    if(it != C.end()){
      ans += it->second;
    }

    ++C[s];
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