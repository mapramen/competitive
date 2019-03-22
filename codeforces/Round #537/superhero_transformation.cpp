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

set<char> vowels{'a', 'e', 'i', 'o', 'u'};

bool IsVowel(char c){
  return vowels.count(c) > 0;
}

bool IsTransformationValid(string s, string t){
  if(s.size() != t.size()){
    return false;
  }

  for(int i = 0; i < s.size(); ++i){
    if(IsVowel(s[i]) ^ IsVowel(t[i])){
      return false;
    }
  }

  return true;
}

int main(){
  string s, t;
  cin >> s >> t;
  cout << (IsTransformationValid(s, t) ? "Yes" : "No") << '\n';
  return 0;
}