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
  int n;
  string s;

  cin >> n >> s;

  char m = 'a' - 1;
  for(int i = 0, j = -1; i < n; ++i){
    if(s[i] > m){
      m = s[i], j = i;
    }
    if(s[i] < m){
      printf("YES\n%d %d\n", j + 1, i + 1);
      return 0;
    }
  }

  printf("NO\n");
  
  return 0;
}