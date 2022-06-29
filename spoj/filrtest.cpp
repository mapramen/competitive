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

int Solve(){
  int m;
  scanf("%d%s", &m, s);

  if(m == -1){
    exit(0);
  }

  int n = strlen(s);

  if(m < n){
    return 0;
  }

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  return 1 + (m - n) / (n - f[n]);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}