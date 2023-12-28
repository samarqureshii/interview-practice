def strdup_every_other_char(s):
    return s[::2]

# alt soln

def every_other(s):
    newS = ""
    for i in range (len(s)):
        if(i%2==0): #even index
            newS+=s[i] #I miss string concat like this (why did I choose low level...)
    return newS;