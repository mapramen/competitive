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

string Solve(){
  int n, k;
  string s;

  cin >> n >> k >> s;
  
  sort(s.begin(), s.end());

  if(k == 1){
    return s;
  }
  
  string ans;
  for(int i = 0; i < n; ){
    int j = min(i + k - 1, n - 1);

    if(ans.empty()){
      ans.push_back(s[j]);
      
      if(s[i] != s[j]){
        break;
      }

      i = j + 1;
      continue;
    }

    j = n - 1;

    if(s[i] == s[j]){
      int x = j - i + 1;
      ans += string((x / k) + (x % k > 0), s[i]);
    }
    else{
      ans += string(s, i);
    }
    break;
  }

  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}