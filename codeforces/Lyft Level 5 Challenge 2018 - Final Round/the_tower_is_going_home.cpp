#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> C, T;

int main(){
  int n, m;
  priority_queue< pii, vector< pii >, greater< pii > > Q1, Q2;

  scanf("%d%d", &n, &m);

  while(n--){
    int x;
    scanf("%d", &x);
    C.PB(x + 1);
  }

  while(m--){
    int x1, x2, y;
    scanf("%d%d%d", &x1, &x2, &y);
    Q1.push(MP(x1, x2));
  }

  C.PB(1);
  C.PB(1000000001);

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  int ans = INT_MAX;
  for(int i = 0; i < C.size() - 1; ++i){
    int l = C[i], r = C[i + 1] - 1;
    while(!Q1.empty() && Q1.top().first <= r){
      int x1, x2;
      tie(x1, x2) = Q1.top();
      Q1.pop();
      if(1 < x1 || x2 < r){
        continue;
      }
      if(x1 > l){
        Q1.push(MP(r, x2));
      }
      else{
        Q2.push(MP(x2, -x1));
      }
    }
    while(!Q2.empty() && Q2.top().first <= r){
      if(Q2.top().first == r && Q2.top().second == -1){
        break;
      }
      else{
        Q2.pop();
      }
    }
    ans = min(ans, i + (int)Q2.size());
  }

  printf("%d\n", ans);

  return 0;
}
