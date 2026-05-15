#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

// Представление графа: список смежности
typedef struct {
    int to;         // номер вершины
    int weight;     // вес ребра
    struct EdgeNode *next;
} EdgeNode;

typedef struct {
    int num_vertices;
    EdgeNode **adj; // массив списков смежности
} Graph;

// Загрузка графа из файла (формат списка рёбер)
Graph* load_graph_edges(const char *filename);

// Загрузка графа из матрицы смежности
Graph* load_graph_matrix(const char *filename);

// Сохранение графа в файл (список рёбер)
int save_graph_edges(const Graph *g, const char *filename);

// Создание пустого графа
Graph* create_graph(int num_vertices);

// Добавление ребра (неориентированное)
void add_edge(Graph *g, int u, int v, int weight);

// Освобождение памяти
void free_graph(Graph *g);

// Печать графа (для отладки)
void print_graph(const Graph *g);

#endif
