#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll GetWood(vector<int>& a, int h){
  ll s = 0;
  for(int& x: a){
    s += max(0, x - h);
  }
  return s;
}

int main(){
  int n;
  ll W;
  scanf("%d%lld", &n, &W);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int l = 0, r = 1E9, ans = 0;
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(GetWood(a, mid) >= W){
      ans = mid, l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}