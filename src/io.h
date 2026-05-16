#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Инициализация консольного интерфейса
void io_init();

// Главное меню: возвращает выбранный пункт (1-5) или 0 для выхода
int io_main_menu();

// Запрос имени файла
char* io_ask_filename();

// Запрос номера вершины
int io_ask_vertex(int max_vertex);

// Вывод сообщения
void io_print(const char *msg);

// Вывод результата Дейкстры
void io_print_dijkstra(const int *path, int path_len, int total_weight);

// // Вывод результата MST
// void io_print_mst(const MSTResult *res);

// Вывод результата BFS
void io_print_bfs(const int *order, int order_len);

// Вывод ошибки
void io_error(const char *msg);

// Очистка ресурсов
void io_cleanup();

#endif
