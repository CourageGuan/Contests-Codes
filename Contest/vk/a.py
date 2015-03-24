#f=file('test')

n=int(raw_input())
t={}
mp=[]
cnt=0

def dfs(n,k):
    global cnt
    cnt=max(cnt,k)
    for i in mp[n]:
        dfs(i,k+1)

for i in range(0,n):
    s=raw_input()
    for ch in s.split():
        if ch.lower()=='reposted': continue
        if ch.lower() in t:
            pass
        else:
            mp.append([])
            t[ch.lower()]=cnt
            cnt+=1
    mp[t[s.split()[0].lower()]].append(t[s.split()[2].lower()])

ans=0
for i in range(0,len(mp)):
    if mp[i]!=[]:
        global cnt
        cnt=0
        dfs(i,1)
        ans=max(cnt,ans)

print ans
#f.close()
