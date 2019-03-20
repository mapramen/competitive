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
    int n;
    string s;
    cin >> n >> s;
    int i;
    for(i = 1; i < s.size() && s[i] == '0'; ++i);
    string s1 = string(s, 0, i), s2 = string(s, i);
    if(s2.size() < s1.size() || (s1.size() == s2.size() && s2 <= s1)){
      cout << "NO\n";
    }
    else{
      cout << "YES\n2\n" << s1 << ' ' << s2 << '\n';
    }
  }
  return 0;
}