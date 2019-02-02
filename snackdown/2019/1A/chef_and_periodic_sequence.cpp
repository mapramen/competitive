#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

bool IsInfinitePeriod(int n){
  int k;
  for(k = 1; k <= n && a[k] == -1; ++k);
  if(k > n){
    return 1;
  }
  for(int i = k + 1; i <= n; ++i){
    if(a[i] == -1){
      continue;
    }
    int x = a[k] + i - k;
    if(a[i] != x){
      return 0;
    }
  }
  for(int i = k - 1; i > 0; --i){
    if(a[i] == -1){
      continue;
    }
    int x = a[k] + i - k;
    if(x < 0 || a[i] != x){
      return 0;
    }
  }
  return 1;
}

bool Check(int n, int m){
  int k;
  for(k = 1; k <= n && a[k] == -1; ++k);
  for(int i = k + 1; i <= n; ++i){
    if(a[i] == -1){
      continue;
    }
    if(a[i] != (a[k] + i - k) % m){
      return 0;
    }
  }
  for(int i = k - 1; i > 0; --i){
    if(a[i] == -1){
      continue;
    }
    if(a[i] != (a[k] + m + ((i - k) % m)) % m){
      return 0;
    }
  }
  return 1;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
      if(a[i] > 0){
        --a[i];
      }
    }

    if(IsInfinitePeriod(n)){
      printf("inf\n");
      continue;
    }

    vector<int> v;
    for(int i = 1; i <= n; ++i){
      if(a[i] >= 0){
        v.PB(i - (a[i] + 1));
      }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int ans = 0;
    int x = 0;
    for(int i = 0; i < v.size() - 1; ++i){
      x = __gcd(x, v[i + 1] - v[i]);
    }

    for(int d = x; d > 0 && ans == 0; --d){
      if(x % d != 0){
        continue;
      }
      if(Check(n, d)){
        ans = d;
      }
    }

    if(ans){
      printf("%d\n", ans);
    }
    else{
      printf("impossible\n");
    }
  }

  return 0;
}
