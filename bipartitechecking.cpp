#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int ans;
  vector< int > v;
	node* leftChild;
	node* rightChild;
}node;

int last_query_no[N], parent[N], color[N], sz[N], ans[N];
map< pii, int > query_map;
pii inv_query_map[N];

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = 1;
  temp->v.clear();

  return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else{
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

void AddQuery(node *currentNode, int l, int r, int qno){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      currentNode->v.PB(qno);
    else{
      AddQuery(currentNode->leftChild, l, r, qno);
      AddQuery(currentNode->rightChild, l, r, qno);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int Find(int i){
  while(i != parent[i])
    i = parent[i];
  return i;
}

int GetColor(int i){
  int c = 0;
  while(i != parent[i]){
    c ^= color[i];
    i = parent[i];
  }
  return c;
}

int Union(int i, int j, stack< tiiii >& rollback){
  int pi = Find(i), pj = Find(j), ci = GetColor(i), cj = GetColor(j);
  if(pi != pj){
    if(sz[pi] > sz[pj])
      swap(pi, pj);

    rollback.push(MT(pi, parent[pi], color[pi], sz[pi]));
    color[pi] = 1 ^ ci ^ cj;
    sz[pj] += sz[pi];
    parent[pi] = pj;
    return 1;
  }
  else{
    return (ci ^ cj);
  }
}

void ApplyRollbacks(stack< tiiii >& rollback){
  while(!rollback.empty()){
    int i, pi, ci, si;
    tie(i, pi, ci, si) = rollback.top();
    rollback.pop();
    parent[i] = pi;
    color[i] = ci;
    sz[i] = si;
  }
}

void DivideAndConquerSolve(node *currentNode){
  stack< tiiii > rollback;

  for(int x = 0; x < currentNode->v.size() && currentNode->ans == 1; x++){
    int i, j;
    tie(i, j) = inv_query_map[currentNode->v[x]];
    currentNode->ans = Union(i, j, rollback);
  }

  currentNode->v.clear();

  if(currentNode->leftEnd == currentNode->rightEnd)
    ans[currentNode->leftEnd] = currentNode->ans;
  else{
    currentNode->leftChild->ans = currentNode->ans;
    currentNode->rightChild->ans = currentNode->ans;
    DivideAndConquerSolve(currentNode->leftChild);
    DivideAndConquerSolve(currentNode->rightChild);
  }

  ApplyRollbacks(rollback);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  node *root = BuildSegmentTree(1, q);
  query_map[MP(0, 0)] = 0;

  for(int x = 1; x <= q; x++){
    int i, j, qno;
    scanf("%d%d", &i, &j);

    pii p = MP(i, j);
    if(query_map.find(p) == query_map.end()){
      qno = query_map.size();
      query_map[p] = qno;
      inv_query_map[qno] = p;
      last_query_no[qno] = x;
    }
    else{
      qno = query_map[p];
      if(last_query_no[qno] > 0){
        int l = last_query_no[qno], r = x - 1;
        last_query_no[qno] = 0;
        AddQuery(root, l, r, qno);
      }
      else
        last_query_no[qno] = x;
    }
  }

  for(int qno = 1; qno <= q; qno++){
    if(last_query_no[qno] > 0){
      int l = last_query_no[qno], r = q;
      last_query_no[qno] = 0;
      AddQuery(root, l, r, qno);
    }
  }

  for(int i = 1; i <= n; i++){
    parent[i] = i;
    sz[i] = 1;
  }

  DivideAndConquerSolve(root);

  for(int x = 1; x <= q; x++){
    if(ans[x])
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
