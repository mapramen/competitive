#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

priority_queue<int> Q;

int main(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);

    if(i % 2 == 0){
      ans -= Q.top();
      Q.pop();
    }

    ans += x;
    Q.push(x - y);
  }

  printf("%d\n", ans);
  
  return 0;
}