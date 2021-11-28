#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  return (a + c - 2 * b) % 3 == 0 ? 0 : 1;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}