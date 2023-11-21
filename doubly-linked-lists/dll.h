typedef struct Node_Route Route;
typedef struct Node_Stop Stop;

Route* route_upsert(char* route_code, Stop* stops);
Stop* stop_push_back(char* name, int passagers);
Stop* stop_get_max_passagers(Route* routes_head);
