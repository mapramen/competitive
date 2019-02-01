#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int x[N], y[N];

int main(){
  int n, x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
    x1 = min(x1, x[i]), x2 = max(x2, x[i]);
    y1 = min(y1, y[i]), y2 = max(y2, y[i]);
  }

  vector<int> v;
  for(int i = 1; i <= n; ++i){
    if(x[i] == x1 || x[i] == x2 || y[i] == y1 || y[i] == y2){
      v.PB(i);
    }
  }

  int ans4 = 0, ans3 = 0;
  for(int i = 0; i < v.size(); ++i){
    int j = (i + 1) % v.size();
    x1 = x[v[i]], x2 = x[v[j]], y1 = y[v[i]], y2 = y[v[j]];
    ans4 += (abs(x1 - x2) + abs(y1 - y2));
  }

  for(int i = 0; i < v.size(); ++i){
    for(int j = i + 1; j < v.size(); ++j){
      x1 = x[v[i]], x2 = x[v[j]], y1 = y[v[i]], y2 = y[v[j]];
      for(int k = 1; k <= n; ++k){
        if(k == v[i] || k == v[j]){
          continue;
        }
        ans3 = max(ans3, abs(x[k] - x1) + abs(x[k] - x2) + abs(y[k] - y1) + abs(y[k] - y2) + abs(x1 - x2) + abs(y1 - y2));
      }
    }
  }

  printf("%d ", ans3);
  for(int k = 4; k <= n; ++k){
    printf("%d ", ans4);
  }
  printf("\n");

  return 0;
}
