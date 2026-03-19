class Solution {
    public int reverse(int x) {
        int temp = x;
        int rem, rev = 0;

        while (temp != 0) {
            rem = temp % 10;

            // overflow check
            if (rev > Integer.MAX_VALUE / 10 || rev < Integer.MIN_VALUE / 10) {
                return 0;
            }

            rev = (rev * 10) + rem;
            temp = temp / 10;
        }

        return rev; // no need for if(x<0)
    }
}
