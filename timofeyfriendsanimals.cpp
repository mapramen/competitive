#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int K;

typedef struct data{
  int ans;
  vector< pii > group, fList;
}data;

typedef struct node{
  int leftEnd;
  int rightEnd;
  data nodeData;
  node* leftChild;
  node* rightChild;
}node;

data GetData(int i){
  data nodeData;
  if(i){
    for(auto j : adj[i])
      nodeData.fList.PB(MP(i, j));
    nodeData.group.PB(MP(i, i));
    nodeData.ans = 1;
  }
  else{
    nodeData.group.clear();
    nodeData.fList.clear();
    nodeData.ans = 0;
  }
  return nodeData;
}

int IndexInGroupVector(int i, vector< pii >& group){
  int x;
  for(x = 0; x < group.size() && group[x].first != i; x++);
  if(x == group.size())
    x = -1;
  return x;
}

int FindGroup(int i, vector< pii >& group){
  int x, gi;
  x = IndexInGroupVector(i, group);
  gi = group[x].second;
  if(gi != i)
    gi = group[x].second = FindGroup(gi, group);
  return gi;
}

int UnionGroup(int i, int j, vector< pii >& group){
  if(i > j)
    swap(i, j);

  int y = IndexInGroupVector(j, group);
  group[y].second = i;
}

void InsertIntoGroup(int i, int gi, vector< pii >& group){
  int x = 0;
  for(x = 0; x < group.size() && group[x].first != i; x++);
  if(x == group.size())
    group.PB(MP(i, gi));
}

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  return temp;
}

data Merge(data a, data b){
  int l = INT_MAX, r = INT_MIN;
  int ans = a.ans + b.ans;
  data c;
  vector< pii > group;

  for(auto mx : a.group){
    l = min(l, mx.first);
    r = max(r, mx.first);
    group.PB(mx);
  }

  for(auto mx : b.group){
    l = min(l, mx.first);
    r = max(r, mx.first);
    group.PB(mx);
  }

  for(auto fx : a.fList){
    if(fx.second > r)
      c.fList.PB(fx);
    else{
      int gi = FindGroup(fx.first, group), gj = FindGroup(fx.second, group);
      if(gi != gj){
        ans--;
        UnionGroup(gi, gj, group);
      }
    }
  }

  for(auto fx : b.fList){
    if(fx.second > r)
      c.fList.PB(fx);
    else{
      int gi = FindGroup(fx.first, group), gj = FindGroup(fx.second, group);
      if(gi != gj){
        ans--;
        UnionGroup(gi, gj, group);
      }
    }
  }

  for(auto p : group){
    int i = p.first;
    if(i >= l + K && i <= r - K)
      continue;

    int gi = FindGroup(i, group);
    InsertIntoGroup(i, gi, c.group);
    InsertIntoGroup(gi, gi, c.group);
  }

  sort(c.group.begin(), c.group.end());

  c.ans = ans;

  return c;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->nodeData = Merge(temp->leftChild->nodeData, temp->rightChild->nodeData);
  }
  else{
    temp->nodeData = GetData(leftEnd);
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

data Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return GetData(0);
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->nodeData;
    else
      return Merge(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m, q;
  node *root;

  scanf("%d%d%d", &n, &K, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    if(i > j)
      swap(i, j);
    adj[i].PB(j);
  }

  root = BuildSegmentTree(1, n);

  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    r = min(r, n);
    printf("%d\n", Query(root, l, r).ans);
  }

	return 0;
}
