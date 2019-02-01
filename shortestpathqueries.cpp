#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 200001
#define B 29

typedef struct node{
  int leftEnd;
  int rightEnd;
  vector<int> edgeNoList;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->edgeNoList.clear();

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Update(node *currentNode, int l, int r, int edgeNo){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      currentNode->edgeNoList.PB(edgeNo);
    }
    else{
      Update(currentNode->leftChild, l, r, edgeNo);
      Update(currentNode->rightChild, l, r, edgeNo);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int edgeU[2 * N], edgeV[2 * N], edgeW[2 * N], edgeS[2 * N], edgeF[2 * N], qU[N], qV[N], parent[N], groupSize[N], d[N], bases[B + 1], ans[N], edgeNos;
map< pii, int > S;

int Reduction(int x){
  for(int k = B; k > -1; --k){
    if((x & (1 << k)) > 0)
      x ^= bases[k];
  }
  return x;
}

void InsertBase(int x, vector< pii >& rollbackBases){
  x = Reduction(x);
  if(x == 0)
    return ;
  int k;
  for(k = B; k > -1 && (x & (1 << k)) == 0; --k);
  rollbackBases.PB(MP(k, bases[k]));
  bases[k] = x;
}

int Find(int i){
  while(parent[i] != i)
    i = parent[i];
  return i;
}

int Dis(int i){
  int ans = 0;
  while(parent[i] != i){
    ans ^= d[i];
    i = parent[i];
  }
  return ans;
}

void PushRollBackDSU(int i, vector< tiiii >& rollbackDSU){
  rollbackDSU.PB(MT(i, parent[i], groupSize[i], d[i]));
}

void Union(int i, int j, int w, vector< tiiii >& rollbackDSU, vector< pii >& rollbackBases){
  w ^= (Dis(i) ^ Dis(j));
  i = Find(i), j = Find(j);
  if(i == j){
    InsertBase(w, rollbackBases);
    return ;
  }
  if(groupSize[i] < groupSize[j])
    swap(i, j);
  PushRollBackDSU(i, rollbackDSU);
  PushRollBackDSU(j, rollbackDSU);
  parent[j] = i;
  groupSize[i] += groupSize[j];
  d[j] = w;
}

void ApplyRollBacks(vector< tiiii >& rollbackDSU, vector< pii >& rollbackBases){
  reverse(rollbackDSU.begin(), rollbackDSU.end());
  reverse(rollbackBases.begin(), rollbackBases.end());

  for(auto t : rollbackDSU){
    int i, pi, gi, di;
    tie(i, pi, gi, di) = t;
    parent[i] = pi;
    groupSize[i] = gi;
    d[i] = di;
  }

  for(auto p : rollbackBases){
    int k, bk;
    tie(k, bk) = p;
    bases[k] = bk;
  }
}

void Solve(node *currentNode){
  vector< tiiii > rollbackDSU;
  vector< pii > rollbackBases;

  for(auto edgeNo : currentNode->edgeNoList)
    Union(edgeU[edgeNo], edgeV[edgeNo], edgeW[edgeNo], rollbackDSU, rollbackBases);

  if(currentNode->leftEnd != currentNode->rightEnd){
    Solve(currentNode->leftChild);
    Solve(currentNode->rightChild);
  }
  else{
    int i = currentNode->leftEnd;
    if(qU[i] != 0){
      ans[i] = Reduction(Dis(qU[i]) ^ Dis(qV[i]));
    }
  }

  ApplyRollBacks(rollbackDSU, rollbackBases);
}

int GetEdgeNo(){
  int i, j;
  scanf("%d%d", &i, &j);
  pii p = MP(i, j);
  if(S.find(p) != S.end())
    return S[p];
  else{
    S[p] = ++edgeNos;
    edgeU[edgeNos] = i;
    edgeV[edgeNos] = j;
    return edgeNos;
  }
}

void AddEdge(int t){
  int edgeNo = GetEdgeNo();
  scanf("%d", &edgeW[edgeNo]);
  edgeS[edgeNo] = t;
}

void RemoveEdge(int t){
  int edgeNo = GetEdgeNo();
  edgeF[edgeNo] = t;
  S.erase(MP(edgeU[edgeNo], edgeV[edgeNo]));
}

int main(){
  int n, m, q;

  scanf("%d%d", &n, &m);

  while(m--)
    AddEdge(1);

  scanf("%d", &q);

  for(int x = 1; x <= q; ++x){
    int t;
    scanf("%d", &t);
    if(t == 1)
      AddEdge(x);
    else if(t == 2)
      RemoveEdge(x);
    else
      scanf("%d%d", &qU[x], &qV[x]);
  }

  node *root = BuildSegmentTree(1, q);

  for(int x = 1; x <= edgeNos; ++x){
    if(edgeF[x] == 0)
      edgeF[x] = q;
    Update(root, edgeS[x], edgeF[x], x);
  }

  for(int i = 1; i <= n; ++i)
    parent[i] = i, groupSize[i] = 1;

  Solve(root);

  for(int i = 1; i <= q; ++i){
    if(qU[i] != 0)
      printf("%d\n", ans[i]);
  }

  return 0;
}
