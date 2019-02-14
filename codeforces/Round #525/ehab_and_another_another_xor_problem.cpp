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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 29

void Print(char c, int a, int b){
  printf("%c %d %d\n", c, a, b);
  fflush(stdout);
}

int Query(int c, int d){
  Print('?', c, d);
  int x;
  scanf("%d", &x);
  return x;
}

void PrintAns(int c, int d){
  Print('!', c, d);
}

int main(){
  int c = 0, d = 0;
  int order = Query(c, d);
  
  for(int k = B; k > -1; --k){
    int one = (1 << k);
    int x1 = Query(c, d + one), x2 = Query(c + one, d);

    if(x1 < 0 && x2 > 0){
      continue;
    }

    if(x1 > 0 && x2 < 0){
      c += one, d += one;
      continue;
    }

    if(order > 0){
      c += one;
    }
    else{
      d += one;
    }

    order = x1;
  }

  PrintAns(c, d);

  return 0;
}