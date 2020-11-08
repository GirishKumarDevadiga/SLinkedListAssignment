#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Headers/slist.h"

//1. Create a single list with methods to add and delete elements from head and tail positions. 
//   Provide method to check whether an element is present in the list. Count number of elements in the list.
void test_length_addnode_head_tail_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list) == 0);
    list = slist_addnode_head(list, 10);
    assert(slist_length(list) == 1);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    assert(slist_length(list) == 3);
    assert(slist_lookup(list, 20) == 1);
    list = slist_addnode_tail(list, 40);
    list = slist_addnode_tail(list, 50);
    assert(slist_length(list) == 5);
    assert(slist_lookup(list, 50) == 1);
}



void test_delete_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);

    list = slist_delnode_head(list);

    assert (slist_length(list) ==2);
    assert (slist_lookup(list, 30) == 0);
    assert (slist_lookup(list, 20) == 1);
    list = slist_addnode_head(list, 40);
    list = slist_addnode_head(list, 50);
    assert (slist_length(list) ==4);
}

void test_delete_tail(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_tail(list, 10);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 30);

    list = slist_delnode_tail(list);

    assert (slist_length(list) ==2);
    assert (slist_lookup(list, 30) == 0);
    assert (slist_lookup(list, 20) == 1);
    list = slist_addnode_tail(list, 40);
    list = slist_addnode_tail(list, 50);
    assert (slist_length(list) ==4);
}

//2. Add methods to Q1 to find maximum and minimum elements in the list.
void test_min_max(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);

    assert(slist_min_max_elements(list).min == 10);
    assert(slist_min_max_elements(list).max == 30);
}

// 3. Modify Q1 such that one can add a new element after any specified element.
void test_addnodeatspecifiedvalue(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_tail(list, 10);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 40);
    list = slist_addnode_tail(list, 50);
    assert (slist_length(list) == 4);
    list = slist_addnode_afterspecifiedelement(list, 30, 20);
    assert (slist_length(list) == 5);
    assert (slist_lookup(list, 30) == 1);
    list = slist_addnode_afterspecifiedelement(list, 60, 50);
    assert (slist_length(list) == 6);
    assert (slist_lookup(list, 60) == 1);

}

//4. Modify Q1 such that one can delete any specified element from the list.
void test_deletenodespecifiedvalue(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_tail(list, 10);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 30);
    list = slist_addnode_tail(list, 40);
    list = slist_addnode_tail(list, 50);
    assert (slist_length(list) == 5);
    list = slist_deletenode_specifiedelement(list, 10);
    assert (slist_length(list) == 4);
    assert (slist_lookup(list, 10) == 0);
    list = slist_deletenode_specifiedelement(list, 40);
    assert (slist_length(list) == 3);
    assert (slist_lookup(list, 40) == 0);
    list = slist_deletenode_specifiedelement(list, 50);
    assert (slist_length(list) == 2);
    assert (slist_lookup(list, 50) == 0);

}

//5. Write a method to reverse the elements in the same list.
void test_reverselist(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_tail(list, 10);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 30);
    list = slist_addnode_tail(list, 40);

    list = slist_reverselist(list);
    assert(list->head->data == 40);
    assert(list->tail->data == 10);
    
}

//6. Create two separate single lists. Check two list are same. 
//   If the two lists have the same number of elements in the same order, then they are treated as same.
void test_compare_two_list(){
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;

    list1 = slist_addnode_tail(list1, 10);
    list1 = slist_addnode_tail(list1, 20);
    list1 = slist_addnode_tail(list1, 30);
    list1 = slist_addnode_tail(list1, 40);

    list2 = slist_addnode_tail(list2, 10);
    list2 = slist_addnode_tail(list2, 20);
    list2 = slist_addnode_tail(list2, 30);
    list2 = slist_addnode_tail(list2, 40);
    assert(slist_comparetwolist(list1, list2) == 1);

    list1 = slist_addnode_tail(list1, 50);
    list2 = slist_addnode_tail(list2, 55);
    assert(slist_comparetwolist(list1, list2) == 0);
}

//7. Write a method which creates the union of elements from two lists.
void test_union_two_list(){
    Slist s = slist_new();
    Slist *list = &s;
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;

    list1 = slist_addnode_tail(list1, 10);
    list1 = slist_addnode_tail(list1, 20);
    list1 = slist_addnode_tail(list1, 30);
    list1 = slist_addnode_tail(list1, 40);

    list2 = slist_addnode_tail(list2, 10);
    list2 = slist_addnode_tail(list2, 20);
    list2 = slist_addnode_tail(list2, 25);
    list2 = slist_addnode_tail(list2, 45);

    list = slist_union_list(list1, list2);

    assert(slist_length(list) == 6);
    
}

//8. Write a method which creates the intersection of elements from two lists.
void test_intersection_two_list(){
    Slist s = slist_new();
    Slist *list = &s;
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;

    list1 = slist_addnode_tail(list1, 10);
    list1 = slist_addnode_tail(list1, 20);
    list1 = slist_addnode_tail(list1, 30);
    list1 = slist_addnode_tail(list1, 40);

    list2 = slist_addnode_tail(list2, 10);
    list2 = slist_addnode_tail(list2, 20);
    list2 = slist_addnode_tail(list2, 25);
    list2 = slist_addnode_tail(list2, 45);

    list = slist_intersection_list(list1, list2);

    assert(slist_length(list) == 2);
    
}

//9. Create single list such that it should always contain unique elements. 
//   Care should be taken that, if element is already present in the list, you should not add it again.
void test_addnode_unique_elements(){
    Slist s1 = slist_new();
    Slist *list = &s1;

    list = slist_addnode_unique_elements(list, 10);
    list = slist_addnode_unique_elements(list, 10);
    list = slist_addnode_unique_elements(list, 30);
    list = slist_addnode_unique_elements(list, 50);
    list = slist_addnode_unique_elements(list, 50);

    assert(slist_length(list) == 3);

}


int main(){
   test_length_addnode_head_tail_list();
   test_delete_head();
   test_delete_tail();
   test_min_max();
   test_addnodeatspecifiedvalue();
   test_deletenodespecifiedvalue();
   test_reverselist();
   test_compare_two_list();
   test_union_two_list();
   test_intersection_two_list();
   test_addnode_unique_elements();

return 0;

}