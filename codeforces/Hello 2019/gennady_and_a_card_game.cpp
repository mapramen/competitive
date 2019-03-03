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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;
  cin >> s;
  for(int k = 0; k < 5; ++k){
    string t;
    cin >> t;
    if(s[0] == t[0] || s[1] == t[1]){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}