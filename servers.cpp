#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, q, t, k, d;
  priority_queue< int, vector<int>, greater<int> > freeServers;
  priority_queue< pii, vector< pii > , greater< pii > > occServers;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; i++)
    freeServers.push(i);

  while(q--){
    scanf("%d%d%d", &t, &k, &d);

    while(!occServers.empty() && occServers.top().first < t){
      int i = occServers.top().second;
      occServers.pop();
      freeServers.push(i);
    }

    int ans = 0;

    if(freeServers.size() < k)
      ans = -1;
    else{
      while(k--){
        int i = freeServers.top();
        freeServers.pop();
        occServers.push(MP(t + d - 1, i));
        ans += i;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
