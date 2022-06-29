#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Calculate(int n){
  return n == 1 ? 0 : 1 + Calculate((n + 1) / 2);
}

int Solve(){
  int n;
  scanf("%d", &n);
  return 1 + Calculate(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}