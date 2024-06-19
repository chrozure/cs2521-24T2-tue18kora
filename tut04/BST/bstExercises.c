#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int bstNumNodes(struct node *t);
int bstCountOdds(struct node *t);
int bstCountInternal(struct node *t);
int bstHeight(struct node *t);
int bstNodeLevel(struct node *t, int key);
int bstCountGreater(struct node *t, int val);

int main(void) {
    struct node *root = bstNew();

    root = bstInsert(root, 5);
    root = bstInsert(root, 2);
    root = bstInsert(root, 3);
    root = bstInsert(root, 4);
    root = bstInsert(root, 6);
    root = bstInsert(root, 1);
    root = bstInsert(root, 7);

    /*
    The tree looks like
            5
           / \
          2   6
         / \   \
        1   3   7
             \
              4
    */

    printf("The tree has %d nodes\n", bstNumNodes(root));
    printf("The tree has %d odd values\n", bstCountOdds(root));
    printf("The tree has %d internal nodes\n", bstCountInternal(root));
    printf("The height of the tree is %d\n\n", bstHeight(root));
    int x = 3;
    int y = 6;
    printf("The node level of %d is %d\n", x, bstNodeLevel(root, x));
    printf("The node level of %d is %d\n", y, bstNodeLevel(root, y));
    printf("The number of nodes greater than %d is %d\n", x, bstCountGreater(root, x));
    printf("The number of nodes greater than %d is %d\n", y, bstCountGreater(root, y));

    bstFree(root);
}

///////////////////////////////////////////////////////

int bstNumNodes(struct node *t) {
    // base case - empty tree
    if (t == NULL) return 0;

    // recursive case - node, and two subtrees
    return 1 + bstNumNodes(t->left) + bstNumNodes(t->right);
}

int bstCountOdds(struct node *t) {
    // base case - empty tree
    if (t == NULL) return 0;

    return t->value % 2 + bstCountOdds(t->left) + bstCountOdds(t->right);
    /*
    int numOddsInLeft = bstCountOdds(t->left);
    int numOddsInRight = bstCountOdds(t->right);

    // recursive case - current value is odd
    if (t->value % 2 == 1) {
        return 1 + numOddsInLeft + numOddsInRight;
    }
    // recursive case - current value is even
    else {
        return numOddsInLeft + numOddsInRight;
    }
    */
}

int bstCountInternal(struct node *t) {
    // base case - empty tree
    if (t == NULL) return 0;

    // base case - leaf node
    if (t->left == NULL && t->right == NULL) return 0;

    // recursive case - internal node
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

int bstHeight(struct node *t) {
    // TODO
    return 0;
}

int bstNodeLevel(struct node *t, int key) {
    // base case - empty tree
    if (t == NULL) return -1;

    // base case - root value is equal to key
    if (t->value == key) return 0;

    // recursive case - key is less than root
    if (key < t->value) {
        int levelInLeftSubtree = bstNodeLevel(t->left, key);
        // value didn't exist in left subtree
        if (levelInLeftSubtree == -1) return -1;
        return 1 + levelInLeftSubtree;
    }

    // recursive case - key is greater than root
    int levelInRightSubtree = bstNodeLevel(t->right, key);
    if (levelInRightSubtree == -1) return -1;
    return 1 + levelInRightSubtree;
}

int bstCountGreater(struct node *t, int val) {
    // TODO
    return 0;
}
