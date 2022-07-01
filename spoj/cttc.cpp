#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int c[N];
bool visited[N];
stack<int> S;

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    visited[i] = false;
  }

  for(int x = 1; x <= 2 * n; ++x){
    int i;
    scanf("%d", &i);

    if(!visited[i]){
      S.push(i);
      visited[i] = true;
      continue;
    }

    int ans = 0;
    while(!S.empty() && S.top() != i){
      S.pop();
      ++ans;
    }

    c[i] = ans;
  }

  S.pop();

  for(int i = 1; i <= n; ++i){
    printf("%d -> %d\n", i, c[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}