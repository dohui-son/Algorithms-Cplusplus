from collections import*
t,d,D,f,R,G=0,0,[[0,1],[1,0],[0,-1],[-1,0]],deque,range,lambda:[input().split()for i in R(int(input()))]
n=int(input())
m=[[0]*n for i in R(n)]
for x,y in G():m[int(x)-1][int(y)-1]=1
mov=f(G())
m[0][0]=2
q=f([[0,0]])
while q:
    t+=1;x,y=q[-1];dx,dy=D[d];x,y=x+dx,y+dy
    if 0<=x<n and 0<=y<n:pass
    else:break
    if m[x][y]==1:m[x][y]=0
    elif len(q)>1 and [x,y]in q:break
    else:q.popleft()
    q.append([x,y])
    if mov and int(mov[0][0])==t:d=(d+[-1,1][mov.popleft()[1]=='D'])%4
print(t)