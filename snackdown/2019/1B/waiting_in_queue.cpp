#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, m, k, l;
    scanf("%d%d%d%d", &n, &m, &k, &l);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    int nextInTime = (m + 1) * l, ans = nextInTime;
    
    for(int i = 1; i <= n; ++i, nextInTime += l){
      if(nextInTime <= a[i]){
        ans = 0;
      }
      nextInTime = max(nextInTime, l * ((a[i] - 1) / l));
      int ansx = nextInTime - a[i];
      ans = min(ans, ansx);
    }

    ans = min(ans, max(0, nextInTime - k));

    printf("%d\n", ans);
  }

  return 0;
}
