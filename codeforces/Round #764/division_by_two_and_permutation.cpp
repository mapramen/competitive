#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  priority_queue<int> Q;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  for( ; n != 0; --n){
    while(Q.top() > n){
      int x = Q.top();
      Q.pop();
      Q.push(x / 2);
    }

    if(Q.top() != n){
      return false;
    }

    Q.pop();
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