#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    int count;
    bool visited;
    node *Left;
    node *Right;
};

node *root;

void insertNode(int value);
void searchNode(int value, node *p);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    root = NULL;
    vector<int>number;
    int n, i;

    while (scanf("%d", &n) != EOF) {
        number.push_back(n);
        insertNode(n);
    }

    n = number.size();
    for (i = 0; i < n; i++) {
        searchNode(number[i], root);
    }

    return 0;
}

void insertNode(int value)
{
    node *p, *ptr, *newNode;

    newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->count = 1;
    newNode->visited = false;
    newNode->Left = NULL;
    newNode->Right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    p = root;
    while (p != NULL) {
        ptr = p;
        if (p->data == value) {
            p->count++;
            return;
        }
        else if (p->data > value) {
            p = p->Left;
        }
        else {
            p = p->Right;
        }
    }

    if (ptr->data > value) {
        ptr->Left = newNode;
    }
    else {
        ptr->Right = newNode;
    }
}

void searchNode(int value, node *p)
{
    if (p->data == value) {
        if (p->visited == true) {
            return;
        }

        printf("%d %d\n", value, p->count);
        p->visited = true;
        return;
    }
    else if (p->data > value) {
        searchNode(value, p->Left);
    }
    else {
        searchNode(value, p->Right);
    }
}
