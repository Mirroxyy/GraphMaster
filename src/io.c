#include "io.h"

// Инициализация консольного интерфейса
void io_init();


// Главное меню: возвращает выбранный пункт (1-5) или 0 для выхода
int io_main_menu() {
    char input[512];
    char* error = NULL;
    int res;
    printf("1. Shortest path search (Dijkstra).\n"
        "2. Construction of a minimal spanning tree (Kruskal).\n"
        "3. Construction of a minimal spanning tree (Prim).\n"
        "4. Breadth-first Graph Traversal (BFS).\n"
        "5. Comparison of the execution time of MST algorithms.\n"
        "Choose one algorithm for working with graphs (write the number 1-5 or 0 to exit).\n");
    while (1) {
        char* string = fgets(input, sizeof(input), stdin);
        if (string != NULL)
            res = strtol(string, &error, 10);
        if (*error == '\n' && 0 <= res && res <= 5)
            break;
        else
            printf("Incorrect input, please try again.\n");
    }
    return res;
}


// Запрос имени файла
char* io_ask_filename() {
	int len = 256;
	int only_spaces = 1;
	const char* del = "\n";
	char* filename = (char*)malloc(len * sizeof(char));
	printf("Please enter the name of the file with the graph.\n");
	char* check = fgets(filename, len, stdin);
	if (check) {
		int ix = strcspn(filename, del);
		*(filename + ix) = '\0';
		for (int i = 0; filename[i] != '\0'; i++) {
			if (!isspace((unsigned char)filename[i])) {
				only_spaces = 0;
				break;
			}
		}
	}
	while (!check || only_spaces) {
		printf("Incorrect input, please try again.\n\n");
		printf("Please enter the name of the file with the graph.\n");
		check = fgets(filename, len, stdin);
		if (check) {
			int ix = strcspn(filename, del);
			*(filename + ix) = '\0';
			for (int i = 0; filename[i] != '\0'; i++) {
				if (!isspace((unsigned char)filename[i])) {
					only_spaces = 0;
					break;
				}
			}
		}
	}
	return filename;
}
