typedef struct Node SCLL;

SCLL* scll_init(char c);
SCLL* scll_push_front(SCLL* head, char c);
SCLL* scll_push_middle(SCLL* head, char c);
SCLL* scll_push_back(SCLL* head, char c);
SCLL* scll_remove(SCLL* head, char c);
SCLL* scll_print(SCLL* head, char c);
SCLL* scll_find(SCLL* head, char c);
SCLL* scll_clear(SCLL* head);
void scll_split(SCLL* head, SCLL** vowals_head_pointer, SCLL** consonants_head_pointer);



