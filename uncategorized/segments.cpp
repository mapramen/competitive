#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

priority_queue<int> Q[N];

int main(){
  int n;

  cin >> n;

  for(int i = 0; i < n; ++i)
    for(int j = i + 1; j <= n; ++j)
      Q[i].push(j);

  int ans = 0;
  while(true){
    int i = 0;
    for(int x = 0; x < n; ++x){
      if(x >= i && Q[x].size()){
        i = Q[x].top();
        Q[x].pop();
      }
    }
    if(i == 0)
      break;
    ++ans;
  }

  cout << ans << '\n';

  return 0;
}
