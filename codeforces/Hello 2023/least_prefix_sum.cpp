#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
priority_queue<int> Q;

void ResetQ(){
  for( ; !Q.empty(); Q.pop());
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll s = 0;
  int ans = 0;
  
  ResetQ();
  for(int i = m; i > 1; --i){
    if(a[i] > 0){
      Q.push(a[i]);
    }

    s += a[i];
    while(s > 0){
      int x = Q.top();
      Q.pop();
      ++ans, s -= 2 * x;
    }
  }

  s = 0;
  ResetQ();
  for(int i = m + 1; i <= n; ++i){
    if(a[i] < 0){
      Q.push(-a[i]);
    }

    s += a[i];
    while(s < 0){
      int x = Q.top();
      Q.pop();
      ++ans, s += 2 * x;
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