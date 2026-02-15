import java.util.*;
public class Articulation {
   static final int MAX=20;
   static int[] l=new int[MAX];
   static int[] dfn=new int[MAX];
   static int num=1,n;
   static int[][] adjmatrix=new int[MAX][MAX];
   static Stack<Edge> stack=new Stack<>();
   static class Edge {
    int u,v;
    Edge(int u,int v) {
        this.u=u;
        this.v=v;
    }
   }
   static void Articulation(int u,int parent) {
    dfn[u]=l[u]=num++;
    int children=0;
    for(int w=1;w<=n;w++) {
        if(adjmatrix[u][w]==1) {
            if(dfn[w]==0) {
                children++;
                stack.push(new Edge(u,w));
                System.out.println("\nEdge"+u+"--"+w+"is pushed onto stack");
                Articulation(w,u);
                l[u]=Math.min(l[u],l[w]);
                if([parent!=0 && l[w]>=dfn[u]]) {

                    System.out.println("New biconnected component");
                    popComponent(u,w);
                }
                if(parent==0 && ch)


            }
        }
    }
   }
}
