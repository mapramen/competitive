#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 1){
    return 2;
  }
  
  int ans = 2 * (n / 6);
  n %= 6;
  
  if(n == 0){
    return ans;
  }

  return ans + 1 + (n == 4 || n == 5);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}