#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    ans = (ans + x - 1) % 2; 
  }

  return ans == 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "errorgorn" : "maomao90");
  }
  return 0;
}