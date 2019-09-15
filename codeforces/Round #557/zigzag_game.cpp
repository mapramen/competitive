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
#define N 51

vector< vector<int> > preferences(2 * N);
int a[N][N], matching[2 * N];
char ch[2];

void InitialisePreferences(int n, int x){
  for(int i = 1; i <= 2 * n; ++i){
    preferences[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    vector< pii > v;
    for(int j = 1; j <= n; ++j){
      v.push_back(make_pair(x * a[i][j], n + j));
    }
    sort(v.begin(), v.end());
    
    preferences[i].clear();
    for(auto p : v){
      preferences[i].push_back(p.second);
    }
    reverse(preferences[i].begin(), preferences[i].end());

    v.clear();
  }

  for(int i = 1; i <= n; ++i){
    preferences[n + i].resize(n + 1);
    preferences[n + i][0] = INT_MIN;
    
    for(int j = 1; j <= n; ++j){
      preferences[n + i][j] = x * a[j][i];  
    }
  }
}

void StableMarriage(int n){
  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    Q.push(i);
    matching[i] = 0;
    matching[n + i] = 0;
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    while(!preferences[i].empty()){
      int j = preferences[i].back();
      preferences[i].pop_back();

      int k = matching[j];

      if(preferences[j][i] > preferences[j][k]){
        matching[i] = j;
        if(k){
          Q.push(k);
        }
        matching[j] = i;
        break;
      }
    }
  }
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        scanf("%d", &a[i][j]);
      }
    }

    puts("B");
    fflush(stdout);

    int start;
    scanf("%s%d", ch, &start);

    int x = ((ch[0] == 'I') ^ (start > n)) ? 1 : -1;
    InitialisePreferences(n, x);
    StableMarriage(n);

    while(start > 0){
      printf("%d\n", matching[start]);
      fflush(stdout);
      scanf("%d", &start);
    }
  }

  return 0;
}