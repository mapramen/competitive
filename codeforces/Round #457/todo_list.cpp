#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

typedef struct node{
  int leftEnd;
  int rightEnd;
  int cnt;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node *CreateNode(int leftEnd, int rightEnd){
  node *newNode = new node;

  newNode->leftEnd = leftEnd;
  newNode->rightEnd = rightEnd;
  newNode->cnt = 0;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;

  return newNode;
}

void SplitNode(node *currentNode){
  if(currentNode->leftChild == NULL){
    int l = currentNode->leftEnd, r = currentNode->rightEnd, mid = l + (r - l) / 2;
    currentNode->leftChild = CreateNode(l, mid);
    currentNode->rightChild = CreateNode(mid + 1, r);
  }
}

node* Update(node *currentNode, int i, int x){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return currentNode;
  else{
    node *newNode = CreateNode(currentNode->leftEnd, currentNode->rightEnd);

    if(currentNode->leftEnd == i && currentNode->rightEnd == i){
      newNode->cnt = x + currentNode->cnt;
    }
    else{
      SplitNode(currentNode);
      newNode->leftChild = Update(currentNode->leftChild, i, x);
      newNode->rightChild = Update(currentNode->rightChild, i, x);
      newNode->cnt = newNode->leftChild->cnt + newNode->rightChild->cnt;
    }

    return newNode;
  }
}

int QueryValue(node *currentNode, int i){
  while(currentNode->leftEnd != i || currentNode->rightEnd != i){
    if(currentNode->leftChild == NULL){
      return 0;
    }
    else{
      if(currentNode->leftChild->rightEnd < i)
        currentNode = currentNode->rightChild;
      else
        currentNode = currentNode->leftChild;
    }
  }
  return (currentNode->cnt);
}

int QuerySum(node *currentNode, int i){
  int ans = 0;
  while(currentNode->leftEnd != i || currentNode->rightEnd != i){
    if(currentNode->leftChild == NULL){
      return -1;
    }
    else{
      if(currentNode->leftChild->rightEnd < i){
        ans += currentNode->leftChild->cnt;
        currentNode = currentNode->rightChild;
      }
      else
        currentNode = currentNode->leftChild;
    }
  }

  if(currentNode->cnt == 0)
    return -1;

  return ans;
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

int inf = 1E9;
node *root1[N];
node *root2[N];
node *r1;
node *r2;
map<string,int> M;
char s[16];

int GetAssignmentID(){
  string t = string(s);
  int ans = M[t];
  if(ans == 0){
    M[t] = M.size();
    ans = M.size();
  }
  return ans;
}

void Remove(int i){
  int px = QueryValue(r1, i);
  if(px){
    r1 = Update(r1, i, -px);
    r2 = Update(r2, px, -1);
  }
}

void Add(int i, int x){
  r1 = Update(r1, i, x);
  r2 = Update(r2, x, 1);
}

void Set(int i, int x){
  Remove(i);
  Add(i, x);
}

int main(){
  int q;

  scanf("%d", &q);

  root1[0] = CreateNode(1, q);
  root2[0] = CreateNode(1, inf);

  for(int k = 1; k <= q; ++k){
    r1 = root1[k - 1], r2 = root2[k - 1];

    scanf("%s", s);

    if(s[0] == 's'){
      int i, x;
      scanf("%s%d", s, &x);
      i = GetAssignmentID();
      Set(i, x);
    }
    else if(s[0] == 'r'){
      int i;
      scanf("%s", s);
      i = GetAssignmentID();
      Remove(i);
    }
    else if(s[0] == 'q'){
      int i;
      scanf("%s", s);
      i = GetAssignmentID();
      int x = QueryValue(r1, i);
      if(x == 0){
        printf("-1\n");
      }
      else
        printf("%d\n", QuerySum(r2, x));
      fflush(stdout);
    }
    else{
      int x;
      scanf("%d", &x);

      r1 = root1[k - x - 1];
      r2 = root2[k - x - 1];
    }

    root1[k] = r1;
    root2[k] = r2;
  }

  return 0;
}
