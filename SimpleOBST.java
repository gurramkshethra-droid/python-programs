import java.util.Scanner;

public class SimpleOBST {

    // function to calculate sum of frequencies
    static int sum(int freq[], int i, int j) {
        int s = 0;
        for (int k = i; k <= j; k++)
            s += freq[k];
        return s;
    }

    // main OBST function
    static int obst(int freq[], int i, int j) {

        // if no keys
        if (i > j) return 0;

        // if one key
        if (i == j) return freq[i];

        int min = Integer.MAX_VALUE;

        // try every key as root
        for (int r = i; r <= j; r++) {

            int cost =
                obst(freq, i, r - 1) +   // left
                obst(freq, r + 1, j) +   // right
                sum(freq, i, j);         // total freq

            if (cost < min)
                min = cost;
        }

        return min;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of keys: ");
        int n = sc.nextInt();

        int freq[] = new int[n];

        System.out.println("Enter frequencies:");
        for (int i = 0; i < n; i++)
            freq[i] = sc.nextInt();

        int result = obst(freq, 0, n - 1);

        System.out.println("Minimum cost = " + result);

        sc.close();
    }
}