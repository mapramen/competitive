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
#define B 16
#define N (1 << B)

int a[N], c[N];

int Query(string s, int i, int j){
  printf("%s %d %d\n", s.c_str(), i + 1, j + 1);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

int FirstElement(int n){
  for(int i = 1; i < n; ++i){
    int k = a[i];
    
    if(k == 0){
      return Query("AND", 0, i);
    }

    if(c[k] != 0){
      return a[i] ^ Query("OR", c[k], i);
    }
    
    c[k] = i;
  }

  int i = 0, j = n - 1;
  for( ; c[i] == 0 || c[j] == 0; ++i, --j);

  return Query("AND", 0, c[i]) | Query("AND", 0, c[j]);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i < n; ++i){
    a[i] = Query("XOR", 0, i);
  }

  int x = FirstElement(n);
  printf("! ");
  for(int i = 0; i < n; ++i){
    printf("%d ", x ^ a[i]);
  }
  printf("\n");
  fflush(stdout);

  return 0;
}