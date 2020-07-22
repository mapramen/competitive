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
#define B 27
#define N 1000001

vector<vector<int>> firstColumnIndexes(B), lastColumnIndexes(B);
int c[B], occurenceInFirstColumn[N], occurenceInLastColumn[N];
string firstColumn, lastColumn;

void FillIndex(string &s, vector<vector<int>> &indexes, int occurence[]){
  for(int i = 0; i < B; ++i){
    c[i] = 0;
  }

  for(int i = 0; i < s.size(); ++i){
    int j = s[i] - 'a' + 1;
    indexes[j].push_back(i);
    occurence[i] = c[j];
    ++c[j];
  }
}

int main(){
  cin >> lastColumn;

  int n = lastColumn.size();
  replace(lastColumn.begin(), lastColumn.end(), '#', (char)('a' - 1));

  for(int i = 0; i < n; ++i){
    ++c[lastColumn[i] - 'a' + 1];
  }

  for(int i = 0; i < B; ++i){
    int k = c[i];
    while(k--){
      firstColumn.push_back('a' + i - 1);
    }
  }

  FillIndex(lastColumn, lastColumnIndexes, occurenceInLastColumn);
  FillIndex(firstColumn, firstColumnIndexes, occurenceInFirstColumn);

  string ans;
  for(int x = 0, i = 0; x < n; ++x){
    ans.push_back(firstColumn[i]);
    int j = lastColumn[i] - 'a' + 1;
    i = firstColumnIndexes[j][occurenceInLastColumn[i]];
  }
  reverse(ans.begin(), ans.end());
  ans.pop_back();

  cout << ans << '\n';

  return 0;
}