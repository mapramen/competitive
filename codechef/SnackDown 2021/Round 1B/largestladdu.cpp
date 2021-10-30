#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 13
#define N (1 << B) + 1

ll a[N], b[N];

void FillB(ll s, int l, int r){
  if(l == r){
    b[l] = s;
    return;
  }

  ll s1 = s / 2, s2 = s - s1;
  int mid = (l + r) / 2;

  FillB(s1, l, mid);
  FillB(s2, mid + 1, r);
}

bool AreEqual(int m){
  sort(a + 1, a + m + 1);
  sort(b + 1, b + m + 1);
  for(int i = 1; i <= m; ++i){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  ll s = 0;
  for(int m = (1 << n), i = 1; i <= m; ++i){
    scanf("%lld", &a[i]);
    s += a[i];
  }

  FillB(s, 1, (1 << n));

  return AreEqual(1 << n);
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }

  return 0;
}