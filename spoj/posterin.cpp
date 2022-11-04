#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

stack<int> S;

int main(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  while(n--){
    int d, w;
    scanf("%d%d", &d, &w);

    while(!S.empty() && S.top() > w){
      ++ans;
      S.pop();
    }

    if(S.empty() || S.top() != w){
      S.push(w);
    }
  }

  ans += S.size();

  printf("%d\n", ans);

  return 0;
}