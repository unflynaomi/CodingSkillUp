file=open('good.txt','r')
goodLines=file.readlines()
goodNum=len(goodLines)
print(goodLines)
good={}
for goodLine in goodLines:
    goodLine=goodLine.strip().lower()
    #print(goodLine)
    words=goodLine.split(' ')
    for word in words:
        if word in good.keys():
            good[word]+=1
        else:
            good[word]=1
print(good)

file=open('bad.txt','r')
badLines=file.readlines()
badNum=len(badLines)
print(badLines)
bad={}
for badLine in badLines:
    badLine=badLine.strip().lower()
    #print(badLine)
    words=badLine.split(' ')
    for word in words:
        if word in bad.keys():
            bad[word]+=1
        else:
            bad[word]=1
print(bad)

v=len(good.keys())+len(bad.keys())

print("Vocabulary size:",v)
test="bla bla bj"
testWords=test.lower().split(' ')
goodProb=1
badProb=1
offset=len(str(goodNum+v))
for i in range(len(testWords)):
    goodProb*=10**offset
    badProb*=10**offset
print('badprob init:',badProb)
print('goodProb init:',goodProb)
for testWord in testWords:
    goodProb*=(good.setdefault(testWord,0)+1)/(goodNum+v)
    badProb*=(bad.setdefault(testWord,0)+1)/(badNum+v)

sum=goodProb+badProb
goodProb=goodProb/sum*100
badProb=badProb/sum*100
print('goodProb:%.2f%%'%goodProb)
print('badProb:%.2f%%'%badProb)
if goodProb>badProb:
    print(1)
else:
    print(0)


