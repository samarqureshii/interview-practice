# Write a Python function to check if two strings are anagrams of each other (e.g., "listen" and "silent").

def anagram(str1, str2):
    if(len(str1)!=len(str2)): #if they are not the same length they cant be anagrams
        return False
    else:
        # create a hash table as a frequency map where we map characters to ints
        #count the number of times each letter appears in the word
        #compare the two hashmaps to eachother and if the letter frequency is the same, then return true
        
        charCount = {} #create a frequency map dict (can also hold negative integers!)
        # we will use this dict for both strings, count up for the first one, count down for the second one
        # they should cancel out and become 0 if the two words are anagrams of one another 
        
        #count the chars in the first string
        for char in str1:
            #use the get method 
            charCount[char] = charCount.get(char, 0)+1 #need to use .get() method incase the key does not exist in the dictionary
        #now count the chars in the second string
        for char in str2:
            if char in charCount:
                charCount[char]-=1
            else:
                return False
        
        #now see if they "cancelled out"
        
        for i in charCount.values():
            if i!=0:
                return False