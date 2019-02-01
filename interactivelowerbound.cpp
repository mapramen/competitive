#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50001

int a[N];

int main(){
  int n, start, x, m, k;
  srand(clock());

  scanf("%d%d%d", &n, &start, &x);

  for(int i = 1; i <= n; ++i)
    a[i] = i;

  random_shuffle(a + 1, a + n + 1);

  m = -1, k = start;
  for(int i = 1; i <= min(n, 999); ++i){
    printf("? %d\n", a[i]);
    fflush(stdout);
    int v, nxt;
    scanf("%d%d", &v, &nxt);
    if(v <= x && v > m){
      m = v;
      k = a[i];
    }
  }

  for(int i = 1; i <= 1000 && k != -1; ++i){
    printf("? %d\n", k);
    fflush(stdout);
    int v, nxt;
    scanf("%d%d", &v, &nxt);
    if(x <= v){
      m = v;
      break;
    }
    k = nxt;
  }

  if(m < x)
    m = -1;

  printf("! %d\n", m);
  fflush(stdout);

  return 0;
}
