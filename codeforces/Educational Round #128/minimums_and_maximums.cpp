#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int l1, r1, l2, r2;
  scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

  if(l2 < l1){
    swap(l1, l2), swap(r1, r2);
  }

  return l2 <= r1 ? l2 : l1 + l2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}