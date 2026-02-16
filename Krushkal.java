import java.util.*;

class Kruskal {

    static int parent[];

    static int find(int i){
        while(parent[i] != i)
            i = parent[i];
        return i;
    }

    static void union(int i, int j){
        int a = find(i);
        int b = find(j);
        parent[a] = b;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of vertices:");
        int n = sc.nextInt();

        int cost[][] = new int[n][n];
        parent = new int[n];

        System.out.println("Enter adjacency matrix:");
        for(int i=0;i<n;i++){
            parent[i] = i;
            for(int j=0;j<n;j++){
                cost[i][j] = sc.nextInt();
                if(cost[i][j] == 0)
                    cost[i][j] = 999;
            }
        }

        int ne = 1, mincost = 0;

        while(ne < n){
            int min = 999, a = -1, b = -1;

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][j] < min){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            int u = find(a);
            int v = find(b);

            if(u != v){
                System.out.println("Edge " + ne + ": (" + a + "," + b + ") = " + min);
                mincost += min;
                union(u,v);
                ne++;
            }

            cost[a][b] = cost[b][a] = 999;
        }

        System.out.println("Minimum cost = " + mincost);
        sc.close();
    }
}
