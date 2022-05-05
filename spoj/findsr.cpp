#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

int Solve(){
  scanf("%s", s);

  if(s[0] == '*'){
    exit(0);
  }

  int n = strlen(s);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  int p = n - f[n];
  return n % p == 0 ? n / p : 1;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}