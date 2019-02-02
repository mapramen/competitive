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
  int n, g = 0, ans;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    g = __gcd(g, a[i]);
  }

  if(g > 1)
    ans = 0;
  else{
    ans = 0;
    for(int i = 1; i <= n; i++){
      if(a[i] % 2 == 0)
        continue;
      int j, k = 1;
      for(j = i + 1; j <= n && a[j] % 2 == 1; j++, k++);
      ans += (k / 2) + 2 * (k % 2);
      i = j;
    }
  }

  printf("YES\n");
  printf("%d\n", ans);

  return 0;
}
