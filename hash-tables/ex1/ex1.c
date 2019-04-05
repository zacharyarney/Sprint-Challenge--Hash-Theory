#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
    HashTable *ht = create_hash_table(16);
    Answer *answer = malloc(sizeof(Answer));
    for (int i = 0; i < length; i++) {
        // find target weight--difference between limit and cur index
        int target = limit - weights[i];
        // retrieve the index of target value
        int try = hash_table_retrieve(ht, target);
        // if it already exists return answer
        if (try != -1) {
            answer->index_1 = i;
            answer->index_2 = try;
            // gotta free that malloc!
            destroy_hash_table(ht);
            return answer;
        }
        // insert into hash table
        hash_table_insert(ht, weights[i], i);
    }
    destroy_hash_table(ht);
    // ...otherwise return NULL
    return NULL;
}

void print_answer(Answer *answer)
{
    if (answer != NULL) {
        printf("%d %d\n", answer->index_1, answer->index_2);
    } else {
        printf("NULL\n");
    }
}

#ifndef TESTING
int main(void)
{

    // TEST 1
    int weights_1 = {9};
    Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
    print_answer(answer_1);  // NULL

    // TEST 2
    int weights_2[] = {4, 4};
    Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
    print_answer(answer_2);  // {1, 0}

// TEST 3
int weights_3[] = {4, 6, 10, 15, 16};
Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
print_answer(answer_3);  // {3, 1}

// TEST 4
int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
print_answer(answer_4);  // {6, 2}

return 0;
}
#endif
