#include<stdio.h>
#define INF 999

void dijkstra_algo(int n,int v,int cost[10][10],int dist[])
{
	int i,u,count,w,flag[10],min;
	for(i=1;i<=n;i++)
		flag[i]=0,dist[i]=cost[v][i];
	count=2;
	while(count<=n)
	{
		min=99;
		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++)
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
	}
}

void main()
{
	int n,v,i,j,cost[10][10],dist[10];
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the cost matrix: (Possible Paths)\n\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			printf("\n\tcost[%d][%d] = ",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j] = INF;
		}
	printf("\n Enter the Node Number from which distance will be calculated : ");
	scanf("%d",&v);
	dijkstra_algo(n,v,cost,dist);
	printf("\n Shortest path: (Minimum Cost)\n");
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("\t( %d ) -> ( %d ) , Minimum_cost = ( %d )\n",v,i,dist[i]);
}
