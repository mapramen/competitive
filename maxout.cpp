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
    int n, m = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      scanf("%d", &a[i]);
      m = max(m, a[i]);
    }
    for(int i = 1; i <= n; i++)
      ans = max(ans, a[i] % m);
    printf("%d\n", ans);
  }

  return 0;
}
