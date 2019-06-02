#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Tree_node {
public:
    T data;
    Tree_node *left;
    Tree_node *right;

    explicit Tree_node(T _data){
        data = _data;
        left = NULL;
        right = NULL;
    }

    Tree_node* Find(T data){
        Tree_node *current_node = this;

        while (current_node != NULL) {
            if (current_node->data > data) {
                if (current_node->left != NULL) {
                    current_node = current_node->left;
                }
                else {
                    return current_node;
                }
            }
            else if (current_node->data < data) {
                if (current_node->right != NULL) {
                    current_node = current_node->right;
                }
                else {
                    return current_node;
                }
            }
            else {
                return current_node;
            }
        }
        return NULL;
    }
};


template <class T>
class Tree {
public:
    Tree_node<T> *root;

    Tree() {
        root = NULL;
    }

    void add(T data) {
        Tree_node<T> *node = root->Find(data);

        if (node == NULL) {
            root = new Tree_node<T>(data);
        }
        else if (node->data >= data) {
            node->left = new Tree_node<T>(data);
        }
        else {
            node->right = new Tree_node<T>(data);
        }
    }
};

template <class T>
class Treap_node {
public:
    T key;
    int priority;
    Treap_node* left;
    Treap_node* right;

    Treap_node(int _key, int _priority) {
        key = _key;
        priority = _priority;
        left = NULL;
        right = NULL;
    }
};

template <class T>
class Treap {
public:
    T *root;

    Treap() {
        root = NULL;
    }
};


template <class T>
//Treap_node* Merge(Treap_node *left, Treap_node *right) {
T* Merge(T *left, T *right) {
    if (left == NULL || right == NULL) {
        return (left == NULL) ? right : left;
    }

    if (left->priority > right->priority) {
        left->right = Merge(left->right, right);
        return left;
    } else {
        right->left = Merge(left, right->left);
        return right;
    }
}

template <class T>
//void Split(Treap_node *currentNode, int key, Treap_node *&left, Treap_node *&right) {
void Split(T *currentNode, int key, T *&left, T *&right) {
        if (currentNode == NULL) {
            left = NULL;
            right = NULL;
        } else if (currentNode->key <= key) {
            Split(currentNode->right, key, currentNode->right, right);
            left = currentNode;
        } else {
            Split(currentNode->left, key, left, currentNode->left);
            right = currentNode;
        }
    }

template <class T>
void Add(T *&root, int key, int priority) {
    T *node = new Treap_node<int>(key, priority);
    T *splitLeft = NULL;
    T *splitRight = NULL;
    Split(root, key, splitLeft, splitRight);
    root = Merge(Merge(splitLeft, node), splitRight);
}


template <class T>
int Depth(T *node, int depth) {
    if (node == NULL){
        return depth;
    }
    return max(Depth(node->left, depth + 1), Depth(node->right, depth + 1));
}


int main() {
    int n;                   //количество элементов дерева
    Treap<Treap_node<int>> treap;     //декартово дерево
    Tree<int> tree;              //наивное дерево

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int key, priority;

        cin >> key >> priority;

        tree.add(key);
        Add(treap.root, key, priority);
    }
    cout << (Depth(tree.root, 0) - Depth(treap.root, 0));
}