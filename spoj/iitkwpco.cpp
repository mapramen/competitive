#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> C;

int Solve(){
  int n;
  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  int ans = 0;
  while(!C.empty()){
    auto it = C.begin();
    if(it->second == 0){
      C.erase(it);
      continue;
    }

    int x = 2 * (it->first);
    --(it->second);

    it = C.find(x);
    if(it != C.end() && it->second > 0){
      ++ans, --(it->second);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}