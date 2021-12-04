#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Query(int l, int r){
  if(r <= l){
    return 0ll;
  }

  printf("? %d %d\n", l, r);
  fflush(stdout);

  ll x;
  scanf("%lld", &x);
  return x;
}

int FindI(int n){
  ll A = Query(1, n);

  int x = 1, y = n - 2, ans = x;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query(mid, n) < A){
      y = mid - 1;
    }
    else{
      x = mid + 1, ans = mid;
    }
  }

  return ans;
}

int FindNext(int n, int i){
  return Query(i, n) - Query(i + 1, n) + i + 1;
}

void Solve(){
  int n;
  scanf("%d", &n);

  int i = FindI(n);
  int j = FindNext(n, i);
  int k = FindNext(n, j) - 1;

  printf("! %d %d %d\n", i, j, k);
  fflush(stdout);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}