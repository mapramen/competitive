#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int ans = 0;
  for(int k = 30; k != -1; --k){
    int mk = 0;
    for(int x: a){
      mk += ((x & (1 << k)) == 0);
    }

    if(mk <= m){
      ans |= (1 << k);
      m -= mk;
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