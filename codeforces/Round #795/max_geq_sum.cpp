#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
ll s[N], max_sum[N], min_sum[N];
stack<int> S;
stack<ll> T;

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + a[i];
  }

  S.push(INT_MAX), T.push(0ll);
  for(int i = 1; i <= n; ++i){
    int x = a[i];
    ll value = s[i - 1];

    for( ; S.top() <= x; S.pop(), T.pop()){
      value = min(value, T.top());
    }

    min_sum[i] = value;
    S.push(x), T.push(value);
  }

  while(S.size() != 1){
    S.pop(), T.pop();
  }

  for(int i = n; i > 0; --i){
    int x = a[i];
    ll value = s[i];

    for( ; S.top() <= x; S.pop(), T.pop()){
      value = max(value, T.top());
    }

    max_sum[i] = value;
    S.push(x), T.push(value);
  }

  for(int i = 1; i <= n; ++i){
    if(max_sum[i] - min_sum[i] > a[i]){
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