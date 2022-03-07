#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> v{INT_MIN, INT_MAX};

int GetLessOrEqualCount(int x){
  return upper_bound(v.begin(), v.end(), x) - v.begin();
}

int GetCount(int x){
  int i = GetLessOrEqualCount(x);
  
  if(v[i - 1] != x){
    return 0;
  }
  
  return i - GetLessOrEqualCount(x - 1);
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n), b(n), c(n), d(n);
  for(int i = 0; i < n; ++i){
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }

  for(int x: a){
    for(int y: b){
      v.push_back(x + y);
    }
  }
  sort(v.begin(), v.end());

  ll ans = 0;
  for(int x: c){
    for(int y: d){
      ans += GetCount(-(x + y));
    }
  }

  printf("%lld\n", ans);

  return 0;
}