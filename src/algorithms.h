#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "graph.h"

// Результат алгоритма Дейкстры
typedef struct {
    int *dist;      // расстояния от стартовой вершины
    int *prev;      // предыдущая вершина в пути
    int source;
} DijkstraResult;

// Поиск кратчайшего пути
DijkstraResult* dijkstra(const Graph *g, int source);

// Восстановление пути в виде массива вершин
int* get_path(const DijkstraResult *res, int target, int *path_len);

// Освобождение результата
void free_dijkstra_result(DijkstraResult *res);

// Результат MST
typedef struct {
    int total_weight;
    int *u, *v;     // массивы рёбер MST
    int num_edges;
} MSTResult;

// Алгоритм Краскала
MSTResult* kruskal(const Graph *g);

// Алгоритм Прима
MSTResult* prim(const Graph *g);

// Освобождение результата MST
void free_mst_result(MSTResult *res);

// Обход в ширину
int* bfs(const Graph *g, int source, int *order_len);

#endif
