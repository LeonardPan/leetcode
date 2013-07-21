//String 2 Integer
//Author: Leonard Pan

public class StringToInteger {
    public int atoi(String str) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(str.equals(""))
            return 0;
        Boolean neg = false;
        int iStart = 0;
        long result = 0;
        str = str.trim();
        neg = '-' == str.charAt(0) ? true : false;
        if('-' == str.charAt(0) || '+' == str.charAt(0))
            str = str.substring(1);
        while('0' == str.charAt(iStart)) 
            ++iStart;
        if(iStart > 0)
            str = str.substring(iStart);
        if(str.equals(""))
            return 0;
        for(iStart = 0; iStart < str.length(); ++iStart){
        	if(neg && -result < Integer.MIN_VALUE || !neg && result > Integer.MAX_VALUE)
        		break;
            if(str.charAt(iStart) > '9' || str.charAt(iStart) < '0')
                break;
            result *= 10;
            result += str.charAt(iStart) - '0';
        }
        if(neg && result >= 2147483648L)
            return -2147483648;
        if(!neg && result >= 2147483648L)
            return 2147483647;
        return neg ? (int)-result : (int)result;
    }
    public static void main(String[] args) {
        // Start typing your code here...
        //System.out.println("Hello world!");
        String s = new String("      -11919730356x");
        StringToInteger sol = new StringToInteger();
        System.out.println(sol.atoi(s));
        
    }
}
