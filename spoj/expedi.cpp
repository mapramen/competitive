#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10002

pii a[N];
priority_queue<int> Q;

int Solve(){
  int n, m, d;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }

  scanf("%d%d", &d, &m);

  for(int i = 1; i <= n; ++i){
    a[i].first = d - a[i].first;
  }
  a[n + 1] = {d, 0};

  sort(a + 1, a + n + 1);
  for( ; !Q.empty(); Q.pop());

  int ans = 0;
  for(int i = 1; i <= n + 1; ++i){
    m -= (a[i].first - a[i - 1].first);
    
    while(!Q.empty() && m < 0){
      m += Q.top();
      ++ans;
      Q.pop();
    }

    if(m < 0){
      return -1;
    }
    
    Q.push(a[i].second);
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