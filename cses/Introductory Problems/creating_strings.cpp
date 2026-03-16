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
  sort(s.begin(), s.end());

  vector<string> ans;
  do{
    ans.push_back(s);
  } while(next_permutation(s.begin(), s.end()));

  cout << ans.size() << '\n';
  for(auto s: ans){
    cout << s << '\n';
  }

  return 0;
}