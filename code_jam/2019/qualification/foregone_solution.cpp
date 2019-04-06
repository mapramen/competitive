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

void PrintAns(string a, string b){
  cout << a << ' ' << b << '\n';
}

string FormA10BString(int a, int b){
  string s;
  s.push_back('0' + a);
  for(int i = 1; i <= b; ++i){
    s.push_back('0');
  }
  return s;
}

void Solve(){
  string s, a, b;
  cin >> s;
  
  for(char c : s){
    int x = c - '0', i, j;
    if(x != 4){
      i = x, j = 0;
    }
    else{
      i = 2, j = 2;
    }
    a.push_back('0' + i);
    if(b.size() || j > 0){
      b.push_back('0' + j);
    }
  }
  
  if(b.size()){
    PrintAns(a, b);
    return ;
  }

  int k;
  for(k = s.size() - 1; k > -1 && s[k] == '0'; --k);

  if(k != 0){
    b = FormA10BString(s[k] - '0', s.size() - k - 1);
    a[k] = '0';
    PrintAns(a, b);
    return ;
  }

  if(s.front() == '1'){
    b = FormA10BString(5, s.size() - 2);
    PrintAns(b, b);
    return ;
  }

  int x = s.front() - '0', i, j;
  for(i = 1; i < x; ++i){
    j = x - i;
    if(i != 4 && j != 4){
      break;
    }
  }

  a = FormA10BString(i, s.size() - 1);
  b = FormA10BString(j, s.size() - 1);

  PrintAns(a, b);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}