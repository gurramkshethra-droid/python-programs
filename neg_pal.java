class Solution {
    public boolean isPalindrome(int x) {
        int temp=x;
        int rem,rev=0;
        if(x<0) {
            return false;
        }
        while(temp!=0) {
            rem=temp%10;
            rev=(rev*10)+rem;
            temp=temp/10;
        }
        if(rev==x) {
            return true;
        }
        else {
            return false;
        } 
    }
}
