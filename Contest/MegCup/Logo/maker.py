#count a picture about 217 logos 
#there is 32 blocks
#so I know the answer is about 217*32
#I guess a range in [-i + 217*32,i + 217*32]  i in [-32,32]
#luckly, I get the right answer when i = 26

for i in range(-32,33):
    f = open(str(i)+".txt",'w')
    f.write(str(i+6944))
