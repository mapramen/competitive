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
#define N 2000001
#define B 26

vector< vector<int> > adj(N);
int T[N][B], c[N], parent[N], length[N], a[N], nxt;
char s[N];

void Reset(){
  for(int i = nxt; i > -1; --i){
    c[i] = 0;
  }
  nxt = 0;
}

void AddString(){
  int i = 0;
  ++c[0];
  for(int j = 0; s[j] != '\0'; ++j){
    int k = s[j] - 'A';
    if(T[i][k]){
      i = T[i][k];
    }
    else{
      i = T[i][k] = ++nxt;
      length[i] = j + 1;
    }
    ++c[i];
  }
}

void UpdateNode(int i, int m){
  a[i] = c[i] >= m ? i : 0;
  for(int j : adj[i]){
    if(length[a[j]] > length[a[i]]){
      a[i] = a[j];
    }
  }
}

void Initialise(int m){
  for(int i = nxt; i > -1; --i){
    adj[i].clear();
    for(int j = 0; j < B; ++j){
      if(T[i][j]){
        parent[T[i][j]] = i;
        adj[i].push_back(T[i][j]);
        T[i][j] = 0;
      }
    }
    UpdateNode(i, m);
  }
}

void DecreaseAndUpdateNode(int i, int m){
  c[i] -= m;
  UpdateNode(i, m);
}

int ExtractMax(int m){
  if(length[a[0]] == 0){
    return 0;
  }

  const int ans = length[a[0]];
  for(int i = a[0]; i > 0; i = parent[i]){
    DecreaseAndUpdateNode(i, m);
  }
  DecreaseAndUpdateNode(0, m);

  return ans;
}

int Solve(){
  int n, m;

  scanf("%d%d", &n, &m);
  
  while(n--){
    scanf("%s", s);
    AddString();
  }

  Initialise(m);

  int ans = 0;
  for(int x = ExtractMax(m); x > 0; x = ExtractMax(m)){
    ans += x;
  }

  Reset();

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}