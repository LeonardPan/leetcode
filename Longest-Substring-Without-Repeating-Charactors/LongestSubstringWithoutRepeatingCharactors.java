//rugular expression maching
//Author: Leonard Pan

import java.util.*;
import java.io.*;

public class LongestSubstringWithoutRepeatingCharactors {
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(s.equals(""))
            return 0;
        HashSet<Character> subStrSet = new HashSet<Character>();
        int i, j, longestLen = 1, len = s.length();
        //String subStr = s.substring(0, 1);
        for(i = 0; i < len - longestLen; ++i){
            subStrSet.clear();
            for(j = i; j < len; ++j){
                if(subStrSet.contains(s.charAt(j)))
                    break;
                else{
                    subStrSet.add(s.charAt(j));
                    if(j-i >= longestLen - 1){
                        longestLen = j-i+1;
                        //subStr = s.substring(i, j+1);
                    }
                }
            }
        }
        return longestLen;
    }
    public static void main(String[] args) {
        // Start typing your code here...
        //System.out.println("Hello world!");
    	String inputLine = null;
    	LongestSubstringWithoutRepeatingCharactors lswr = new LongestSubstringWithoutRepeatingCharactors();
		BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
		try{
	    	while(true){
	    		inputLine = is.readLine();
	    		if (0 == inputLine.length())
	    			return;
	            System.out.println(lswr.lengthOfLongestSubstring(inputLine));
	    	}
		}
		catch (IOException e){
			System.out.println("IOException: " + e);
		}
        
    }
}