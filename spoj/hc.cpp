#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char op[4];

bool Solve(){
  int n;
  scanf("%d", &n);

  bool ans = false;
  while(n--){
    scanf("%s", op);
    if(op[0] == 'l'){
      ans = !ans;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "lxh" : "hhb");
  }
  return 0;
}