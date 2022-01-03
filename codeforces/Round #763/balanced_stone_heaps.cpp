#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N], b[N], c[N];

bool Check(int n, int m){
  for(int i = 1; i <= n; ++i){
    b[i] = a[i];
    c[i] = 0;
  }

  for(int i = n; i > 2; --i){
    ll d = max(0ll, b[i] - max(0ll, m - c[i]));
    d /= 3;

    b[i] -= 3 * d;
    c[i - 1] += d;
    c[i - 2] += 2 * d;
  }

  for(int i = 1; i <= n; ++i){
    if(b[i] + c[i] < m){
      return false;
    }
  }

  return true;
}

int BinarySearch(int n){
  int x = 0, y = 1E9, ans = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  return BinarySearch(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}