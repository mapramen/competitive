#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int LIS(vector<int>& a){
  vector<int> v;

  for(int x: a){
    if(v.empty() || v.back() < x){
      v.push_back(x);
    }
    else{
      int i = lower_bound(v.begin(), v.end(), x) - v.begin();
      v[i] = x;
    }
  }

  return v.size();
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n + 1);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    p[x] = i;
  }

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
    x = p[x];
  }

  return LIS(a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}