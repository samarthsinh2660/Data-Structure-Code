#include <stdio.h>
#include <stdlib.h>

// Edge structure to represent an edge with weight, start, and end vertices
struct Edge {
    int u, v, weight;
};

// Disjoint Set (Union-Find) structure
struct DisjointSet {
    int *parent, *rank;
    int n;
};

// Function to create a Disjoint Set
struct DisjointSet* createSet(int n) {
    struct DisjointSet *set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->n = n;
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));

    // Initialize parent and rank arrays
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
    return set;
}

// Find operation with path compression
int find(struct DisjointSet *set, int u) {
    if (set->parent[u] != u) {
        set->parent[u] = find(set, set->parent[u]); // Path compression
    }
    return set->parent[u];
}

// Union operation with union by rank
void unionSets(struct DisjointSet *set, int u, int v) {
    int rootU = find(set, u);
    int rootV = find(set, v);

    if (rootU != rootV) {
        // Union by rank
        if (set->rank[rootU] > set->rank[rootV]) {
            set->parent[rootV] = rootU;
        } else if (set->rank[rootU] < set->rank[rootV]) {
            set->parent[rootU] = rootV;
        } else {
            set->parent[rootV] = rootU;
            set->rank[rootU]++;
        }
    }
}

// Function to compare two edges for sorting by weight
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the MST
void kruskal(struct Edge *edges, int V, int E) {
    struct DisjointSet *set = createSet(V);

    // Sort edges by weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree (MST):\n");

    // Iterate through edges and add to MST if they don't form a cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(set, u) != find(set, v)) {
            printf("%d - %d: %d\n", u, v, weight);
            mstWeight += weight;
            unionSets(set, u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

// Main function
int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge *edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
