#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m, e, ans = 0;
    vector< pii > C(1);
    vector<int> D(1), v(1);

    scanf("%d%d%d", &n, &m, &e);

    for(int i = 1; i <= n; i++){
      int a;
      scanf("%d", &a);
      C.PB(MP(a - e, a + e));
    }

    for(int j = 1; j <= m; j++){
      int a;
      scanf("%d", &a);
      D.PB(a);
    }

    sort(C.begin() + 1, C.end());
    sort(D.begin() + 1, D.end());

    for(auto d : D){
      for(auto p : C){
        int l, r;
        tie(l, r) = p;
        v.PB(d - l);
        v.PB(d - r);
      }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto x : v){
      int ansx = 0;
      priority_queue< int, vector<int>, greater<int> > Q;

      for(int i = 1; i <= n; i++){
        C[i].first += x;
        C[i].second += x;
      }

      for(int j = 1, i = 1; j <= m; j++){
        for( ; i <= n && C[i].first <= D[j]; i++)
          Q.push(C[i].second);

        while(!Q.empty() && Q.top() < D[j])
          Q.pop();

        if(!Q.empty()){
          ansx++;
          Q.pop();
        }
      }

      for(int i = 1; i <= n; i++){
        C[i].first -= x;
        C[i].second -= x;
      }

      ans = max(ans, ansx);
    }

    printf("%d\n", ans);
  }

  return 0;
}
