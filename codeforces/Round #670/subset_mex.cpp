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
#define N 101

int c[N];

void Reset(){
  for(int i = 0; i < N; ++i){
    c[i] = 0;
  }
}

int GetMex(){
  for(int i = 0; i < N; ++i){
    if(c[i] == 0){
      return i;
    }
    --c[i];
  }
  return N;
}

int Solve(){
  int n;

  Reset();
  
  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  return GetMex() + GetMex();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }  
  return 0;
}