#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0, j = n - 1; i < j; ){
    ll s = 0ll + a[i] + a[j];
    if(s == m){
      ++i, --j, ++ans;
      continue;
    }

    if(s > m){
      --j;
    }
    else{
      ++i;
    }
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