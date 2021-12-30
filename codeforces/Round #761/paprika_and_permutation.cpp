#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bool visited[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    visited[i] = false;
  }

  vector<int> a;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    if(x > n || visited[x]){
      a.push_back(x);
      continue;
    }

    visited[x] = 1;
  }
  sort(a.begin(), a.end(), greater<int>());
  
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }

    if(a.back() < 2 * i + 1){
      ans = -1;
      break;
    }

    a.pop_back();
    ++ans;
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