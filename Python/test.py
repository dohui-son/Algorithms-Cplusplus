from sys import stdin

n, m = map(int, stdin.readline().split())
g = [list(stdin.readline()) for _ in range(n)]


def move(y, x, dy, dx):
    cnt = 0
    while g[y+dy][x+dx] != '#' and g[y][x] != 'O':
        y += dy
        x += dx
        cnt += 1
    return y, x, cnt


def solution():
    for y, b in enumerate(g):
        for x, a in enumerate(b):
            if a == "R":
                sry, srx = y, x
            if a == "B":
                sby, sbx = y, x
    visited = {}
    qlist = [[sry, srx, sby, sbx, 1]]
    visited[(sry, srx, sby, sbx)] = 1
    dir = [[0, -1], [-1, 0], [0, 1], [1, 0]]
    while qlist:
        now = qlist.pop(0)
        ry, rx, by, bx = now[0], now[1], now[2], now[3]
        if(now[4] > 10):
            break
        for d in dir:
            rry, rrx, rcnt = move(ry, rx, d[0], d[1])
            bby, bbx, bcnt = move(by, bx, d[0], d[1])
            if g[bby][bbx] != 'O':
                if g[rry][rrx] == 'O':
                    print(now[4])
                    return
                if bby == rry and bbx == rrx:
                    if rcnt > bcnt:
                        rry -= d[0]
                        rrx -= d[1]
                    else:
                        bby -= d[0]
                        bbx -= d[1]
                if (rry, rrx, bby, bbx) in visited:
                    continue
                visited[(rry, rrx, bby, bbx)] = 1
                qlist.append([rry, rrx, bby, bbx, now[4]+1])
    print(-1)


solution()
