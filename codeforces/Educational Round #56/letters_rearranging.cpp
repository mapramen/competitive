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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); ++i){
      if(s[i] != s[0]){
        swap(s[i], s[s.size() - 1]);
      }
    }
    if(s.front() == s.back()){
      cout << "-1\n";
    }
    else{
      cout << s << '\n';
    }
  }
  return 0;
}