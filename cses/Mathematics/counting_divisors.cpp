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
#define N 1000001

int c[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      ++c[j];
    }
  }
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    printf("%d\n", c[n]);
  }
  
  return 0;
}