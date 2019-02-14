#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int main(){
  int n, m, c;

  scanf("%d%d%d", &n, &m, &c);

  vector<int> a(n + 1);

  for(int l = 1, r = n; l <= r && m > 0; --m){
    int x, k;
    scanf("%d", &x);

    if(2 * x <= c){
      for(k = 1; k < l && a[k] <= x; ++k);
      if(k == l)
        ++l;
    }
    else{
      for(k = n; k > r && a[k] >= x; --k);
      if(k == r)
        --r;
    }

    a[k] = x;
    printf("%d\n", k);
    fflush(stdout);
  }

  return 0;
}
