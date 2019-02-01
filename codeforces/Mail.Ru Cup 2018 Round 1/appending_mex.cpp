#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

int c[N];

int main(){
  int n, m = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x > m){
      printf("%d\n", i);
      return 0;
    }
    ++c[x];
    for( ; c[m] > 0; ++m);
  }

  printf("-1\n");

  return 0;
}
