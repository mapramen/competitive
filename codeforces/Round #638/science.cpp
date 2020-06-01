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

vector<int> Solve(int n){
  vector<int> ans;

  for(int i = 1; i <= n; n -= i, i *= 2){
    ans.push_back(i);
  }

  if(n){
    ans.push_back(n);
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    
    auto ans = Solve(n);

    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); ++i){
      cout << ans[i] - ans[i - 1] << ' ';
    }
    cout << '\n';
  }
  return 0;
}