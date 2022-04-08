#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

void Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
    int p = i - f[i];
    if(p != i && i % p == 0){
      printf("%d %d\n", i, i / p);
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Test case #%d\n", k);
    Solve();
    if(k != t){
      printf("\n");
    }
  }
  return 0;
}