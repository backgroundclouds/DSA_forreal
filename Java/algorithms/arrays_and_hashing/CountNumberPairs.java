public class CountNumberPairs{
//Hacker Rank - Count Number Pairs
//count pairs within an ordered array, where the sum of pairs is less than or equal to target amount 
    public static void main(String[] args){
        int[] testArray = {1, 2, 3, 4, 5};
        int target = 7;

        int count = countNumberPairs(testArray, target);

        System.out.println("Count is : " + count);

        return;

    }

    public static int countNumberPairs(int[] array, int x){
        int result = 0;
        int left = 0;
        int right = array.length - 1;

        while(left < right){
            if(array[left] + array[right] <= x){
                result += (right - left);
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
}