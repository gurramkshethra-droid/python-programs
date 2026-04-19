import java.util.Scanner;

public class TSP {

    static int n;
    static int[][] cost;
    static boolean[] visited;
    static int minCost = Integer.MAX_VALUE;

    static void tsp(int city, int count, int currCost, int start) {

        // all cities visited
        if (count == n && cost[city][start] > 0) {
            minCost = Math.min(minCost, currCost + cost[city][start]);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (!visited[i] && cost[city][i] > 0) {

                visited[i] = true;

                tsp(i, count + 1,
                    currCost + cost[city][i],
                    start);

                visited[i] = false; // backtrack
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of cities: ");
        n = sc.nextInt();

        cost = new int[n][n];
        visited = new boolean[n];

        System.out.println("Enter cost matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cost[i][j] = sc.nextInt();

        visited[0] = true;

        tsp(0, 1, 0, 0);

        System.out.println("Minimum cost: " + minCost);

        sc.close();
    }
}