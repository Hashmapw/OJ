from collections import defaultdict

N = 110

h = [-1] * N
e = [0] * N
ne = [0] * N
idx = 0
cnt = [0] * N
max_depth = 0

def add(a, b):
    global idx
    e[idx] = b
    ne[idx] = h[a]
    h[a] = idx
    idx += 1

def dfs(u, depth):
    global max_depth
    if h[u] == -1:  # 叶子节点
        cnt[depth] += 1
        max_depth = max(max_depth, depth)
        return

    i = h[u]
    while i != -1:
        dfs(e[i], depth + 1)
        i = ne[i]

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        temp = list (map(int,input().split()))
        id=temp[0]
        k=temp[1]
        for j in temp[2::]:
            add(id, j)
    
    dfs(1, 0)

    print(cnt[0], end='')
    for i in range(1, max_depth + 1):
        print("", cnt[i], end='')
    print()
