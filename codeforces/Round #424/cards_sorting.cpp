#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > v(N);
int c[N];

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
  temp->ans = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Update(node *currentNode, int i, int x){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->ans = x;
    else{
      Update(currentNode->leftChild, i, x);
      Update(currentNode->rightChild, i, x);
      currentNode->ans = max(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}

int Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      return currentNode->ans;
    else
      return max(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;
  node *root = BuildSegmentTree(1, N - 1);
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int x;
    scanf("%d", &x);
    v[x].PB(i);
  }

  for(int x = 1; x < N; x++){
    for(auto i : v[x])
      c[i] = max(Query(root, 1, i), 1 + Query(root, i, n));
    for(auto i : v[x])
      Update(root, i, c[i]);
  }

  for(int i = 1; i <= n; i++)
    ans += c[i];

  printf("%lld\n", ans);

	return 0;
}
