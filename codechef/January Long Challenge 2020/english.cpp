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
#define N 200001
#define B 26

char s[N];
vector< vector<int> > adj(N);
int trie[N][B], c[N], h[N], cost[N], nextNode = 0;

void Reset(){
  for(int i = 0; i <= nextNode; ++i){
    for(int k = 0; k < B; ++k){
      if(trie[i][k]){
        trie[i][k] = 0;
      }
    }
    adj[i].clear();
    c[i] = 0;
    h[i] = 0;
    cost[i] = 0;
  }
  nextNode = 0;
}

void AddToTrie(int n){
  ++c[0];
  for(int x = 0, i = 0; x < n; ++x){
    int k = s[x] - 'a';
    if(trie[i][k] == 0){
      trie[i][k] = ++nextNode;
      adj[i].push_back(nextNode);
      i = nextNode;
      h[i] = x + 1;
    }
    else{
      i = trie[i][k];
    }
    ++c[i];
  }
}

void AddString(){
  int n = strlen(s);
  for(int i = n - 1, j = 2 * i; i > -1; --i, j -= 2){
    s[j] = s[i];
  }

  n *= 2;
  s[n] = '\0';
  for(int i = 0, j = n - 1; i < n; i += 2, j -= 2){
    s[j] = s[i];
  }

  AddToTrie(n);
}

void UpdateNode(int i){
  if(c[i] < 2){
    cost[i] = INT_MIN;
    return ;
  }

  cost[i] = h[i];
  for(int j : adj[i]){
    cost[i] = max(cost[i], cost[j]);
  }
}

void PreProcess(int i){
  for(int j : adj[i]){
    PreProcess(j);
  }
  UpdateNode(i);
}

int ExtractMax(int i){
  if(c[i] < 2){
    return 0;
  }

  int ans = cost[i], j = INT_MIN;
  for(int x : adj[i]){
    if(cost[x] == ans){
      j = x;
      break;
    }
  }

  c[i] -= 2;
  
  if(j != INT_MIN){
    ExtractMax(j);
  }
  
  UpdateNode(i);

  return ans / 2;
}

ll Solve(){
  int n;

  scanf("%d", &n);
  while(n--){
    scanf("%s", s);
    AddString();
  }

  PreProcess(0);

  ll ans = 0;
  for(int cost = ExtractMax(0); cost; cost = ExtractMax(0)){
    ans += 1ll * cost * cost;
  }

  Reset();

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}