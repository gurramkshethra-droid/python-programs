import java.util.*;

public class prims {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of vertices:");
        int n = sc.nextInt();

        int cost[][] = new int[n][n];
        int visited[] = new int[n];

        System.out.println("Enter adjacency matrix:");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cost[i][j] = sc.nextInt();
                if(cost[i][j] == 0)
                    cost[i][j] = 999;
            }
        }

        visited[0] = 1;
        int ne = 1, mincost = 0;

        while(ne < n){
            int min = 999, a = -1, b = -1;

            for(int i=0;i<n;i++){
                if(visited[i] == 1){
                    for(int j=0;j<n;j++){
                        if(visited[j] == 0 && cost[i][j] < min){
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }

            System.out.println("Edge " + ne + ": (" + a + "," + b + ") = " + min);
            mincost += min;
            visited[b] = 1;
            cost[a][b] = cost[b][a] = 999;
            ne++;
        }

        System.out.println("Minimum cost = " + mincost);
        sc.close();
    }
}
