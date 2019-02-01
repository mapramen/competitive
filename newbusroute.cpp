#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

int main(){
  int n, ans = INT_MAX, cnt = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  sort(a + 1, a + n + 1);

  for(int i = 2; i <= n; i++){
    int ansx = a[i] - a[i - 1];
    if(ansx < ans)
      ans = ansx, cnt = 1;
    else
      cnt += (ans == ansx);
  }

  printf("%d %d\n", ans, cnt);
  
  return 0;
}
