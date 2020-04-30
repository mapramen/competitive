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
  int x, y;
  string s;

  cin >> x >> y;
  
  queue< tuple<int,int,string> > Q;
  Q.push(make_tuple(x, y, ""));

  while(!Q.empty()){
    tie(x, y, s) = Q.front();
    Q.pop();

    if(x == 0 && y == 0){
      while(!Q.empty()){
        Q.pop();
      }
      return s;
    }

    if(abs(x) % 2 == abs(y) % 2){
      continue;
    }

    if(abs(x) % 2 == 1){
      Q.push(make_tuple((x - 1) / 2, y / 2, s + "E"));
      Q.push(make_tuple((x + 1) / 2, y / 2, s + "W"));
    }
    else{
      Q.push(make_tuple(x / 2, (y - 1) / 2, s + "N"));
      Q.push(make_tuple(x / 2, (y + 1) / 2, s + "S"));
    }
  }

  return "IMPOSSIBLE";
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": " << Solve() << '\n';
  }
  return 0;
}