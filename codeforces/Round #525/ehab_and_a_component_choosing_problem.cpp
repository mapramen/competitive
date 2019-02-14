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
#define N 300001

vector< vector<int> > adj(N);
int a[N];
ll m = -2E18, c = 0;

ll CalculateMaxDFS(int i, int p){
  ll ans = a[i];
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    ans += max(0ll, CalculateMaxDFS(j, i));
  }
  m = max(m, ans);
  return ans;
}

ll CollectMaxCountDFS(int i, int p){
  ll ans = a[i];
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    ans += max(0ll, CollectMaxCountDFS(j, i));
  }
  if(ans == m){
    ++c, ans = 0;
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  CalculateMaxDFS(1, 0);
  CollectMaxCountDFS(1, 0);

  ll ansS = c * m, ansK = c;

  printf("%lld %lld\n", ansS, ansK);

  return 0;
}