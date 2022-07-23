#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  map<int,int> C;
  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  int ans = 0, ans_l = -1, ans_r = -1;
  int l = 1, r = 1;
  for(auto it = C.begin(); it != C.end(); ++it){
    if(it->second < k){
      continue;
    }

    if(it->first == r){
      ++r;
    }
    else{
      l = it->first, r = l + 1;
    }

    int ansx = r - l;
    if(ansx > ans){
      ans = ansx, ans_l = l, ans_r = r - 1;
    }
  }

  if(ans == 0){
    printf("-1\n");
    return;
  }

  printf("%d %d\n", ans_l, ans_r);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}