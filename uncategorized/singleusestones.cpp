#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

const int inf = 1E9;
int a[N], b[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->ans = temp->leftChild->ans + temp->rightChild->ans;
  }
  else{
    temp->ans = a[leftEnd];
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

void Update(node *currentNode, int i, int val){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->ans += val;
    else{
      Update(currentNode->leftChild, i, val);
      Update(currentNode->rightChild, i, val);
      currentNode->ans = currentNode->leftChild->ans + currentNode->rightChild->ans;
    }
  }
}

int RightMostNonZeroValueIndex(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l || currentNode->ans == 0){
    return 0;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      while(currentNode->leftEnd != currentNode->rightEnd){
        if(currentNode->rightChild->ans){
          currentNode = currentNode->rightChild;
        }
        else{
          currentNode = currentNode->leftChild;
        }
      }
      return currentNode->rightEnd;
    }
    else{
      return max(RightMostNonZeroValueIndex(currentNode->leftChild, l, r), RightMostNonZeroValueIndex(currentNode->rightChild, l, r));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i < n; ++i)
    scanf("%d", &a[i]);

  a[n] = inf;
  b[0] = inf;

  node *root = BuildSegmentTree(0, n);

  for(int i = 0; i <= n; ++i){
    for(int j = RightMostNonZeroValueIndex(root, i + 1, i + m); j != 0 && b[i] > 0; j = RightMostNonZeroValueIndex(root, i + 1, i + m)){
      int x = min(b[i], a[j]);
      b[j] += x;
      b[i] -= x;
      a[j] -= x;
      Update(root, j, -x);
    }
  }

  printf("%d\n", b[n]);

	return 0;
}
