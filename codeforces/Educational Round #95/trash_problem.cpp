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

#define pii pair<int,int>
#define pll pair<ll,ll>

set<int> S;
priority_queue<pii> Q;

int DistanceToNext(int x){
  if(*S.rbegin() == x){
    return 0;
  }

  auto it = S.find(x);
  if(it == S.end()){
    return 0;
  }

  return *next(it) - x;
}

void Add(int x){
  auto it = S.insert(x).first;

  if(it != S.begin()){
    int p = *prev(it);
    Q.push({x - p, p});
  }

  auto nt = next(it);
  if(nt != S.end()){
    Q.push({*nt - x, x});
  }
}

void Delete(int x){
  auto it = S.find(x);

  if(it == S.begin()){
    S.erase(it);
    return;
  }

  int p = *prev(it);
  S.erase(it);

  Q.push({DistanceToNext(p), p});
}

int QueryMaxGap(){
  while(!Q.empty() && DistanceToNext(Q.top().second) != Q.top().first){
    Q.pop();
  }
  return Q.top().first;
}

int Query(){
  if(S.size() <= 2){
    return 0;
  }

  return (*S.rbegin() - *S.begin()) - QueryMaxGap();
}

void PrintAns(){
  printf("%d\n", Query());
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  while(n--){
    int x;
    scanf("%d", &x);
    Add(x);
  }

  PrintAns();

  while(q--){
    int t, x;
    scanf("%d%d", &t, &x);

    if(t == 0){
      Delete(x);
    }
    else{
      Add(x);
    }

    PrintAns();
  }
  
  return 0;
}