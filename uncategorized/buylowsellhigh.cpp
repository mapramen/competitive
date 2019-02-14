#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  priority_queue< pii, vector< pii >, greater< pii > > Q;
  ll ans = 0;

  scanf("%d", &n);
  while(n--){
    int p;
    scanf("%d", &p);
    if(!Q.empty() && Q.top().first < p){
      int q, k;
      tie(q, k) = Q.top();
      Q.pop();

      ans += (p - q);

      if(k)
        Q.push(MP(q, 0));
      Q.push(MP(p, 1));
    }
    else
      Q.push(MP(p, 0));
  }

  printf("%lld\n", ans);

  return 0;
}
