#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  set<int> S;
  while(n--){
    int x;
    scanf("%d", &x);

    S.insert(x);

    int y = x;
    while(!S.empty() && *S.rbegin() >= x){
      y = max(y, *S.rbegin());
      S.erase(*S.rbegin());
    }

    S.insert(y);
  }

  return S.size();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}