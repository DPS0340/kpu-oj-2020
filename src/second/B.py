def is_palin(w):
    mid = len(w)//2
    if len(w) % 2 == 1:
        return w[:mid] == w[mid+1:][::-1]
    else:
        return w[:mid] == w[mid::][::-1]


def add(w1, w2):
    res = []
    x = 0
    cnt = 0
    for i in range(len(w1))[::-1]:
        x += (ord(w1[i]) + ord(w2[i]) - ord('a') * 2) * (26 ** cnt)
        cnt += 1
    while x:
        res.append(chr(x % 26 + ord('a')))
        x //= 26
    return ''.join(res[::-1])


word = input()
rev = word[::-1]
while not is_palin(word):
    word = add(word, rev)
    rev = word[::-1]
print(word)
