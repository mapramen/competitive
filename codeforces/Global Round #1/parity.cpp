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

int main(){
  int b, n, ans = 0;

  scanf("%d%d", &b, &n);

  b %= 2;
  while(n--){
    int a;
    scanf("%d", &a);
    ans = (b * ans + a) % 2;
  }

  printf("%s\n", ans == 0 ? "even" : "odd");
  
  return 0;
}