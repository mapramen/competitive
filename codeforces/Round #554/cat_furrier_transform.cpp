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

int MSB(int n){
  int ans = 0;
  for( ; n; n /= 2){
    ++ans;
  }
  return ans;
}

int main(){
  int n;
  vector<int> ans;

  cin >> n;
  while((n & (n + 1)) != 0 && (n < 2 || (n & (n - 1)) != 0)){
    int m = MSB(n);
    n ^= ((1 << m) - 1);
    ans.push_back(m);
    ++n;
    ans.push_back(0);
  }

  if(n > 1 && (n & (n - 1)) == 0){
    ans.push_back(MSB(n) - 1);
  }

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i += 2){
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}