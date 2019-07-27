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
#define N 501
#define B 10

int A[N][N];

int main(){
  int n, m;
  
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &A[i][j]);
    }
  }

  for(int k = 0; k < B; ++k){
    int a = 0, b = 0, c = 0;
    
    for(int i = 1; i <= n; ++i){
      int x = 0;
      for(int j = 1; j <= m; ++j){
        x += ((A[i][j] & (1 << k)) > 0);
      }
      a += (x == m);
      b += (x == 0);
      c += (x != 0 && x != m);
    }

    for( ; a % 2 == 0 && c > 0; ++a, --c);

    if(a % 2){
      printf("TAK\n");
      for(int i = 1; i <= n; ++i){
        int x = 0, y = 0;
        for(int j = 1; j <= m; ++j){
          int z = ((A[i][j] & (1 << k)) > 0);
          if(z){
            x = j;
          }
          else{
            y = j;
          }
        }
        if(x == 0 || (y > 0 && c > 0)){
          printf("%d ", y);
          c -= (x > 0 && y > 0 && c > 0);
        }
        else{
          printf("%d ", x);
        }
      }
      printf("\n");
      return 0;
    }
  }

  printf("NIE\n");
  return 0;
}