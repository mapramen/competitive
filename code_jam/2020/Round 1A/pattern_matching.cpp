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

int Update(vector<string> &s, string &A){
  set<char> S;
  bool isAnyStringEmpty = false;

  for(auto t : s){
    isAnyStringEmpty = isAnyStringEmpty || t.empty();
    S.insert(t.back());
  }

  bool wildCharPresent = S.count('*') > 0;
  if(wildCharPresent){
    S.erase('*');
  }

  if(S.size() == 0){
    return 0;
  }

  if(isAnyStringEmpty || S.size() > 1){
    return -1;
  }

  char c = *S.begin();

  for(int i = 0; i < s.size(); ++i){
    if(s[i].back() == c){
      s[i].pop_back();
    }
  }

  A.push_back(c);

  return 1;
}

string Solve(){
  int n;
  vector<string> s;

  cin >> n;
  for(int i = 0; i < n; ++i){
    string t;
    cin >> t;
    s.push_back(t);
  }

  string A, B;

  while(true){
    int x = Update(s, B);
    if(x == -1){
      return "*";
    }
    if(x == 0){
      break;
    }
  }

  for(int i = 0; i < n; ++i){
    reverse(s[i].begin(), s[i].end());
  }

  while(true){
    int x = Update(s, A);
    if(x == -1){
      return "*";
    }
    if(x == 0){
      break;
    }
  }

  string ans = A;

  for(int i = 0; i < n; ++i){
    for(int x = 0; x < 2; ++x){
      if(!s[i].empty() && s[i].back() == '*'){
        s[i].pop_back();
      }
      reverse(s[i].begin(), s[i].end());
    }

    for( ; !s[i].empty(); s[i].pop_back()){
      if(s[i].back() != '*'){
        ans.push_back(s[i].back());
      }
    }
  }

  reverse(B.begin(), B.end());

  ans += B;

  return ans;
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": " << Solve() << '\n';
  }
  return 0;
}