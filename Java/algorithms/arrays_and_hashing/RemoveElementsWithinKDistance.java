//Remove Elements Within K Distance // HackerRank
// Given a non-decreasing array of integers and an integer K, remove in-place any element that is within K of the previous kept element and return the new length. Use constant extra space and single pass with two pointers.

import java.util.*; //wildcard

public class RemoveElementsWithinKDistance {

    public static void main(String[] args) {

        List<Integer> timestamps = new ArrayList<>(Arrays.asList(1, 4, 7, 10));
        int K = 3;

        System.out.println("Input: ");
        System.out.println("timestamps = " + timestamps );
        System.out.println("K = " + K );


        int output = debounceTimestamps(timestamps, K);

        System.out.println("Output: ");
        System.out.println(output + " " );

        return;
    }

    
    public static int debounceTimestamps(List<Integer> timestamps, int K) {
    int n = timestamps.size();
    if(n == 0)
        return 0;
    
    int a = 0;
    int b = 1;
    int answer = n; //answer starts as length of array
    
    while(b < n){
        int check = (timestamps.get(b) - timestamps.get(a)); //check if element(b) is within K of previous kept element(a)
        
        if(check < K){
            //if true, remove (b)element in place by overwriting it with (a)
            timestamps.set(b, timestamps.get(a));
            b++; //increment pointers forward
            a++;
            answer--; //decrement answer to reflect updated array length
        }
        else{
            a++; //increment pointers forward to update 'previous kept element' and repeat comparison
            b++; //while ends once b reaches n       
        }
        }
    return answer;
    
    }
}