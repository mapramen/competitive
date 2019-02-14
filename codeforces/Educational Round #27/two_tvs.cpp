#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

pii a[N];

int main(){
  int n, x = -1, y = -1;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].first, &a[i].second);

  sort(a + 1, a + n + 1);

  for(int i = 1; i <= n; ++i){
    int l, r;
    tie(l, r) = a[i];
    if(l > x)
      x = r;
    else if(l > y)
      y = r;
    else{
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
