#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 200001

int a[N];

tiii Calculate(int l, int r, int x, int y){
  int sgn = 1, cnt = 0;
  for(int i = l; i <= r; ++i){
    cnt += (abs(a[i]) == 2);
    sgn = a[i] < 0 ? -sgn : sgn;
  }

  if(sgn == 1){
    return {cnt, x, y};
  }

  int x1 = x, y1 = y, sgn1 = sgn, cnt1 = cnt;
  for(int i = l; i <= r && sgn1 == -1; ++i, ++x1){
    cnt1 -= (abs(a[i]) == 2);
    sgn1 = a[i] < 0 ? -sgn1 : sgn1;
  }

  int x2 = x, y2 = y, sgn2 = sgn, cnt2 = cnt;
  for(int i = r; i >= l && sgn2 == -1; --i, ++y2){
    cnt2 -= (abs(a[i]) == 2);
    sgn2 = a[i] < 0 ? -sgn2 : sgn2;
  }

  return max(make_tuple(cnt1, x1, y1), make_tuple(cnt2, x2, y2));
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  tiii ans = {0, 0, n};
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      continue;
    }
    
    int j = i;
    for( ; j <= n && a[j] != 0; ++j);
    --j;
    
    ans = max(ans, Calculate(i, j, i - 1, n - j));
    i = j;
  }

  printf("%d %d\n", get<1>(ans), get<2>(ans));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}