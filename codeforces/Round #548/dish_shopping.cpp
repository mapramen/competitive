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
#define N 300001

int p[N], s[N], b[N], inc[N], pref[N], T[N], ans[N];
vector< vector< pii > > queries(N);
vector<int> vR;

void RemoveDuplicates(vector<int> &v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedValue(vector<int> &v, int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Solve(){
  vector<int> v;
  for(int i = 1; i < N; ++i){
    for(auto query : queries[i]){
      v.push_back(query.first);
    }
  }
  RemoveDuplicates(v);

  for(int j = 1; j < N; ++j){
    for(auto query : queries[j]){
      int i = GetCompressedValue(v, query.first);
      int x = query.second;

      if(x < 2){
        Update(i, x);
      }
      else{
        ans[x - 1] += Query(i);
      }
    }
  }
}

void AddToQuery(int i, int x, int y){
  queries[i].push_back(make_pair(x, y));
}

void SolveLeftPart(int n, int m){
  for(int i = 1; i <= n; ++i){
    AddToQuery(GetCompressedValue(vR, p[i]), p[i] + b[i], 1);
    AddToQuery(GetCompressedValue(vR, s[i] + 1), p[i] + b[i], -1);
  }

  for(int i = 1; i <= m; ++i){
    AddToQuery(GetCompressedValue(vR, inc[i]), inc[i] + pref[i], i + 1);
  }

  Solve();
}

void SolveRightPart(int n, int m){
  for(int i = 1; i < N; ++i){
    T[i] = 0;
    queries[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    AddToQuery(GetCompressedValue(vR, p[i]), b[i] - p[i] + 1, -1);
    AddToQuery(GetCompressedValue(vR, s[i] + 1), b[i] - p[i] + 1, 1);
  }

  for(int i = 1; i <= m; ++i){
    AddToQuery(GetCompressedValue(vR, inc[i]), pref[i] - inc[i], i + 1);
  }

  Solve();
}

void TakeInput(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  TakeInput(n, p);
  TakeInput(n, s);
  TakeInput(n, b);
  TakeInput(m, inc);
  TakeInput(m, pref);

  for(int i = 1; i <= n; ++i){
    vR.push_back(p[i]);
    vR.push_back(s[i] + 1);
  }

  for(int i = 1; i <= m; ++i){
    vR.push_back(inc[i]);
  }

  RemoveDuplicates(vR);
  
  SolveLeftPart(n, m);
  SolveRightPart(n, m);

  for(int i = 1; i <= m; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}