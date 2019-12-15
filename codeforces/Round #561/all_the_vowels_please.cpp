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

vector<char> v{'a', 'e', 'i', 'o', 'u'};

int main(){
  int k;

  cin >> k;
  
  int n, m;
  for(n = v.size(); n * v.size() <= k && k % n != 0; ++n);

  if(k % n != 0 || k / n < v.size()){
    cout << "-1\n";
    return 0;
  }

  m = k / n;

  string s;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      s.push_back(v[(i + j) % v.size()]);
    }
  }

  cout << s << '\n';
  
  return 0;
}