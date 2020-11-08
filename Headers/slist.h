#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct _node_
{
    int32_t data;
    Node *next;
};

typedef struct _slist_ Slist;

struct _slist_ {
    Node *head;
    Node *tail; 
    Node *temp;
    uint32_t length;
};

struct _min_max_ {
    int min;
    int max;
};

typedef struct _min_max_ Min_Max;

Slist slist_new();
uint8_t slist_lookup(const Slist *list, int32_t key);
uint32_t slist_length(const Slist *list);
Slist* slist_addnode_head(Slist *list, int32_t val);
Slist* slist_addnode_tail(Slist *list, int32_t val);
Slist* slist_delnode_head(Slist *list); 
Slist* slist_delnode_tail(Slist *list); 
Min_Max slist_min_max_elements(Slist *list);
Slist* slist_addnode_afterspecifiedelement(Slist *list, int32_t val, int32_t specifiedval);
Slist* slist_deletenode_specifiedelement(Slist *list, int32_t specifiedval);
Slist* slist_reverselist(Slist *list);
int8_t slist_comparetwolist(Slist *list1, Slist *list2);
Slist* slist_union_list(Slist *list1, Slist *list2);
Slist* slist_intersection_list(Slist *list1, Slist *list2);
Slist*   slist_addnode_unique_elements(Slist *list, int32_t val);

#endif //SLIST_H_INCLUDED

