#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > v(N);
int dp[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(n--){
    int s, r;
    scanf("%d%d", &s, &r);
    v[s].push_back(r);
  }

  for(int i = 1; i <= m; ++i){
    sort(v[i].begin(), v[i].end(), greater<int>());
    for(int k = 0, s = 0; k < v[i].size(); ++k){
      s += v[i][k];
      if(s <= 0){
        break;
      }
      dp[k + 1] += s;
    }
  }

  int ans = 0;
  for(int k = 0; k < N; ++k){
    ans = max(ans, dp[k]);
  }

  printf("%d\n", ans);

  return 0;
}