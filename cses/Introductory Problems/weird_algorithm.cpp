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
  ll n;
  scanf("%lld", &n);

  while(n != 1){
    printf("%lld ", n);
    n = (n % 2 == 1) ? (3 * n + 1) : (n / 2);
  }
  printf("1\n");

  return 0;
}