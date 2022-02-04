#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    ans ^= x;
  }

  printf("%d\n", ans);
  
  return 0;
}