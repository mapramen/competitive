#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], t[N], l[N], r[N];

int main(){
  int n, q, m;

  scanf("%d%d%d", &n, &q, &m);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= q; ++i)
    scanf("%d%d%d", &t[i], &l[i], &r[i]);

  for(int i = 1; 2 * i <= q; ++i){
    swap(t[i], t[q - i + 1]);
    swap(l[i], l[q - i + 1]);
    swap(r[i], r[q - i + 1]);
  }

  while(m--){
    int b;
    scanf("%d", &b);
    for(int i = 1; i <= q; ++i){
      if(b < l[i] || r[i] < b)
        continue;
      if(t[i] == 1)
        b = (b == l[i]) ? r[i] : b - 1;
      else
        b = r[i] + l[i] - b;
    }
    printf("%d ", a[b]);
  }
  printf("\n");

  return 0;
}
