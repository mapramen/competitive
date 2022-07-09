#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsValid(int n){
  int prv = 0;
  for( ; n != 0; n /= 10){
    int cur = n % 10;
    if(cur == 2 || (cur == 1 && prv == 4)){
      return false;
    }
    prv = cur;
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);

  int ans = 1;
  for(int c = 0; c != n; ++ans){
    c += IsValid(ans);
  }
  --ans;

  printf("%d\n", ans);

  return 0;
}