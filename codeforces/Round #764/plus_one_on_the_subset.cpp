#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& ai: a){
    scanf("%d", &ai);
  }
  sort(a.begin(), a.end());

  return a.back() - a.front();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}