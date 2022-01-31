#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Cost(int a, int b){
  int ans = b - a;
  for(int c = b; c != 0; c = ((c - 1) & b)){
    if(c >= a){
      ans = min(ans, c - a + (c != b));
    }
  }
  return ans;
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  if(a > b){
    return a - b;
  }

  int ans = b - a;
  for(int k = 0; k <= ans; ++k){
    ans = min(ans, k + Cost(a, b + k));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}