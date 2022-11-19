#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], b[N];

void TrySaturate(int n){
  int m = *max_element(b + 1, b + n + 1);

  for(int i = 2; i <= n; ++i){
    if(b[i] == m && b[i - 1] != m){
      b[i - 1] = 1E9;
      return;
    }
  }

  for(int i = 2; i <= n; ++i){
    if(b[i - 1] == m && b[i] != m){
      b[i] = 1E9;
      return;
    }
  }

  b[1] = 1E9;
}

bool Check(int n, int k, int m){
  int x = max(0, m - 1) / 2;

  for(int i = 1; i <= n; ++i){
    b[i] = a[i];
  }

  for(int i = 1; i <= n; ++i){
    if(b[i] <= x){
      b[i] = 1E9;
      --k;
    }
  }

  if(k < 0){
    return false;
  }

  for(int i = 1; i <= min(2, k); ++i){
    TrySaturate(n);
  }

  for(int i = 2; i <= n; ++i){
    if(b[i - 1] >= m && b[i] >= m){
      return true;
    }
  }

  return false;
}

int BinarySearch(int n, int k){
  int x = 1, y = 1E9, ans = 1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, k, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  return BinarySearch(n, k);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}