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
  int t;
  cin >> t;
  while(t--){
    int n;
    string s;
    cin >> n >> s;
    
    int x = 0;
    for(int i = 0; i < s.size() && s[i] == '<'; ++i, ++x);

    int y = 0;
    for(int i = s.size() - 1; i > -1 && s[i] == '>'; --i, ++y);

    int ans = min(x, y);
    
    cout << ans << '\n';
  }
  return 0;
}