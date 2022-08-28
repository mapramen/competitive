#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int s[N], f[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &s[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &f[i]);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", f[i] - max(s[i], f[i - 1]));
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