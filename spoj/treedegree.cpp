#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int degree[N];
stack<int> S;

void AddEdge(int i, int j){
  if(i == 0 || j == 0){
    return;
  }
  ++degree[i], ++degree[j];
}

int Solve(){
  int n;
  scanf("%d", &n);

  S.push(0);
  for(int i = 1; i <= 2 * n; ++i){
    int x;
    scanf("%d", &x);

    if(S.top() == x){
      S.pop();
      AddEdge(S.top(), x);
    }
    else{
      S.push(x);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, degree[i]);
    degree[i] = 0;
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