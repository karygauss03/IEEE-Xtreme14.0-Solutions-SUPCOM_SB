N = int(input())
S = list(map(int,input().split()))
Q=int(input())
K=[]
R=[N]
for i in range(Q):
    K.append(int(input()))
r=True
mi=min(K)
R.append(len(set(S)))
T=list(set(S))
while(r):
    T=[S[j-1] for j in T]
    T=list(set(T))
    tt=len(T)
    if(len(R)==0 or tt<R[-1]):
        R.append(tt)
    else:
        r=False
    if (tt<=mi):
        r=False
for i in K:
    if i in R:
        print(R.index(i))
    else:
        print(-1)