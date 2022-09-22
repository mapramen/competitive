#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll N = 4E9;
vector<ll> a;

void Initialize(){
  ll s = 0;
  for(int i = 0; s < N; ++i, s += i){
    a.push_back(s);
  }
}

string Solve(){
  ll n;
  scanf("%lld", &n);
  int i = lower_bound(a.begin(), a.end(), n) - a.begin();
  return a[i] == n ? to_string(i) : "NAI";
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  
  return 0;
}