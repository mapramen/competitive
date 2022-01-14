#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> c(n + 1);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  ll ans = 0;
  priority_queue<int> Q;
  for(int i = 0; i <= n; ++i){
    if(ans < 0){
      printf("%lld ", ans);
      continue;
    }

    printf("%lld ", ans + c[i]);

    while(c[i] > 1){
      Q.push(i);
      --c[i];
    }

    if(c[i] == 0 && Q.empty()){
      ans = -1;
      continue;
    }

    if(c[i] == 0){
      ans += (i - Q.top());
      Q.pop();
    }
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}