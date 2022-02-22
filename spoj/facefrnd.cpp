#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000

bool frnd[N], frnd_of_frnd[N];

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int x, m;
    scanf("%d%d", &x, &m);

    frnd[x] = true;
    while(m--){
      int y;
      scanf("%d", &y);
      frnd_of_frnd[y] = true;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; ++i){
    ans += (!frnd[i] && frnd_of_frnd[i]);
  }

  printf("%d\n", ans);
  
  return 0;
}