#include <iostream>
using namespace std;

template<class T>
class Binary_Tree_Node
{
public:
    T Data;
    Binary_Tree_Node* Left;
    Binary_Tree_Node* Right;

    Binary_Tree_Node(T d){   //конструктор
        Data = d;
        Left = NULL;
        Right = NULL;
    }

    ~Binary_Tree_Node(){       //дектруктор
        delete Left;
        delete Right;
    }
};

template<class T>
class Binary_Tree
{
public:
    Binary_Tree(){           //конструктор
        Root = NULL;
    }

    ~Binary_Tree(){           //деструктор
        delete Root;
    }

    void add(int K){       //добавление элемента
        T* newNode;
        newNode = new T(K);

        if (Root == NULL){
            Root = newNode;
            return;
        }

        T* nextNode = Root;
        while (1){
            if (K < nextNode->Data){
                //идем влево
                if (nextNode->Left != NULL){
                    nextNode = nextNode->Left;
                }
                else{
                    nextNode->Left = newNode;
                    return;
                }
            }
            else{
                //идем вправо
                if (nextNode->Right != NULL){

                    nextNode = nextNode->Right;
                }
                else{
                    nextNode->Right = newNode;
                    return;
                }
            }
        }

    }

    void preOrder(){       //обход pre-order
        preOrder(Root);
    }


private:
    T* Root; // Корневой элемент

    void visit(T* node){ // Вывод элемента
        cout << node->Data << " ";
    }

    void preOrder(T *node){
        if (node == NULL){
            return;
        }

        visit(node);            //вывод элемента
        preOrder(node->Left);   //левое поддерево
        preOrder(node->Right);  //правое поддерево
    }
};


int main(int argc, char* argv[])
{
    int N = 0;
    cin >> N;
    if (N == 0){
        return 0;
    }

    Binary_Tree<Binary_Tree_Node<int>> tree;
    for (int i = 0; i < N; i++){
        int K = 0;
        cin >> K;
        tree.add(K);
    }

    tree.preOrder();  //вывод  дерева методом pre-order

    return 0;
}
