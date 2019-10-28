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
#define N 200001

char s[N];
int a[N];

int main(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1, k = 0; i <= n; ++i){
    char c = s[i - 1];
    if(c == '('){
      ++k;
    }
    a[i] = k % 2;
    if(c == ')'){
      --k;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d", a[i]);
  }
  printf("\n");

  return 0;
}