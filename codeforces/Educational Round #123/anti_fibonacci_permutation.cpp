#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int n, vector<int>& p){
  for(int i = 2; i < n; ++i){
    if(p[i] == p[i - 1] + p[i - 2]){
      return false;
    }
  }
  return true;
}

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n);
  for(int i = 0; i < n; ++i){
    p[i] = i + 1;
  }

  set<vector<int>> S;
  while(S.size() < n){
    while(!Check(n, p) || S.count(p) > 0){
      random_shuffle(p.begin(), p.end());
    }

    S.insert(p);
  }

  for(vector<int> v: S){
    for(int x: v){
      printf("%d ", x);
    }
    printf("\n");
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