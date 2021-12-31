#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Calculate(vector<int>&a, int x, int y){
  set<int> S;

  for(int i = 0; i <= x; ++i){
    for(int j = 0; j <= y; ++j){
      S.insert(i + 2 * j);
    }
  }

  int c = 0;
  for(int i: a){
    int cx = INT_MAX / 2;
    for(int j: S){
      if(j <= i && (i - j) % 3 == 0){
        cx = min(cx, (i - j) / 3);
      }
    }
    c = max(c, cx);
  }

  return x + y + c;
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = INT_MAX;
  for(int i = 0; i < 6; ++i){
    for(int j = 0; j < 3; ++j){
      ans = min(ans, Calculate(a, i, j));
    }
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