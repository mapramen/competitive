#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);

  while(n--){
    int h;
    scanf("%d", &h);

    while(h > d && m > 0){
      h -= d, --m;
    }
  }

  return m == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}