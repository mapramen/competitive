#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int h = 1;
  for(int i = 1, y = -1; i <= n; ++i){
    int x = a[i];
    if(x == 0 && y == 0){
      h = -1;
      break;
    }

    if(x == 0){
      y = 0;
      continue;
    }

    h += y == 1 ? 5 : 1;
    y = 1;
  }

  return h;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}