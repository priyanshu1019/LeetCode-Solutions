/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static String getString(ListNode head)
    {
        ListNode temp = head;
        String values = "";
        while( temp!= null )
        {
            int data = temp.val;
            values  += Integer.toString(data);
            temp     = temp.next;
        }

        return values;
    }
    public static boolean check(String values)
    {
        int low = 0;
        int high= values.length()-1;
        
        while(low <= high )
        {
            if( values.charAt(low) != values.charAt(high))
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    public boolean isPalindrome(ListNode head) {
        String values = getString(head);
        boolean answer= check(values);
        return answer;
    }
}