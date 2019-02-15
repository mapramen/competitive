#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], b[N], p[N];

int main(){
  int n, l, r;

  scanf("%d%d%d", &n, &l, &r);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d", &j);
    p[j] = i;
  }

  for(int i = 1, d = l - r - 1; i <= n; i++){
    int j = p[i];
    d++;
    b[j] = max(l, a[j] + d);
    if(b[j] > r){
      printf("-1\n");
      return 0;
    }
    d = b[j] - a[j];
  }

  for(int i = 1; i <= n; i++)
    printf("%d ", b[i]);
  printf("\n");

  return 0;
}
