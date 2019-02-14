#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int q, k = 0, m = 0;
  ll S = 0;
  priority_queue<int> Q1;
  priority_queue< int, vector<int>, greater<int> > Q2;

  scanf("%d", &q);

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int x;
      scanf("%d", &x);
      Q2.push(x);
      m = max(m, x);
    }
    else{
      S += m;
      ++k;

      while(!Q1.empty() && 1ll * Q1.top() * k >= S){
        int x = Q1.top();
        Q1.pop();
        S -= x;
        --k;
        Q2.push(x);
      }

      while(!Q2.empty() && 1ll * Q2.top() * k < S){
        int x = Q2.top();
        Q2.pop();
        S += x;
        ++k;
        Q1.push(x);
      }

      double ans = S;
      ans = m - ans / k;

      S -= m;
      --k;

      printf("%.15lf\n", ans);
    }
  }

  return 0;
}
