#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define P 31
#define B 27
#define INVP 129032259
#define MOD 1000000007

typedef struct node{
  int leftEnd;
  int rightEnd;
  int hsh;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->hsh = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Merge(node *currentNode){
  currentNode->hsh = (currentNode->leftChild->hsh + currentNode->rightChild->hsh) % MOD;
}

void Update(node *currentNode, int i, int val){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->hsh = val;
    else{
      Update(currentNode->leftChild, i, val);
      Update(currentNode->rightChild, i, val);
      Merge(currentNode);
    }
  }
}

int GetLeftEnd(node *u, node *v){
  if(u->hsh == v->hsh)
    return u->rightEnd + 1;
  else{
    if(u->leftEnd == u->rightEnd)
      return u->leftEnd;
    else{
      if(u->leftChild->hsh != v->leftChild->hsh)
        return GetLeftEnd(u->leftChild, v->leftChild);
      else
        return GetLeftEnd(u->rightChild, v->rightChild);
    }
  }
}

int GetRightEnd(node *u, node *v){
  if(u->hsh == v->hsh)
    return u->leftEnd - 1;
  else{
    if(u->leftEnd == u->rightEnd)
      return u->leftEnd;
    else{
      if(u->rightChild->hsh != v->rightChild->hsh)
        return GetRightEnd(u->rightChild, v->rightChild);
      else
        return GetRightEnd(u->leftChild, v->leftChild);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

vector< vector<int> > M;
int n, m, c[B];
vector<int> p, invp;
char s[N];
node *root[N];
bool hasDuplicateCharacters = 0, found = 0;

void Initialise(){
  p.resize(n + 1);
  invp.resize(n + 1);
  M.resize(m + 1, vector<int>(n + 1, 0));
}

void Update(int k, int i, int x){
  Update(root[k], i, x);
}

void PreProcess(){
  p[0] = invp[0] = 1;
  for(int i = 1; i <= n; ++i){
    p[i] = (1ll * P * p[i - 1]) % MOD;
    invp[i] = (1ll * INVP * invp[i - 1]) % MOD;
  }

  for(int k = 1; k <= m; ++k){
    root[k] = BuildSegmentTree(1, n);
    for(int i = 1; i <= n; ++i)
      Update(k, i, (1ll * M[k][i] * p[i]) % MOD);
  }
}

void Swap(int k, int i, int j){
  if(M[k][i] == M[k][j])
    return ;

  int x1 = (1ll * M[k][j] * p[i]) % MOD, x2 = (1ll * M[k][i] * p[j]) % MOD;
  Update(k, i, x1);
  Update(k, j, x2);
  swap(M[k][i], M[k][j]);
}

int GetLeftEnd(int k){
  return GetLeftEnd(root[1], root[k]);
}

int GetRightEnd(int k){
  return GetRightEnd(root[1], root[k]);
}

int GetStringHash(int k){
  return root[k]->hsh;
}

bool CheckAndPrint(){
  int cnt = 1, targetStringHash = GetStringHash(1);

  for(int k = 2; k <= m; ++k){
    int l = GetLeftEnd(k);

    if(l == n + 1){
      cnt += hasDuplicateCharacters;
    }
    else{
      int r = GetRightEnd(k);
      Swap(k, l, r);
      cnt += (GetStringHash(k) == targetStringHash);
      Swap(k, l, r);
    }

    if(cnt < k)
      break;
  }

  if(cnt == m){
    for(int x = 1; x <= n; ++x)
      putchar('a' + M[1][x] - 1);
    putchar('\n');
  }

  return (cnt == m);
}

void SwapAndCheck(int i, int j){
  if(found)
    return ;

  Swap(1, i, j);
  found = CheckAndPrint();
  Swap(1, i, j);
}

int main(){
  scanf("%d%d", &m, &n);

  if(n == 1){
    printf("-1\n");
    return 0;
  }

  Initialise();

  for(int k = 1; k <= m; ++k){
    scanf("%s", s);
    for(int i = 1; i <= n; ++i)
      M[k][i] = s[i - 1] - 'a' + 1;
  }

  PreProcess();

  for(int i = 1; i <= n; ++i)
    ++c[M[1][i]];

  for(int i = 1; i < B; ++i)
    hasDuplicateCharacters |= (c[i] > 1);

  if(hasDuplicateCharacters)
    found = CheckAndPrint();

  SwapAndCheck(1, 2);

  for(int k = 2; k <= m && found == 0; ++k){
    vector<int> v;
    for(int i = 1; i <= n && v.size() < 5; ++i){
      if(M[k][i] != M[1][i])
        v.PB(i);
    }

    if(v.size() > 4)
      break;

    for(auto i : v){
      for(auto j : v){
        if(i == j)
          continue;

        SwapAndCheck(i, j);

        if(found)
          break;
      }

      if(found)
        break;
    }
  }

  if(found == 0)
    printf("-1\n");

  return 0;
}
