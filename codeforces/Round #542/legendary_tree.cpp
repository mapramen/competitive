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

int n;
vector< pii > edges;

void PrintQuerySet(vector<int> v){
  printf("%lu\n", v.size());
  for(int x : v){
    printf("%d ", x);
  }
  printf("\n");
}

int Query(vector<int> S, vector<int> T, int v){
  if(S.size() == 0 || T.size() == 0 || v == 0){
    return 0;
  }

  PrintQuerySet(S);
  PrintQuerySet(T);
  printf("%d\n", v);
  fflush(stdout);
  
  int x;
  scanf("%d", &x);
  return x;
}

int QuerySubtreeSize(int i){
  vector<int> S{1}, T;
  for(int j = 2; j <= n; ++j){
    if(j != i){
      T.push_back(j);
    }
  }
  return Query(S, T, i);
}

int BinarySearchChild(int i, vector<int>& T){
  vector<int> S{1};
  int x = 0, y = T.size() - 1, ans = 0;
  
  while(x <= y){
    int mid = x + (y - x) / 2;
    int k = Query(S, vector<int>(T.begin(), T.begin() + mid + 1), i);
    if(k){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  
  int j = T[ans];
  T.erase(T.begin() + ans);

  return j;
}

int main(){
  scanf("%d", &n);

  vector< pii > v;
  for(int i = 2; i <= n; ++i){
    v.push_back(make_pair(QuerySubtreeSize(i), i));
  }
  sort(v.begin(), v.end());

  vector<int> T;
  for(pii p : v){
    int i = p.second;
    vector<int> S{1};

    int k = Query(S, T, i);
    while(k--){
      edges.push_back(make_pair(i, BinarySearchChild(i, T)));
    }

    T.push_back(i);
  }

  for( ; T.size(); T.pop_back()){
    edges.push_back(make_pair(1, T.back()));
  }

  printf("ANSWER\n");
  for(pii p : edges){
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}