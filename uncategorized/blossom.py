def SimplePath(parent, u, v):
    P = []
    while u != v:
        P.append(u)
        u = parent[u]
    P.append(v)
    return P

def Blossom(parent, dis, Adj, M, v, w):
    if dis[v] < dis[w]:
        v, w = w, v
    vx, wx = v, w
    while dis[vx] > dis[wx]:
        vx = parent[vx]
    while vx != wx:
        vx, wx = parent[vx], parent[wx]
    u = vx
    B = SimplePath(parent, v, u)
    B.reverse()
    B += SimplePath(parent, w, u)
    k = len(B)
    B = B + B[1:]
    i = 1
    l = len(B) - 1
    while i <= l:
        e1 = Adj[B[i]][B[i - 1]]
        e2 = Adj[B[i]][B[i + 1]]
        if e1 in M or e2 in M:
            i += 1
        else:
            break
    B = B[i:i+k]
    return B

def Contract(G, M, B):
    Adj, Edges = G
    newAdj = {}
    newEdges = {}
    newM = set()
    vertexMapping = {}

    for v in Adj:
        vertexMapping[v] = v

    vb = B[0]
    for v in B:
        vertexMapping[v] = vb

    for v in Adj:
        nv = vertexMapping[v]
        d = {}
        for w, e in Adj[v].iteritems():
            nw = vertexMapping[w]
            if nv != nw:
                d[nw] = e
                newEdges[e] = (nv, nw)
                if e in M:
                    newM.add(e)
        if len(d):
            newAdj[nv] = d

    newG = (newAdj, newEdges)
    return newG, newM

def SimpleLiftPath(newP, B, Adj):
    w = newP[1]
    i = 0
    while w not in Adj[B[i]]:
        i += 1
    if i % 2 == 1:
        B.reverse()
        i = len(B) - 1 - i
    P = B[0:i + 1] + newP[1:]
    return P

def LiftPath(newP, B, M, Adj):
    vb = B[0]
    if vb not in newP:
        return newP
    else:
        P = []
        i = newP.index(vb)
        if i == 0 or i == len(newP) - 1:
            if i == len(newP) - 1:
                newP.reverse()
        else:
            if Adj[vb][newP[i + 1]] in M:
                newP.reverse()
            i = newP.index(vb)
            P = newP[:i]
            newP = newP[i:]
        P += SimpleLiftPath(newP, B, Adj)
        return P

def AugmentingPath(G, M):
    Adj, Edges = G
    root = {}
    parent = {}
    dis = {}
    match = {}
    exposed = set()
    unmarkedVertices = set()
    markedEdges = set()
    Q = []


    for v in Adj:
        exposed.add(v)

    for e in M:
        u, v = Edges[e]
        exposed.remove(u)
        exposed.remove(v)
        markedEdges.add(e)
        match[u] = v
        match[v] = u

    for v in exposed:
        root[v] = v
        parent[v] = v
        dis[v] = 0
        unmarkedVertices.add(v)

    while len(unmarkedVertices):
        v = unmarkedVertices.pop()
        if dis[v] % 2 == 1:
            continue
        for w, e in Adj[v].iteritems():
            if e in markedEdges:
                continue
            if w not in root:
                x = match[w]
                L = [(v, w), (w, x)]
                for l in L:
                    a, b = l
                    root[b] = root[a]
                    parent[b] = a
                    dis[b] = dis[a] + 1
                    unmarkedVertices.add(b)
            else:
                if dis[w] % 2 == 1:
                    w = w
                else:
                    if root[v] != root[w]:
                        P = SimplePath(parent, v, root[v])
                        P.reverse()
                        P += SimplePath(parent, w, root[w])
                        return P
                    else:
                        B = Blossom(parent, dis, Adj, M, v, w)
                        newG, newM = Contract(G, M, B)
                        newP = AugmentingPath(newG, newM)
                        P = LiftPath(newP, B, M, Adj)
                        return P
            markedEdges.add(e)

    return []

def MaximumMatching(G):
    Adj, Edges = G
    M = set()
    while True:
        P = AugmentingPath(G, M)
        if P:
            Mx = set()
            for i in range(len(P) - 1):
                Mx.add(Adj[P[i]][P[i + 1]])
            M.symmetric_difference_update(Mx)
        else:
            break
    return len(M)

def IsLoop(a, b):
    if a == b:
        return False
    else:
        while a % 2 == 0 and b % 2 == 0:
            a /= 2
            b /= 2

        if a % 2 != b % 2:
            return True
        else:
            if a > b:
                a, b = b, a
            return IsLoop(2 * a, b - a)

def answer(banana_list):
    Adj = {}
    Edges = {}
    edgeNo = 1
    for i in range(len(banana_list)):
        Adj[i] = {}
    for i in range(len(banana_list)):
        for j in range(i + 1, len(banana_list)):
            if not IsLoop(banana_list[i], banana_list[j]):
                continue
            Adj[i][j] = edgeNo
            Adj[j][i] = edgeNo
            Edges[edgeNo] = (i, j)
            edgeNo += 1
    for i in range(len(banana_list)):
        if len(Adj[i]) == 0:
            _ = Adj.pop(i, None)
    G = (Adj, Edges)
    ans = len(banana_list) - 2 * MaximumMatching(G)
    return ans

banana_list = map(int, raw_input().split(' '))
print banana_list
print 'answer: ', answer(banana_list)
