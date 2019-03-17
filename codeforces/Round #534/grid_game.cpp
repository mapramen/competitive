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

int main(){
  string s;
  int verticalCount = 0, horizontalCount = 0;

  cin >> s;
  for(char c : s){
    if(c == '0'){
      cout << 1 + 2 * verticalCount << ' ' << 1 << '\n';
      verticalCount = 1 - verticalCount;
    }
    else{
      cout << 4 << ' ' << 3 - 2 * horizontalCount << '\n';
      horizontalCount = 1 - horizontalCount;
    }
  }

  return 0;
}