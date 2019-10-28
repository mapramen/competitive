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
#define L 11

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    string s;
    cin >> n >> s;
    int i = s.find('8');
    cout << (i == -1 || n - i < L ? "NO" : "YES") << "\n";
  }
  return 0;
}