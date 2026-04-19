import java.util.Scanner;

public class SubsetSum {

    static void findSubset(int[] arr, int n, int target, int index, int sum, String subset) {

        // If sum matches
        if (sum == target) {
            System.out.println(subset);
            return;
        }

        // If sum exceeds or end reached
        if (sum > target || index == n)
            return;

        // Take the element
        findSubset(arr, n, target, index + 1,
                   sum + arr[index],
                   subset + arr[index] + " ");

        // Skip the element
        findSubset(arr, n, target, index + 1,
                   sum,
                   subset);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        System.out.print("Enter target sum: ");
        int target = sc.nextInt();

        System.out.println("Subsets are:");

        findSubset(arr, n, target, 0, 0, "");

        sc.close();
    }
}