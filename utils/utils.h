typedef struct Node SCLL;

void clearConsole();

void c1_insert(SCLL** head);
void c1_remove(SCLL** head);
void c1_find(SCLL** head);
void c1_split(SCLL** head);

typedef struct Node_Route Route;
typedef struct Node_Stop Stop;

void c2_insert(Route** routes);
void c2_print(Route** routes);
void c2_remove(Route** routes);
void c2_add_stop(Route** routes);
void c2_rm_stop(Route** routes);
void c2_max(Route** routes);
