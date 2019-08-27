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
#define N 100001
#define B 18
#define M (1 << B)

int a[N];
char s[2];

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M];

void inline UpdateNode(int k, int x){
  if(x == 1){
    T[k] ^= 1;
  }
  else{
    T[k] = x;
  }
}

void LazyUpdateChildren(int k){
  if(T[k] == 0){
    return ;
  }

  UpdateNode(2 * k + 1, T[k]);
  UpdateNode(2 * k + 2, T[k]);
  T[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < ql || qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
}

int Query(int k, int l, int r, int i){
  if(i < l || r < i){
    return INT_MIN;
  }

  if(l == i && r == i){
    return T[k];
  }

  LazyUpdateChildren(k);
  return max(Query(2 * k + 1, l, (l + r) / 2, i), Query(2 * k + 2, (l + r) / 2 + 1, r, i));
}
//-------------------------------------- Segment Tree Ends --------------------------------------//


int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(q--){
    int sgn;
    scanf("%s%d", s, &sgn);

    char c = s[0];
    int x = abs(sgn);
    sgn /= max(1, x);
    
    if(c == '<'){
      if(sgn < 0){
        Update(0, 0, N, x + 1, N, 2);
      }
      else{
        Update(0, 0, N, 0, x - 1, 1);
        Update(0, 0, N, x, N, 2);
      }
    }
    else{
      if(sgn < 0){
        Update(0, 0, N, 0, x - 1, 1);
        Update(0, 0, N, x, N, 3);
      }
      else{
        Update(0, 0, N, x + 1, N, 3);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    int x = Query(0, 0, N, abs(a[i]));
    
    if(x == 1){
      a[i] *= -1;
    }
    else if(x == 2){
      a[i] = abs(a[i]);
    }
    else if(x == 3){
      a[i] = -abs(a[i]);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
  
  return 0;
}