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

  return n * (n + 1) * (2 * n + 1) / 6;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}