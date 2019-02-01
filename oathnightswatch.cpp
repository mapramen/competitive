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
  int n, i, j, ans;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  sort(a + 1, a + n + 1);

  for(i = 2; i <= n && a[i] == a[1]; i++);
  for(j = n - 1; j > 0 && a[j] == a[n]; j--);
  ans = max(0, j - i + 1);

  printf("%d\n", ans);
  
  return 0;
}
