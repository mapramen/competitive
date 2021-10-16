#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  bool ans = false;
  for(int i = 0; i < 3; ++i){
    int x;
    scanf("%d", &x);
    ans = ans || (x == 7);
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }

  return 0;
}