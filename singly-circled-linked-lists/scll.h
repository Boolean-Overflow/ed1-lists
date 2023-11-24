typedef struct Node SCLL;

SCLL* scll_init();
SCLL* scll_insert(SCLL* head, char c);
SCLL* scll_remove(SCLL* head, char c);
void scll_print(SCLL* head);
int scll_find(SCLL* head, char c);
SCLL* scll_clear(SCLL* head);
int scll_split(SCLL** head, SCLL** vowals_head_pointer, SCLL** consonants_head_pointer);



