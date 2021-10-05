from itertools import*
R=range
N,*l=map(int,open(0).read().split())
m=[l[i:i+N]for i in R(0,N*N,N)]
def F(m,k):
    nm=[]
    for t in[[[v,len([*w])] for v,w in groupby(filter(int,i))]for i in m]:
        a=[i for v,c in t for i in ([2*v]*(c//2)+[v]*(c&1))[::[-1,1][k]]]
        nm+=[a+[0]*(N-len(a))if k else[0]*(N-len(a))+a]
    return nm
q=[m]
for i in R(5):
    Q=[]
    for m in q:M=[*zip(*m)];Q+=[F(m,1),F(m,0),F(M,0),F(M,1)]
    q=Q
print(max(max(map(max,m))for m in q))