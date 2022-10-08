#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 41

char s[N];
ll L[B], R[B], a[B];

void Solve(){
  int n, c, q;
  scanf("%d%d%d", &n, &c, &q);

  scanf("%s", s);

  a[0] = n;
  for(int k = 1; k <= c; ++k){
    scanf("%lld%lld", &L[k], &R[k]);
    a[k] = a[k - 1] + (R[k] - L[k] + 1);
  }

  while(q--){
    ll i;
    scanf("%lld", &i);

    for(int k = c; k != 0; --k){
      if(i <= a[k - 1]){
        continue;
      }
      i = (i - a[k - 1] - 1) + L[k];
    }

    printf("%c\n", s[i - 1]);
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