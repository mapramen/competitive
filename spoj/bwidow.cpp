#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int a[N], b[N];
bool possible[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i], &b[i]);
    possible[i] = true;
  }

  for(int i = 1, x = 0; i <= n; ++i){
    possible[i] = possible[i] && (x < a[i]);
    x = max(x, b[i]);
  }

  for(int i = n, x = 0; i != 0; --i){
    possible[i] = possible[i] && (x < a[i]);
    x = max(x, b[i]);
  }

  for(int i = 1; i <= n; ++i){
    if(possible[i]){
      return i;
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}