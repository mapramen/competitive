#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 5
#define inf INT_MAX / 2

string s;

typedef struct data{
  int mat[B][B];
}data;

typedef struct node{
  int leftEnd;
  int rightEnd;
  data ans;
  node* leftChild;
  node* rightChild;
}node;

data GetDataMat(char c){
  data d;

  for(int i = 0; i < B; i++){
    for(int j = i; j < B; j++)
      d.mat[i][j] = inf;
    d.mat[i][i] = 0;
  }

  if(c == '2'){
    d.mat[0][1] = 0;
    d.mat[0][0] = 1;
  }

  if(c == '0'){
    d.mat[1][2] = 0;
    d.mat[1][1] = 1;
  }

  if(c == '1'){
    d.mat[2][3] = 0;
    d.mat[2][2] = 1;
  }

  if(c == '6'){
    d.mat[3][3] = 1;
    d.mat[4][4] = 1;
  }

  if(c == '7'){
    d.mat[3][4] = 0;
    d.mat[3][3] = 1;
  }

  return d;
}

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  return temp;
}

data Merge(data a, data b){
  data c;

  for(int i = 0; i < B; i++)
    for(int j = i; j < B; j++)
      c.mat[i][j] = inf;

  for(int i = 0; i < B; i++)
    for(int j = i; j < B; j++)
      for(int k = i; k <= j; k++)
        c.mat[i][j] = min(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);

  return c;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->ans = Merge(temp->leftChild->ans, temp->rightChild->ans);
  }
  else{
    temp->ans = GetDataMat(s[leftEnd - 1]);
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

data Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return GetDataMat('9');
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else
      return Merge(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, q;
  node *root;

  scanf("%d%d", &n, &q);
  cin >> s;

  root = BuildSegmentTree(1, n);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = Query(root, l, r).mat[0][4];
    if(ans == inf)
      ans = -1;
    printf("%d\n", ans);
  }

	return 0;
}
