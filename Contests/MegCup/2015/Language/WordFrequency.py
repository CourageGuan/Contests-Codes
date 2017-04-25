f = open ('rem.txt')
dic = {}

for line in f:
    cnt = 0
    words = line.split()
    for word in words:
        if word in dic:
            dic[word] += 1
        else:
            dic[word] = 1

lst = []

for word,freq in dic.items():
    lst.append((freq,word))

lst.sort(reverse = True)

for freq,word in lst[:15]:
    print word,freq

