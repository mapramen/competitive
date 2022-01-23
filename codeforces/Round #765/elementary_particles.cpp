#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 150001

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> v(n);
  for(int& x: v){
    scanf("%d", &x);
  }

  int ans = -1;
  for(int i = 1; i <= n; ++i){
    int x = v[i - 1];
    if(a[x] != 0){
      int j = a[x];
      int ansx = min(i, j) + min(n - i, n - j);
      ans = max(ans, ansx);
    }
    a[x] = i;
  }

  for(int x: v){
    a[x] = 0;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}