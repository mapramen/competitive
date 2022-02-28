#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

bool IsLocalMaximum(int n, int i){
  return i > 1 && i < n && a[i] > a[i - 1] && a[i] > a[i + 1];
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int i = 2; i < n; ++i){
    if(IsLocalMaximum(n, i - 1) && IsLocalMaximum(n, i + 1)){
      a[i] = max(a[i - 1], a[i + 1]);
      ++ans;
    }
  }

  for(int i = 2; i < n; ++i){
    if(IsLocalMaximum(n, i)){
      a[i] = max(a[i - 1], a[i + 1]);
      ++ans;
    }
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}