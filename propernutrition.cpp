#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, a, b;

  cin >> n >> a >> b;

  for(int i = 0, x = 0, y = n; x <= n; ++i, x += a, y -= a){
    if(y % b == 0){
      printf("YES\n%d %d\n", i, y / b);
      return 0;
    }
  }

  printf("NO\n");

  return 0;
}
