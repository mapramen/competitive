#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int odd_cnt = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    odd_cnt += (x % 2 == 1);
  }

  return min(odd_cnt, n - odd_cnt);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}