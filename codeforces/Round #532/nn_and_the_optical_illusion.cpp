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

const double PI = 4 * atan(1.0);

int main(){
  int n, R;
  cin >> n >> R;
  double an = PI / n;
  double r = R / ((1 / sin(an)) - 1);
  printf("%.15lf\n", r);
  return 0;
}