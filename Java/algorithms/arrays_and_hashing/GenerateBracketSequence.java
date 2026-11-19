import java.io.*;
import java.util.List;
import java.util.ArrayList;
//HackerRank - Generate Valid Angle Bracket Sequences
// Given n, return all valid sequences of n pairs of '<' and '>' with proper nesting.

public class GenerateBracketSequence{

    public static void main(String[] args){
        if(args.length == 0){
            System.out.println("Please enter an argument");
            return;
        }

        int n = Integer.parseInt(args[0]);
        if( n > 12 || n <= 0){
            System.out.println("\nPlease enter a number greater than 0 and less than 13");
            return;
        }

        List<String> sequences = generateBracketSequence(n);
            for (String seq : sequences) {
                System.out.println(seq);
            }
        System.out.println("n = " + n);
        System.out.println("Sequences: " + sequences.size());

        return;
    }

    public static List<String> generateBracketSequence(int n){

        ArrayList<String> result = new ArrayList<>();
        validBrackets(n, 0, "", result);
        return result;       
    }

    //recursive sequence
    static void validBrackets(int n, int open, String current, ArrayList<String> result){
        //3 conditionals
        //1. terminiating condition
        if(current.length() == (n * 2)){
            result.add(current);
            return;
        }
        //2. is open counter less than n. If so add bracket.
        if(open < n){
            validBrackets(n, open + 1, current + "<", result);
        }
        //3. if difference of string length and open brackets applied is less than open brackets applied, use a closed bracket
        if(current.length() - open < open){
            validBrackets(n, open, current + ">", result);
        }
    }
    
}