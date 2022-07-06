#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000002

int c[N];

int main(){
  int n, m, w;
  scanf("%d%d%d", &n, &m, &w);

  while(n--){
    int l, r;
    scanf("%d%d", &l, &r);
    ++l, ++r;

    ++c[l], --c[r + 1];
  }

  for(int i = 1; i <= w; ++i){
    c[i] += c[i - 1];
  }

  while(m--){
    int i;
    scanf("%d", &i);
    ++i;
    printf("%d\n", c[i]);
  }
  
  return 0;
}