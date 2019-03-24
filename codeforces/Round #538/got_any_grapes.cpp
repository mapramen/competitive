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

void Relax(int &x, int &a){
  int z = min(x, a);
  x -= z;
  a -= z;
}

int main(){
  int x, y, z, a, b, c;

  cin >> a >> b >> c;
  cin >> x >> y >> z;

  Relax(x, a);
  Relax(x, b);
  Relax(y, b);
  Relax(x, c);
  Relax(y, c);
  Relax(z, c);

  if(a + b + c == 0){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }

  return 0;
}