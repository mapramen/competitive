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
#define N 50001
#define B 26

vector< vector<int> > adj(N);
int T[N][B], nxt = 0;
int C[N];

void AddString(string s, int x){
  reverse(s.begin(), s.end());
  int i = 0, l = 0;
  for(char c : s){
    int k = c - 'A';
    if(T[i][k] == 0){
      T[i][k] = ++nxt;
      adj[i].push_back(nxt);
    }
    i = T[i][k];
    ++C[i];
  }
}

void Reset(){
  for(int i = 0; i < N; ++i){
    for(int k = 0; k < B; ++k){
      T[i][k] = 0;
    }
    C[i] = 0;
    adj[i].clear();
  }
  nxt = 0;
}

void DFS(int i){
  for(int j : adj[i]){
    DFS(j);
    C[i] -= C[j];
  }
  
  C[i] = max(0, C[i]);
  C[i] = (C[i] >= 2) ? 2 : 0;

  for(int j : adj[i]){
    C[i] += C[j];
  }
}

int Solve(){
  int n;
  cin >> n;

  Reset();

  while(n--){
    string s;
    cin >> s;
    AddString(s, n);
  }

  DFS(0);

  return C[0];
}

int main(){
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    printf("Case #%d: %d\n", i, Solve());
  }
  return 0;
}