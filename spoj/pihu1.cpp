#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

ll a[N];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);

  ll p;
  scanf("%lld", &p);

  for(int z = 3; z <= n; ++z){
    for(int x = 1, y = z - 1; x < y; ){
      ll q = a[x] + a[y] + a[z];
      if(q == p){
        return true;
      }

      if(q < p){
        ++x;
      }
      else{
        --y;
      }
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}