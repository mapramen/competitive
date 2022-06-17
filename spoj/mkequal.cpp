#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int r = 0;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    r = (r + x) % n;
  }

  return n - (r != 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}