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
  string s;

  cin >> s;

  string t = s + s;

  int n = s.size();
  for(int i = 0; i < n; ++i){
    bool isPalindrome = true;
    for(int x = i, y = i + n - 1; x < y && isPalindrome; ++x, --y){
      isPalindrome = (t[x] == t[y]);
    }
    if(!isPalindrome){
      continue;
    }
    
    bool isEqualToOriginal = true;
    for(int x = 0, y = i; x < n && isEqualToOriginal; ++x, ++y){
      isEqualToOriginal = (s[x] == t[y]);
    }
    if(isEqualToOriginal){
      continue;
    }

    cout << 1 << '\n';
    return 0;
  }

  for(int i = 1; 2 * i <= n; ++i){
    if(s[i - 1] != s[0]){
      cout << 2 << '\n';
      return 0;
    }
  }

  cout << "Impossible\n";
  return 0;
}