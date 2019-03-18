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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 3

char s[N];
int a[N], prefixCount[B], suffixCount[B];

int TakeInput(){
  int n;
  scanf("%d%s", &n, s);
  for(int i = 1; i <= n; ++i){
    a[i] = s[i - 1] - '0';
  }
  return n;
}

void InitialiseCount(int n){
  for(int i = 0; i < B; ++i){
    prefixCount[i] = 0;
    suffixCount[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    ++suffixCount[a[i]];
  }
}

int main(){
  int n = TakeInput();

  for(int x = 0, m = n / B; x < B; ++x){
    InitialiseCount(n);
    
    if(suffixCount[x] >= m){
      continue;
    }

    for(int i = 1; i <= n && prefixCount[x] + suffixCount[x] < m; ++i){
      int y = a[i];

      if(y < x){
        ++prefixCount[y];
        if(prefixCount[y] > m){
          a[i] = x;
          --prefixCount[y];
          ++prefixCount[x];
        }
      }
      else if(y > x){
        if(suffixCount[y] > m){
          a[i] = x;
          ++prefixCount[x];
        }
        else{
          ++prefixCount[y];
        }
      }
      else{
        ++prefixCount[y];
      }
      --suffixCount[y];
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d", a[i]);
  }
  printf("\n");

  return 0;
}