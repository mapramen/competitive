#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Solve(){
  int n;
  scanf("%d", &n);

  if(n == 3){
    return {};
  }

  int x, y;
  if(n % 2 == 0){
    x = 1, y = -1;
  }
  else{
    x = -(n / 2 - 1), y = n / 2;
  }

  vector<int> v;
  for(int i = 0; i < n; ++i){
    v.push_back(i % 2 == 0 ? x : y);
  }

  return v;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    vector<int> ans = Solve();
    if(ans.empty()){
      printf("NO\n");
      continue;
    }

    printf("YES\n");
    for(int x: ans){
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}