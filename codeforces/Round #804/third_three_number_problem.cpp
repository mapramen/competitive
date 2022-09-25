#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  if(n % 2 == 1){
    printf("-1\n");
    return;
  }

  printf("%d %d %d\n", 0, n / 2, n / 2);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}