#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int a[N], even[N], odd[N], ans[N];

int main(){
  int n, m;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    ans[1] = max(ans[1], a[i]);
  }

  if(n >= 2){
    for(int i = 1; i < n; i++){
      int ansx = max(a[i], a[i + 1]);
      int j = min(i, n - i);
      even[j] = max(even[j], ansx);
    }
  }

  if(n >= 3){
    for(int i = 2; i < n; i++){
      int ansx = min(a[i], max(a[i - 1], a[i + 1]));
      int j = min(i - 1, n - i);
      odd[j] = max(odd[j], ansx);
    }
  }

  m = n / 2;
  for(int i = m - 1; i > 0; i--)
    even[i] = max(even[i], even[i + 1]);

  for(int i = 1; i <= m; i++)
    ans[i + i] = even[i];

  m = (n + 1) / 2;
  for(int i = m - 1; i > 0; i--)
    odd[i] = max(odd[i], odd[i + 1]);

  for(int i = 1; i <= m; i++)
    ans[i + i + 1] = odd[i];

  for(int i = n; i > 0; i--)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
