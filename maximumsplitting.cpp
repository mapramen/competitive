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
    int n, ans;

    scanf("%d", &n);
    ans = n / 4;
    n %= 4;

    if(n == 1){
      if(ans > 1)
        --ans;
      else
        ans = 0;
    }

    if(n == 3){
      if(ans >= 3)
        --ans;
      else
        ans = 0;
    }

    if(ans == 0)
      ans = -1;

    printf("%d\n", ans);
  }

  return 0;
}
