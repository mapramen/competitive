#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a.begin() + 1, a.end(), greater<int>());

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }
  a.push_back(INT_MAX);

  while(q--){
    int x;
    scanf("%d", &x);

    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    if(i > n){
      i = -1;
    }

    printf("%d\n", i);
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