#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlli tuple< ll, ll, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple

ll inf = 1E18;
vector< tlli > queries;
vector< ll > v(1);

typedef struct node{
  ll leftEnd;
  ll rightEnd;
  int active;
  int lazyInvert;
  ll minA;
  ll minB;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(ll leftEnd, ll rightEnd){
  // printf("CreateNode %lld %lld\n", leftEnd, rightEnd);
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->active = 0;
  temp->lazyInvert = 0;
  temp->minA = inf;
  temp->minB = leftEnd;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  return temp;
}

node* BuildSegmentTree(int i, int j){
  node *temp = CreateNode(v[i - 1] + 1, v[j]);

  if(i != j){
    int k = (i + j) / 2;
    temp->leftChild = BuildSegmentTree(i, k);
    temp->rightChild = BuildSegmentTree(k + 1, j);
  }

  return temp;
}

void TraverseSegmentTree(node *root){
  if(root){
    TraverseSegmentTree(root->leftChild);
    TraverseSegmentTree(root->rightChild);
    printf("%lld %lld\n", root->leftEnd, root->rightEnd);
  }
}

void ActivateNode(node *currentNode){
  currentNode->active = 1;
  currentNode->lazyInvert = 0;
  currentNode->minA = currentNode->leftEnd;
  currentNode->minB = inf;
}

void DeactivateNode(node *currentNode){
  currentNode->active = 0;
  currentNode->lazyInvert = 0;
  currentNode->minA = inf;
  currentNode->minB = currentNode->leftEnd;
}

void InvertNode(node *currentNode){
  if(currentNode->active == 1)
    DeactivateNode(currentNode);
  else if(currentNode->active == 0)
    ActivateNode(currentNode);
  else{
    swap(currentNode->minA, currentNode->minB);
    currentNode->lazyInvert = 1 - currentNode->lazyInvert;
  }

}

void LazyUpdateChild(node *currentNode, node *childNode){
  if(currentNode->active == 0)
    DeactivateNode(childNode);
  else if(currentNode->active == 1)
    ActivateNode(childNode);

  if(currentNode->lazyInvert)
    InvertNode(childNode);
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyInvert = 0;
}

void Merge(node *currentNode){
  int active1 = min(currentNode->leftChild->active, currentNode->rightChild->active);
  int active2 = max(currentNode->leftChild->active, currentNode->rightChild->active);

  if(active2 == 2)
    currentNode->active = 2;
  else if(active1 == 1)
    currentNode->active = 1;
  else if(active2 == 1)
    currentNode->active = 2;
  else
    currentNode->active = 0;

  currentNode->minA = min(currentNode->leftChild->minA, currentNode->rightChild->minA);
  currentNode->minB = min(currentNode->leftChild->minB, currentNode->rightChild->minB);
}

ll Update(node *currentNode, ll l, ll r, int t){
  ll ans = inf;
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    ans = currentNode->minB;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      if(t == 2)
        DeactivateNode(currentNode);
      else if(t == 1)
        ActivateNode(currentNode);
      else
        InvertNode(currentNode);

      ans = currentNode->minB;
    }
    else{
      LazyUpdateChildren(currentNode);
      ans = min(Update(currentNode->leftChild, l, r, t), Update(currentNode->rightChild, l, r, t));
      Merge(currentNode);
    }
  }

  // printf("Update %lld %lld %lld %lld %d %lld\n", l, r, currentNode->leftEnd, currentNode->rightEnd, currentNode->active, ans);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

node *PreProcess(){
  for(auto query : queries){
    int t;
    ll l, r;
    tie(l, r, t) = query;
    v.PB(l - 1);
    v.PB(l);
    v.PB(l + 1);
    v.PB(r - 1);
    v.PB(r);
    v.PB(r + 1);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  inf = v.back() + 1;

  int i = 1, j = v.size() - 1;

  // printf("%d %d %lld\n", i, j, inf);

  return BuildSegmentTree(i, j);
}

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    int t;
    ll l, r;
    scanf("%d%lld%lld", &t, &l, &r);
    queries.PB(MT(l, r, t));
  }

  node *root = PreProcess();

  // printf("TraverseSegmentTree\n");
  // TraverseSegmentTree(root);

  for(auto query : queries){
    int t;
    ll l, r;
    tie(l, r, t) = query;
    printf("%lld\n", Update(root, l, r, t));
  }

	return 0;
}
