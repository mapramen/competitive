#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], max_index[N], b[N], c[N];
bool visited[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    max_index[i] = 0, b[i] = 0, c[i] = 0, visited[i] = false;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    max_index[a[i]] = i;
  }

  for(int i = 1; i <= n; ++i){
    b[i] = max(b[i - 1], max_index[a[i]]);
    c[i] = c[i - 1] + !visited[a[i]];
    visited[a[i]] = true;
  }

  int ans = c[n];
  for(int i = n, x = INT_MAX; i != 0 && a[i] <= x; x = a[i], --i){
    if(b[i - 1] < i){
      ans = c[i - 1];
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}