#include "boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree p;
    p = newTreeNode(root);
    if (p != NULL){
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = newTreeNode(root);
    if (*p != NULL) {
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
}

Address newTreeNode(ElType val) {
    Address p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p) {
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    return p == NULL;
}

boolean isOneElmt (BinTree p) {
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
}

boolean isUnerLeft (BinTree p) {
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
}

boolean isUnerRight (BinTree p) {
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

boolean isBinary (BinTree p) {
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

void printPreorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    }
    else {
        printf("(");
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}

void printInorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    }
    else {
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}

void printPostorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printwithIndentation(BinTree p, int h, int count) {
    int i;
    if (!isTreeEmpty(p)) {
        for (i = 0; i < h * count; i++) {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printwithIndentation(LEFT(p), h, count + 1);
        printwithIndentation(RIGHT(p), h, count + 1);
    }
}


void printTree(BinTree p, int h) {
    printwithIndentation(p, h, 0);
}

int hitungBebek(BinTree root, int n) {
    if (isOneElmt(root)){
        if (n == ROOT(root)) {
            return ROOT(root);
        }
        else {
            return 0;
        }
    } else {
        if (isUnerRight(root)) {
            return (ROOT(root) % 10000) * (hitungBebek(RIGHT(root), n - ROOT(root)) % 10000) % 10000;
        }
        else if (isUnerLeft(root)) {
            return (ROOT(root) % 10000) * (hitungBebek(LEFT(root), n-ROOT(root)) % 10000) % 10000;
        }
        else if (isBinary(root)){
            return (ROOT(root) % 10000) * (hitungBebek(LEFT(root), n-ROOT(root)) % 10000) % 10000 + (ROOT(root) % 10000) * (hitungBebek(RIGHT(root), n-ROOT(root)) % 10000) % 10000;
        }
        else {
            return 0;
        }
    }
    return 0;
}