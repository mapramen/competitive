#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int a, b, c, x, y;
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
  return max(0, x - a) + max(0, y - b) <= c;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}