def relabel_to_front(C, source, sink):
    n = len(C)
    F = [[0] * n for _ in range(n)]

    height = [0] * n
    excess = [0] * n
    seen   = [0] * n

    def push(u, v):
        send = min(excess[u], C[u][v] - F[u][v])
        if send:
            F[u][v] += send
            F[v][u] -= send
            excess[u] -= send
            excess[v] += send

    def relabel(u):
        min_height = 2 * n
        for v in range(n):
            if C[u][v] - F[u][v] > 0:
                min_height = min(min_height, height[v])
        height[u] = min_height + 1

    def discharge(u):
        while excess[u] > 0:
            if seen[u] < n:
                v = seen[u]
                if C[u][v] - F[u][v] > 0 and height[u] > height[v]:
                    push(u, v)
                else:
                    seen[u] += 1
            else:
                relabel(u)
                seen[u] = 0

    height[source] = n
    excess[source] = sum(C[source])
    for v in range(n):
        push(source, v)
    excess[source] = -sum(C[source])

    Q = [i for i in range(n) if i != source and i != sink and excess[i] > 0]
    while Q:
        u = Q[0]
        old_height = height[u]
        discharge(u)
        Q = [i for i in range(n) if i != source and i != sink and excess[i] > 0]

    return sum(F[source])

def answer(entrances, exits, path):
    n = len(path) + 2
    C = [[0] * n for _ in range(n)]

    n = len(path)
    for i in range(n):
        for j in range(n):
            C[i + 1][j + 1] = path[i][j]

    for i in entrances:
        C[0][i + 1] += sum(path[i])

    for j in exits:
        c = 0
        for i in range(n):
            c += path[i][j]
        C[j + 1][n + 1] += c

    source = 0
    sink = n + 1
    print C
    return relabel_to_front(C, source, sink)

entrances = [0]
exits = [3]
path = [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]]
print answer(entrances, exits, path)

print relabel_to_front(path, 0, 3)
