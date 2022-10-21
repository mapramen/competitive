#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  int ans = 0, m = 0;
  while(n--){
    int z;
    scanf("%d", &z);
    ans ^= z;
    m = max(m, z);
  }

  return m <= 1 ? ans == 0 : ans != 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "John" : "Brother");
  }
  return 0;
}