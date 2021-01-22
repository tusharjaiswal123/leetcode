PROBLEM:



Two strings are considered close if you can attain one from the other using the following operations:
Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"


Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"


Example 4:
Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:
1. 1 <= word1.length, word2.length <= 105
2. word1 and word2 contain only lowercase English letters.





SOLUTION:




class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int i,j,n1,n2,f;
        n1 = word1.size();
        n2 = word2.size();
        vector<int> v1(26,0),v2(26,0);
        
        if(n1!=n2)
            return false;
        
        if(word1==word2)
            return true;
        
        for(i=0;i<n1;i++)
            v1[word1[i]-'a']++;
        
        for(i=0;i<n2;i++)
            v2[word2[i]-'a']++;
        
        for(i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
            {
                if(v1[i]==0 || v2[i]==0)
                    return false;
                
                f=0;
                for(j=i+1;j<26;j++)
                {
                    if(v2[j]==v1[i])
                    {   
                        v2[j]=v2[i];
                        f=1;
                        break;
                    }
                }
                
                if(f==0)
                    return false;
            }
        }
        
        return true;
    }
};






class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int i,j,n1,n2;
        n1 = word1.size();
        n2 = word2.size();
        vector<int> v1(26,0),v2(26,0);
        
        if(n1!=n2)
            return false;
        
        if(word1==word2)
            return true;
        
        for(i=0;i<n1;i++)
            v1[word1[i]-'a']++;
        
        for(i=0;i<n2;i++)
            v2[word2[i]-'a']++;
        
        for(i=0;i<26;i++)
        {
            if(v1[i]!=v2[i] && (v1[i]==0 || v2[i]==0) )
            {
                return false;
            }
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;
    }
};
