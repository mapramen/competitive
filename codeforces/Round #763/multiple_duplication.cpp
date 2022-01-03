#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 26

char s[N];
int leftChild[N], rightChild[N];
bool isGood[N], shouldDuplicate[N];
vector<int> inorder;

void InorderDFS(int i){
  if(i == 0){
    return;
  }
  
  InorderDFS(leftChild[i]);
  
  inorder.push_back(i);

  InorderDFS(rightChild[i]);
}

bool ShouldDuplicateDFS(int& m, int i, int cost){
  if(i == 0){
    return false;
  }

  ++cost;
  bool ans = ShouldDuplicateDFS(m, leftChild[i], cost);

  if(ans){
    shouldDuplicate[i] = true;
  }

  if(!ans && isGood[i] && cost <= m){
    m -= cost;
    shouldDuplicate[i] = true;
    ans = true;
  }

  if(ans){
    ShouldDuplicateDFS(m, rightChild[i], 0);
  }

  return ans;
}

void PrintDFS(int i){
  if(i == 0){
    return;
  }

  PrintDFS(leftChild[i]);

  putchar(s[i - 1]);
  if(shouldDuplicate[i]){
    putchar(s[i - 1]);
  }

  PrintDFS(rightChild[i]);
}

int main(){
  int n, m;
  scanf("%d%d%s", &n, &m, s);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &leftChild[i], &rightChild[i]);
  }

  InorderDFS(1);

  for(int x = 0; x < n; ){
    char c = s[inorder[x] - 1];
    
    int y = x + 1;
    for( ; y < n && s[inorder[y] - 1] == c; ++y);

    char d = y == n ? 'a' - 1 : s[inorder[y] - 1];
    for( ; x < y; ++x){
      isGood[inorder[x]] = d > c;
    }
  }

  ShouldDuplicateDFS(m, 1, 0);

  PrintDFS(1);
  putchar('\n');

  return 0;
}