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

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for(int i = N - 1; i > 0; --i){
    int x = 0;
    for(int j = i; j < N && x < 2; j += i){
      x += c[j];
    }
    if(x >= 2){
      printf("%d\n", i);
      break;
    }
  }
  
  return 0;
}