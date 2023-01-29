#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetLISLength(vector<pii>& a){
  vector<int> v, ans;

  for(pii& p: a){
    int x = p.second;
    if(v.empty() || v.back() <= x){
      v.push_back(x);
    }
    else{
      int k = upper_bound(v.begin(), v.end(), x) - v.begin();
      v[k] = x;
    }
  }

  return v.size();
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d", &p.first);
  }

  for(pii& p: a){
    scanf("%d", &p.second);
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  return GetLISLength(a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}