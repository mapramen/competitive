#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      char c = (i == j && (i == 2 || i >= 4)) ? 'Q' : '.';
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