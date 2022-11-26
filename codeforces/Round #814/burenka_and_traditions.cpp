#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int ans = n;
  set<int> S;

  S.insert(0);
  for(int i = 1, z = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
    z ^= x;

    if(S.count(z) != 0){
      --ans;
      
      z = 0;
      S.clear();
      S.insert(0);
    }
    else{
      S.insert(z);
    }
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