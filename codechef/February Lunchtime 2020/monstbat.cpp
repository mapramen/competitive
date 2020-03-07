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
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001

int a[N];
char ch[N];
ll s[2], dp[2 * N];

priority_queue<int> P[2];
priority_queue<int> Q[2];

void Clear(priority_queue<int> &Q){
  for( ; !Q.empty(); Q.pop());
}

ll ReadMonsters(int n, priority_queue<int> &P, priority_queue<int> &Q){
  Clear(P), Clear(Q);

  for(int i = 0; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  scanf("%s", ch);

  ll s = 0;
  for(int i = 0; i < n; ++i){
    s += a[i];
    if(ch[i] == 'A'){
      P.push(-a[i]);
    }
    else{
      Q.push(a[i]);
    }
  }

  return s;
}

ll Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  s[0] = ReadMonsters(n, P[0], Q[0]);
  s[1] = ReadMonsters(m, P[1], Q[1]);

  int cur = 0, nxt =  1 - cur, i = 0;
  for( ; ; ++i, swap(cur, nxt)){
    dp[i] = s[0] - s[1];

    if(P[cur].empty() || Q[nxt].empty()){
      break;
    }

    Q[cur].push(-P[cur].top());
    P[cur].pop();

    s[nxt] -= Q[nxt].top();
    Q[nxt].pop();
  }

  for(--i, swap(cur, nxt); i > -1; --i, swap(cur, nxt)){
    if(cur == 0){
      dp[i] = max(dp[i], dp[i + 1]);
    }
    else{
      dp[i] = min(dp[i], dp[i + 1]);
    }
  }

  return dp[0];
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}