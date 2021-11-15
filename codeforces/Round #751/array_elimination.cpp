#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 30

int a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int k = 0; k < B; ++k){
    int c = 0;
    for(int i = 1; i <= n; ++i){
      c += ((a[i] & (1 << k)) != 0);
    }
    if(c != 0){
      ans = __gcd(ans, c);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(ans == 0 || ans % i == 0){
      printf("%d ", i);
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