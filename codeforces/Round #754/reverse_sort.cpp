#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  string s;

  cin >> n >> s;
  
  string t = string(s);
  sort(t.begin(), t.end());

  vector<int> v;
  for(int i = 0; i < n; ++i){
    if(s[i] != t[i]){
      v.push_back(i + 1);
    }
  }

  printf("%d\n", v.empty() ? 0 : 1);

  if(v.empty()){
    return;
  }

  printf("%lu ", v.size());
  for(int x: v){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}