#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

node *root;

void insertNode(int v);
void postOrder(node *p);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    root = NULL;

    while (scanf("%d", &n) != EOF) {
        insertNode(n);
    }

    postOrder(root);

    return 0;
}

void insertNode(int v)
{
    node *p, *newNode, *temp;

    newNode = (node *) malloc(sizeof(node));
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    p = root;
    while (p != NULL) {
        temp = p;

        if (v < p->value) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if (v < temp->value) {
        temp->left = newNode;
    }
    else {
        temp->right = newNode;
    }
}

void postOrder(node *p)
{
    if (p == NULL) {
        return;
    }

    postOrder(p->left);
    postOrder(p->right);
    printf("%d\n", p->value);
}
