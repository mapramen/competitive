#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, k;
    scanf("%d%d", &n, &k);
    while(n--){
      int x;
      scanf("%d", &x);
      k -= (x > 1);
    }
    printf("%s\n", k >= 0 ? "YES" : "NO");
  }

  return 0;
}
