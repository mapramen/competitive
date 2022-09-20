#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

vector<vector<int>> V(N);
priority_queue<int> Q;

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int g, d;
    scanf("%d%d", &g, &d);
    V[d].push_back(g);
  }

  int ans = 0;
  for(int k = N - 1; k != 0; --k){
    for(int g: V[k]){
      Q.push(g);
    }

    if(!Q.empty()){
      ans += Q.top();
      Q.pop();
    }
  }

  printf("%d\n", ans);
  
  return 0;
}