#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  string s;
  cin >> s;

  stack<pii> S;
  vector<pii> ans;
  for(int i = 1; i <= n; ++i){
    int x = i, dx = s[i - 1] - '0';
    while(!S.empty() && S.top().first != dx){
      int dy, y;
      tie(dy, y) = S.top();
      S.pop();

      ans.push_back({x, y});

      x = dx == 0 ? x : y;
      dx = 1;
    }
    S.push({dx, x});
  }

  if(S.top().first == 0 || S.size() % 2 == 1){
    printf("NO\n");
    return;
  }

  for(int x = 0; !S.empty(); S.pop()){
    int y = S.top().second;
    if(x != 0){
      ans.push_back({x, y});
    }
    else{
      x = y;
    }
  }

  printf("YES\n");
  for(auto [x, y]: ans){
    printf("%d %d\n", x, y);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}