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

vector<string> words;

void Initialise(){
  string s;
  for(char a = 'a'; a <= 'z'; ++a){
    s.push_back(a);
    words.push_back(s);
    s.pop_back();
  }

  for(char a = 'a'; a <= 'z'; ++a){
    s.push_back(a);
    for(char b = 'a'; b <= 'z'; ++b){
      s.push_back(b);
      words.push_back(s);
      s.pop_back();
    }
    s.pop_back();
  }

  for(char a = 'a'; a <= 'z' && words.size() < 3000; ++a){
    s.push_back(a);
    for(char b = 'a'; b <= 'z'; ++b){
      s.push_back(b);
      for(char c = 'a'; c <= 'z'; ++c){
        s.push_back(c);
        words.push_back(s);
        s.pop_back();
      }
      s.pop_back();
    }
    s.pop_back();
  }
}

string Solve(){
  int n;
  string s;
  set<string> S;

  cin >> n >> s;
  for(int l = 1; l <= 3; ++l){
    for(int i = 0; i + l <= n; ++i){
      S.insert(string(s, i, l));
    }
  }

  for(string &t: words){
    if(S.count(t) == 0){
      return t;
    }
  }

  return "";
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    cout << Solve() << '\n';
  }
  
  return 0;
}