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
  int t;
  cin >> t;
  while(t--){
    int l, r, d, ans;
    cin >> l >> r >> d;
    if(d < l){
      ans = d;
    }
    else{
      ans = d * (r / d + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}