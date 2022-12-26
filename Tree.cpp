#include <iostream>
class node {
private:
    int data;

public:
    node *left;
    node *right;

    explicit node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

      void preorder(node *root){
        if (root!= nullptr) {
            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node *root){
        if (root!= nullptr){
            postorder(root->left);
            postorder(root->right);
            std::cout<<root->data<<" ";

        }
    }
    void inorder(node *root){
        if (root!= nullptr){
            postorder(root->left);
            std::cout<<root->data<<" ";
            postorder(root->right);

        }
    }
    bool isBst(node *root){
        static node *prev= nullptr;
        if(root!=nullptr){
            if(!isBst(root->left)) {
                return false;
            }
            if (prev!= nullptr && root->data <= prev->data){
                return false;
            }
            prev = root;
            return isBst(root->right);
        }else{
            return true;
        }
    }
    static node* insert(node *root, int s) {
        if (root == nullptr) {
            return new node(s);
        }

        if (s < root->data) {
            root->left = insert(root->left, s);
        } else if (s > root->data) {
            root->right = insert(root->right, s);
        }

        return root;
    }


};



int main() {
    node *p = new node(4);
    node *p1 = new node(1);
    node *p2 = new node(6);
    node *p3 = new node(5);
    node *p4 = new node(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p->preorder(p);
    std::cout<<" ";
    p->postorder(p);
    std::cout<<" ";
    p->inorder(p);
    std::cout<<" ";
    p->insert(p,7);
    p->inorder(p);
    std::cout<<" ";


    return 0;
}
