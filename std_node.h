#ifndef node_h
#define node_h

struct std_node
{
    int id;
    char name[30];
    struct std_node *next;
};

typedef struct std_node* std_NodePtr;

#endif /* std_node_h */