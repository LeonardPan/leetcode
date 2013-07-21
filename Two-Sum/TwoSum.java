//Two Sum
//Author: Leonard Pan

import java.util.*;

public class TwoSum {
	public class NumberWithIndex implements Comparable<NumberWithIndex> {
		private int num;
		private int index;
		public int getNumber(){
			return num;
		}
		public int getIndex(){
			return index;
		}
		public NumberWithIndex(int n, int i){
			num = n;
			index = i;
		}
		public int compareTo(NumberWithIndex n){
			return num - n.num;
		}
	}
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ArrayList<NumberWithIndex> arrayNumIndex = new ArrayList<NumberWithIndex>();
    	for(int i = 0; i < numbers.length; ++i){
    		arrayNumIndex.add(new NumberWithIndex(numbers[i], i+1));
    	}
        //Arrays.sort(numbers);
    	Collections.sort(arrayNumIndex);
        int left = 0, right = numbers.length - 1;
        int[] result = new int[2];
        while(left < right)
        {
            if(arrayNumIndex.get(left).getNumber() + arrayNumIndex.get(right).getNumber() == target) {
            	int index1 = arrayNumIndex.get(left).getIndex();
            	int index2 = arrayNumIndex.get(right).getIndex();
            	result[0] = index1 < index2 ? index1 : index2;
            	result[1] = index1 > index2 ? index1 : index2;
                break;
            }
            else if(arrayNumIndex.get(left).getNumber() + arrayNumIndex.get(right).getNumber() < target){
                ++left;
            }
            else{
                --right;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        // Start typing your code here...
        //System.out.println("Hello world!");
    	TwoSum twoSum = new TwoSum();
        int[] number = new int[]{150,24,79,50,88,345,3};
        int target = 200;
        int[] indexes = twoSum.twoSum(number, target);
        System.out.println(String.format("[%d, %d]", indexes[0], indexes[1]));
        
    }
}