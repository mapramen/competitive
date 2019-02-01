#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1501

int a[N];

int main(){
  int n, m, parity = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      parity ^= (a[j] < a[i]);
    }
  }

  scanf("%d", &m);
  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    int x = r - l;
    parity ^= ((x + 3) % 4 < 2);
    if(parity)
      printf("odd\n");
    else
      printf("even\n");
  }

  return 0;
}
