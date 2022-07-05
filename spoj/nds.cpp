#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> v;
  while(n--){
    int x;
    scanf("%d", &x);

    if(v.empty() || v.back() < x){
      v.push_back(x);
    }
    else{
      int i = lower_bound(v.begin(), v.end(), x) - v.begin();
      v[i] = x;
    }
  }

  int l;
  scanf("%d", &l);

  return l > v.size() ? -1 : v[l - 1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}