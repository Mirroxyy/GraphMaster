#include "graph.h"
#include "algorithms.h"
#include "io.h"

int main() {
    io_init();
    Graph *g = NULL;
    int running = 1;

    while (running) {
        int choice = io_main_menu();
        switch (choice) {
            case 0: running = 0; break;
            case 1: {
                // Загрузка графа
                char *fname = io_ask_filename();
                g = load_graph_edges(fname);
                if (!g) g = load_graph_matrix(fname);
                if (!g) io_error("Ошибка загрузки графа");
                free(fname);
                break;
            }
            case 2: {
                // Дейкстра
                if (!g) { io_error("Сначала загрузите граф"); break; }
                int src = io_ask_vertex(g->num_vertices - 1);
                int tgt = io_ask_vertex(g->num_vertices - 1);
                DijkstraResult *res = dijkstra(g, src);
                int path_len;
                int *path = get_path(res, tgt, &path_len);
                io_print_dijkstra(path, path_len, res->dist[tgt]);
                free(path);
                free_dijkstra_result(res);
                break;
            }
            // ... другие case ...
        }
    }

    if (g) free_graph(g);
    io_cleanup();
    return 0;
}
