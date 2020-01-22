/** 
 * Reference:
 * Stanford University (http://web.stanford.edu/class/cs161/)
 */

/**
 * Dijkstra's computes the shortest paths from a source node 
 * to every other node in the graph.
 */

const int V = 5; // Set to number of vertices

// Find the vertex with minimum distance 
int min(int dist[], bool set[]) { 
	int min = INT_MAX;
    int minIndex;

	for (int v = 0; v < V; v++) {
		if (set[v] == false && dist[v] <= min) {
			min = dist[v];
            minIndex = v; 
        }
    }

	return minIndex; 
}

void dijkstra(int graph[V][V], int s) {
	int dist[V]; // To hold the shortest distance from s to i 
	bool set[V]; // To hold true/false flags (shortest path tree)

	// Initialize distances
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
        set[i] = false; 
    }

	// Source to s is 0
	dist[s] = 0;

	// Find shortest path for all vertices
	for (int i = 0; i < V - 1; i++) { 
		// Set u to the minimum distance 
        // (not yet processed)
		int u = min(dist, set);

		// Set vertex to 'true' as processed 
		set[u] = true;

		// Update value of adjacent vertices
		for (int v = 0; v < V; v++) {
			if (!set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
        }
	}
}