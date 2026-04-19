import java.util.Scanner;

public class Hamiltonian {

    int V;              // number of vertices
    int[][] graph;
    int[] path;

    // check if safe
    boolean isSafe(int v, int pos) {

        // check if connected
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // check if already used
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    // solve using backtracking
    boolean solve(int pos) {

        // all vertices included
        if (pos == V) {
            // check last to first connection
            return graph[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < V; v++) {

            if (isSafe(v, pos)) {
                path[pos] = v;

                if (solve(pos + 1))
                    return true;
            }
        }
        return false;
    }

    void printSolution() {
        for (int i = 0; i < V; i++)
            System.out.print(path[i] + " ");
        System.out.println(path[0]); // back to start
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();

        int[][] graph = new int[n][n];

        System.out.println("Enter adjacency matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = sc.nextInt();

        Hamiltonian h = new Hamiltonian();
        h.V = n;
        h.graph = graph;
        h.path = new int[n];

        h.path[0] = 0; // start from vertex 0

        if (h.solve(1))
            h.printSolution();
        else
            System.out.println("No Hamiltonian Cycle");

        sc.close();
    }
}