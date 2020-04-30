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
#define N 1001
#define M 1441

vector< vector<int> > additions(M), deletions(M);
char s[N];
queue<char> Q;

void Reset(){
  for(int i = 0; i < M; ++i){
    additions[i].clear();
    deletions[i].clear();
  }

  for(int i = 0; i < N; ++i){
    s[i] = '\0';
  }

  for( ; !Q.empty(); Q.pop());

  Q.push('C');
  Q.push('J');
}

string Solve(){
  int n;

  Reset();

  cin >> n;

  for(int x = 0; x < n; ++x){
    int i, j;
    cin >> i >> j;
    additions[i].push_back(x);
    deletions[j].push_back(x);
  }

  for(int i = 0; i < M; ++i){
    for(auto x : deletions[i]){
      Q.push(s[x]);
    }

    for(auto x : additions[i]){
      if(Q.empty()){
        return "IMPOSSIBLE";
      }
      s[x] = Q.front();
      Q.pop();
    }
  }

  return string(s);
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": " << Solve() << "\n";
  }
  return 0;
}