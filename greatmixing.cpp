#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define BASE 500 * 1000

bool mark[N];
int dp[2 * BASE + 1];
vector< int > cokes;

int main(){
  int n, k;
  queue<int> q;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= k; i++){
    int j;
    scanf("%d", &j);
    mark[j] = 1;
  }

  for(int i = 0; i < N; i++)
    if(mark[i])
      cokes.PB(i);

  for(int i = 0; i < cokes.size(); i++)
    cokes[i] -= n;

  q.push(BASE);
  while(!q.empty() && dp[BASE] == 0){
    int i = q.front();
    q.pop();

    for(auto j : cokes){
      int k = i + j;
      if(k >= 0 && k <= BASE && dp[k] == 0){
        dp[k] = dp[i] + 1;
        q.push(k);
      }
    }
  }

  if(dp[BASE] == 0)
    dp[BASE] = -1;

  printf("%d\n", dp[BASE]);

  return 0;
}
