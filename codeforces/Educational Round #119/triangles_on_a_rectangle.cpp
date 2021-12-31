#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ReadPoints(){
  int n;
  scanf("%d", &n);

  int a, b;
  scanf("%d", &a);

  while(--n){
    scanf("%d", &b);
  }

  return b - a;
}

ll Solve(){
  int w, h;
  scanf("%d%d", &w, &h);

  int maxWidth = max(ReadPoints(), ReadPoints());
  int maxHeight = max(ReadPoints(), ReadPoints());

  return max(1ll * maxWidth * h, 1ll * w * maxHeight);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}