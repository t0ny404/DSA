#include <iostream>
#include <fstream>

using namespace std;


int minDistance(int dist[], bool sptSet[], int V)
{

    int minim = INT_MAX, mini;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= minim )
           {
                minim = dist[v];
                 mini = v;
           }


    return mini;
}

int dist[100000];

void dijkstra( int V, int graph[][100000], int src )
{

    bool sptSet[V];

    for ( int i = 0; i < V; i++ )
        {
            dist[i] = INT_MAX;
            sptSet[i] = 0;
        }

    dist[src] = 0;

    for ( int i = 0; i < V - 1; i++ ) {
        int u = minDistance( dist, sptSet, V );

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
               if ( !sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}

int main( int argv, char* argc[] )
{
    ifstream in;
    in.open( argc[1] );
    ofstream out;
    out.open( argc[2] );

    int V, E, S, s, d, w;
    in >> V >> E >> S;

    int graph[V][100000];

    for( int i = 0; i < V; i++ )
        for( int j = 0; j < V; j++ )
        graph[i][j] = 0;

    for( int i = 0; i < E; i++ )
    {
        in >> s >> d >> w;
        graph[s][d] = w;
    }

    dijkstra( V, graph, S);

    for (int i = 0; i < V; i++)
        if( dist[i] != INT_MAX )
            out << dist[i] << " ";
        else
            out << "INF" << " ";

    in.close();
    out.close();

    return 0;
}
