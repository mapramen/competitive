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

vector<char> v{'R', 'P', 'S'};

char GetLoser(char c){
  if(c == 'R'){
    return 'S';
  }

  if(c == 'P'){
    return 'R';
  }

  return 'P';
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

  string ans;
  for(int i = 0; i < 500; ++i){
    for(char c : v){
      char loserC = GetLoser(c);
      bool canWin = true;
      for(auto t : s){
        char d = t[(i % t.size())];
        canWin &= (d == loserC);
      }
      if(canWin){
        ans.push_back(c);
        return ans;
      }
    }

    for(char c : v){
      char loserC = GetLoser(c);
      bool cannotLose = true;
      for(auto t : s){
        char d = t[(i % t.size())];
        cannotLose &= ((c == d) || d == loserC);
      }
      if(cannotLose){
        ans.push_back(c);
        for(int j = 0; j < s.size(); ++j){
          char d = s[j][(i % s[j].size())];
          if(d == loserC){
            swap(s[s.size() - 1], s[j]);
            s.pop_back();
            --j;
          }
        }
        break;
      }
    }

    if(ans.size() <= i){
      break;
    }
  }

  return "IMPOSSIBLE";
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": " << Solve() << "\n";
  }
  return 0;
}