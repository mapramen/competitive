#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  string a, b;
  cin >> a >> b;

  if(a == "0" && b == "0"){
    exit(0);
  }

  int ans = 0;
  for(int carry = 0; !a.empty() || !b.empty() || carry != 0; carry /= 10, ans += carry){
    if(!a.empty()){
      carry += (a.back() - '0');
      a.pop_back();
    }

    if(!b.empty()){
      carry += (b.back() - '0');
      b.pop_back();
    }
  }

  return ans;
}

int main(){
  while(true){
    int ans = Solve();
    
    if(ans == 0){
      printf("No carry operation.\n");
      continue;
    }

    if(ans == 1){
      printf("1 carry operation.\n");
      continue;
    }

    printf("%d carry operations.\n", ans);
  }
  return 0;
}