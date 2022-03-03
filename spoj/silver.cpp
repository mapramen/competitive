#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  return 31 - __builtin_clz(n);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}