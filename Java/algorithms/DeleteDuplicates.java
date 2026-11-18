
//Write a function "deleteDuplicates" that removes consecutive duplicate nodes in-place, retaining only the first node of each code. Return the head of the resulting list.
import java.io.*; //wildcard

public class RemoveDuplicates{

    public static void main(String[] args){

        //Build Linked List
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(2);
        head.next.next.next = new Node(2);
        head.next.next.next.next = new Node(2);
        head.next.next.next.next.next = new Node(3);
        head.next.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next.next.next = new Node(5);

        //// print initial list
        printNodes(head);

        //Algorithm
        removeDuplicates(head);
        
        //// print updated list
        printNodes(head);
        return;

    }
    //Algorithm
    static void removeDuplicates(Node head){
        
        Node current = head;

        while (current != null && current.next !=null){
            //if current node matches the next node
            if( current.data == current.next.data){
                current.next = current.next.next; //prune and join the following
            }
            else{//ONLY if no nodes match, traverse forward
                current = current.next; 
            }
        }
        return;
    }
    //Utility Function
    static void printNodes(Node head){
        Node temp = head;
        while (temp != null) {
            if(temp.next == null ){
            System.out.print(temp.data + "\n");
            }
            else{
            System.out.print(temp.data + " ");
            }
            temp = temp.next;
        }
    }

}
//Class Definition
//Singly Linked List Node 
    class Node {
            int data;
            Node next;

            Node(int nodeData) {
                this.data = nodeData;
                this.next = null;
            }
    }