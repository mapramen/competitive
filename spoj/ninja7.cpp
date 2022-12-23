#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] -= x;
  }

  sort(a + 1, a + n + 1, greater<int>());

  ll s = 0;
  for(int i = 1; i <= n && s >= 0; ++i){
    s += a[i];
    if(s < 0){
      return i - 1;
    }
  }

  return n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}