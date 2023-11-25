typedef struct Node_Route Route;
typedef struct Node_Stop Stop;

Route* init_routes();
Stop* init_stops();
Route* check_route(Route* routes, int code);
Stop* check_stop(Route* routes, char* name);
Route* route_insert(Route* routes, Stop* stops);
Route* remove_route(Route* routes, int code);
Stop* add_stop(Stop* stops, char* name, int qtd);
Stop* remove_stop(Route* routes, char* name);
void print_route(Route* routes, int code);
Stop* best_stop(Route* routes, int code);
Route* clear_routes(Route* routes);