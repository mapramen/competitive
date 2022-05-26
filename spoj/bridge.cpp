#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

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

  vector<int> v;
  for(pii& p: a){
    int x = p.second;
    if(v.empty() || v.back() <= x){
      v.push_back(x);
      continue;
    }

    int i = upper_bound(v.begin(), v.end(), x) - v.begin();
    v[i] = x;
  }

  return v.size();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}