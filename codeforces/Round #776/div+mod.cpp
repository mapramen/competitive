#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int F(int x, int a){
  return (x / a) + (x % a);
}

int F(int l, int r, int a, int x){
  return l <= x && x <= r ? F(x, a) : 0;
}

int Solve(){
  int l, r, a;
  scanf("%d%d%d", &l, &r, &a);

  return max(max(F(l, a), F(r, a)), F(l, r, a, a * (r / a) - 1));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}