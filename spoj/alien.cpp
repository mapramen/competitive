#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ansq = 0, ansp = 0;
  for(int i = 1, j = 1, s = 0; i <= n; ++i){
    for( ; j <= n && s <= m; ++j){
      s += a[j];
    }

    int q = j - i - (s > m);
    int p = s - (s > m ? a[j - 1] : 0);
    if(q > ansq || (q == ansq && p < ansp)){
      ansq = q, ansp = p;
    }

    s -= a[i];
  }

  printf("%d %d\n", ansp, ansq);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}