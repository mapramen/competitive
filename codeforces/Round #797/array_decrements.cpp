#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

int a[N], b[N];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  int m = INT_MAX;
  for(int i = 1; i <= n && m == INT_MAX; ++i){
    if(b[i] != 0){
      m = a[i] - b[i];
    }
  }

  if(m < 0){
    return false;
  }

  if(m == INT_MAX){
    return true;
  }

  for(int i = 1; i <= n; ++i){
    if((b[i] == 0 && a[i] - b[i] > m) || (b[i] != 0 && a[i] - b[i] != m)){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}