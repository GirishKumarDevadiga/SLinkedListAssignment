#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../Headers/slist.h"

Slist slist_new() {
    Slist s1 = {NULL, NULL, 0};
    return s1;
}

uint32_t slist_length(const Slist *list){
    assert(list != NULL);
    return list->length;
}

//helper function which is not visible outside
static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

Slist* slist_addnode_head(Slist *list, int32_t val){
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);

    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL){
        list->tail = new_node;
    }
    ++list->length;

    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;
}


Slist*   slist_addnode_tail(Slist *list, int32_t val){
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);

    if(list->tail != NULL) {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else{
        list->head = list->tail = new_node; // when yu add node for first time
    }

    ++list->length;

    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;

}

uint8_t slist_lookup(const Slist *list, int32_t key) {
    assert (list != NULL);
    Node *cur = list->head;

    for ( cur = list->head ; cur != NULL; cur = cur->next ){
        if (cur->data == key ){
            break;
        }
    }
    //if (cur != NULL) { return 1;} else { return 0;}
    return (cur != NULL);
}


Slist* slist_delnode_head(Slist *list) {
    assert(list != NULL);
    Node *temp;
    if (list->head != NULL) {
        list->head = list->head->next;
        if (list-> head == NULL) {
            list->tail = NULL;
        }
        --list->length;
        free(temp);
    }
    return list;
}


Slist* slist_delnode_tail(Slist *list) {
    assert (list !=NULL);
    Node *last, *cur;

    if (list->tail !=NULL) {
        last = list->tail;
        if (list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else {
            for(cur = list->head; cur->next !=last; cur = cur->next);
            list->tail = cur;
            cur->next = NULL;
        }
        --list->length;
        free(last);
    }

    return list;
}


Min_Max slist_min_max_elements(Slist *list){
    assert (list != NULL);
    Min_Max min_max = {list->head->data, list->head->data};
    Node *cur;

        for (cur = list->head; cur->next != NULL; cur = cur->next);
            if (cur->data < min_max.min){
                min_max.min = cur->data;
            }
            if(cur->data > min_max.max){
                min_max.max = cur->data;
            }    
        return min_max;

}

Slist* slist_addnode_afterspecifiedelement(Slist *list, int32_t val, int32_t specifiedval) {
    assert(list != NULL);
    Node *newnode = _get_new_node_(val);
    list->temp = list->head;

    if (list->tail->data == specifiedval){
        list->tail->next = newnode;
        list->tail = newnode;
        ++list->length;
    } else
    {
        
    while(list->temp->next != NULL ){

        if(list->temp->data == specifiedval) {
              newnode->next = list->temp->next;
              list->temp->next = newnode;
              ++list->length;
              break;
        }
        list->temp = list->temp->next;
        
    }
    }

   return list;
}



Slist* slist_deletenode_specifiedelement(Slist *list, int32_t specifiedval) {
    assert(list != NULL);
    list->temp = list->head;
    Node *cur;

    if (list->head != NULL && list->head->data == specifiedval ) {
        list->head = list->head->next;
        if (list-> head == NULL) {
            list->tail = NULL;
        }
        --list->length;
    }

    else if (list->tail->data == specifiedval){
        list->temp = list->tail;
        if (list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else {
            for(cur = list->head; cur->next !=list->temp; cur = cur->next);
            list->tail = cur;
            cur->next = NULL;
        }
        --list->length;

    } 

    else {
        
       for(cur = list->head; cur->data != specifiedval; cur = cur->next){
           list->temp = cur->next;
           if(list->temp->data == specifiedval){
               list->temp = list->temp->next;
               cur->next = list->temp;
               break;
           }

        }

        --list->length;
    }

   return list;
}


Slist* slist_reverselist(Slist *list){
    Node *prev = NULL;
    Node *next = NULL;
    list->tail = list->head;

    while(list->head != NULL) {
        next = list->head->next;
        list->head->next = prev;
        prev = list->head;
        list->head = next;
    }
    list->head = prev;

    return list;
}


int8_t slist_comparetwolist(Slist *list1, Slist *list2){
     Node *cur1, *cur2;

     for(cur1 = list1->head, cur2 = list2->head; cur1 !=NULL, cur2 !=NULL; cur1 = cur1->next, cur2 = cur2->next){
          
          if(cur1->data != cur2->data){
              return 0;
          }
     }

   return 1;
}

Slist* slist_union_list(Slist *list1, Slist *list2){
    Slist *list = list1;
    Node *cur1, *cur2;
    int8_t isPresent = 0;

    for(cur2 = list2->head ; cur2 != NULL; cur2 = cur2->next){
        isPresent = 0;
        for(cur1 = list1->head ; cur1 != NULL; cur1 = cur1->next){
        if(cur1->data == cur2->data){
         isPresent = 1;
         break;
        } 
     }
        if( isPresent == 0){
           list = slist_addnode_tail(list, cur2->data);
     }

    }

    return list;

}


Slist* slist_intersection_list(Slist *list1, Slist *list2){
    Slist s = slist_new();
    Slist *list = &s;
    
    Node *cur1, *cur2;
    int8_t isPresent = 0;

    for(cur2 = list2->head ; cur2 != NULL; cur2 = cur2->next){
        isPresent = 0;
        for(cur1 = list1->head ; cur1 != NULL; cur1 = cur1->next){
        if(cur1->data == cur2->data){
         isPresent = 1;
         break;
        } 
     }
        if( isPresent == 1){
           list = slist_addnode_tail(list, cur2->data);
     }

    }

    return list;

}



Slist*   slist_addnode_unique_elements(Slist *list, int32_t val){
    assert(list != NULL);
    Node *cur;
    int8_t isPresent = 0;

    for(cur = list->head;  cur != NULL; cur = cur->next){
        isPresent = 0;
        if(cur->data == val){
          isPresent = 1;
          break;
        }
    }

    if(isPresent == 0){
    Node *new_node = _get_new_node_(val);

    if(list->tail != NULL) {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else{
        list->head = list->tail = new_node; 
    }

    ++list->length;
    }
    
    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;

}

