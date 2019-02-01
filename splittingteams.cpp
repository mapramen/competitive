#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, o = 0, e = 0, ans = 0;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    if(i == 1)
      ++o;
    else
      ++e;
  }

  for(int i = 0; i <= e; ++i){
    int x = min(i, o), y = o - x;
    ans = max(ans, x + y / 3);
  }

  printf("%d\n", ans);
  
  return 0;
}
