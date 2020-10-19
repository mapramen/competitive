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

int main(){
  string s;
  cin >> s;

  int n = s.size();

  printf("3\n");
  printf("L %d\n", n - 1);
  printf("R %d\n", n - 1);
  printf("R %d\n", 2 * n - 1);
  
  return 0;
}