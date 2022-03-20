#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> c(m + 1), s(m + 1);
  while(n--){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int x = 1; x <= m; ++x){
    s[x] = s[x - 1] + c[x];
  }

  for(int y = 1; y <= m; ++y){
    if(c[y] == 0){
      continue;
    }
    for(int k = 1, lx = y, rx = lx + y - 1; lx <= m; ++k, lx += y, rx += y){
      if(c[k] == 0 && (s[min(m, rx)] - s[lx - 1] > 0)){
        return false;
      }
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}