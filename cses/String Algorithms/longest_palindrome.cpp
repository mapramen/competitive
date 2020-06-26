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

string ManacherAlgorithmOddLength(string s){
  const int n = s.size();
  vector<int> d(n);
  int maxLength = 0, startIndex;

  for(int i = 0, l = 0, r = -1; i < n; ++i){
    int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

    while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){
      ++k;
    }

    d[i] = k--;
    if(i + k > r){
      l = i - k, r = i + k;
    }

    int length = 2 * d[i] - 1;
    if(maxLength < length){
      maxLength = length, startIndex = i - d[i] + 1;
    }
  }

  return string(s, startIndex, maxLength);
}

string ManacherAlgorithmEvenLength(string s){
  const int n = s.size();
  vector<int> d(n);
  int maxLength = 0, startIndex;

  for(int i = 0, l = 0, r = -1; i < n; ++i){
    int k = (i > r) ? 0 : min(d[l + r - i + 1], r - i + 1);

    while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]){
      ++k;
    }

    d[i] = k--;
    if(i + k > r){
      l = i - k - 1, r = i + k;
    }

    int length = 2 * d[i];
    if(maxLength < length){
      maxLength = length, startIndex = i - d[i];
    }
  }

  return string(s, startIndex, maxLength);
}

string ManacherAlgorithm(string s){
  string ans1 = ManacherAlgorithmOddLength(s);
  string ans2 = ManacherAlgorithmEvenLength(s);
  return ans1.size() > ans2.size() ? ans1 : ans2;
}

int main(){
  string s;
  cin >> s;
  cout << ManacherAlgorithm(s) << '\n';
  return 0;
}