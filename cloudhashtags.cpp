#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501000
#define B 26

int T[N][B], nxtIndex, lengths[N];
set<int> c[N];
vector< string > hashTags;

int NextTreeIndex(int i, int j){
  if(T[i][j] == 0)
    T[i][j] = ++nxtIndex;
  return T[i][j];
}

void EraseText(int i, int maxEraseNo){
  if(i == 0)
    return ;

  int eraseCnt = 0;
  while(c[i].size() > 0 && *c[i].begin() < maxEraseNo){
    c[i].erase(*c[i].begin());
    eraseCnt++;
  }

  for(int j = 0; j < B && eraseCnt > 0; j++)
    if(T[i][j] != 0)
      EraseText(T[i][j], maxEraseNo);
}

void CalculateFinalLengths(int i, int len){
  for(auto x : c[i])
    lengths[x] = max(lengths[x], len);

  for(int j = 0; j < B; j++){
    if(T[i][j] != 0)
      CalculateFinalLengths(T[i][j], len + 1);
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 0; x < n; x++){
    string s;
    int currentIndex = 0;

    cin >> s;
    for(int i = 1; i < s.size(); i++){
      int j = s[i] - 'a';
      int maxEraseNo = 0;
      for(int k = j + 1; k < B; k++){
        int ind = T[currentIndex][k];
        if(c[ind].size() != 0)
          maxEraseNo = max(maxEraseNo, *c[ind].rbegin());
        EraseText(T[currentIndex][k], INT_MAX);
      }
      for(int k = 0; k <= j; k++)
        EraseText(T[currentIndex][k], maxEraseNo);
      currentIndex = NextTreeIndex(currentIndex, j);
      c[currentIndex].insert(x);
    }

    for(int k = 0; k < B; k++)
      EraseText(T[currentIndex][k], INT_MAX);

    hashTags.PB(s);
  }

  CalculateFinalLengths(0, 0);

  for(int i = 0; i < n; i++)
    cout << string(hashTags[i], 0, 1 + lengths[i]) << '\n';

  return 0;
}
