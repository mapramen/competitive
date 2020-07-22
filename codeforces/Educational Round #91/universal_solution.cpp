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
#define pcc pair<char,char>

vector<pcc> winningPairs{{'R', 'S'}, {'S', 'P'} , {'P', 'R'}};

string Solve(){
  string s;

  cin >> s;

  int k = 0;
  char c;
  for(pcc p: winningPairs){
    int x = 0;
    for(char a: s){
      x += (a == p.second);
    }
    if(x > k){
      k = x, c = p.first;
    }
  }

  return string(s.size(), c);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}