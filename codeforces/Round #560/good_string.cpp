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

  string ans;
  for(int i = 0; i < n; ){
    int j = i, k = 0;
    for( ; j < n && s[j] == s[i]; ++j, ++k);
    if(ans.size() % 2 == 0){
      ans.push_back(s[i]);
    }
    else{
      k = min(k, 2);
      while(k--){
        ans.push_back(s[i]);
      }
    }
    i = j;
  }

  if(ans.size() % 2){
    ans.pop_back();
  }

  cout << s.size() - ans.size() << '\n';
  cout << ans << '\n';
  
  return 0;
}