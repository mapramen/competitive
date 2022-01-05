#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(2 * k > n + 1){
    printf("-1\n");
    return;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      char c = (i % 2 == 0 && j == i && (i / 2) < k) ? 'R' : '.';
      putchar(c);
    }
    putchar('\n');
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}