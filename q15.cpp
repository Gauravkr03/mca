#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return node->height;
    }
}

int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return height(node->left) - height(node->right);
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp;
            if (root->left != nullptr) {
                temp = root->left;
            } else {
                temp = root->right;
            }

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inOrderDisplay(Node* root) {
    if (root != nullptr) {
        inOrderDisplay(root->left);
        cout << root->key << " ";
        inOrderDisplay(root->right);
    }
}


#define MAX_QUEUE_SIZE 100

Node* queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

bool isQueueEmpty() {
    return front == rear;
}

void enqueue(Node* node) {
    if (rear < MAX_QUEUE_SIZE) {
        queue[rear++] = node;
    }
}

Node* dequeue() {
    if (!isQueueEmpty()) {
        return queue[front++];
    }
    return nullptr;
}

void bfsTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    enqueue(root);

    while (!isQueueEmpty()) {
        Node* node = dequeue();
        cout << node->key << " ";

        if (node->left != nullptr) {
            enqueue(node->left);
        }
        if (node->right != nullptr) {
            enqueue(node->right);
        }
    }
    cout << endl;
}

void dfsTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        dfsTraversal(root->left);
        dfsTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, key;

    while (true) {
     
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display (In-order)\n";
        cout << "5. BFS Traversal\n";
        cout << "6. DFS Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            root = insert(root, key);
            cout << "Inserted " << key << " into the AVL tree.\n";
        } else if (choice == 2) {
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Deleted " << key << " from the AVL tree.\n";
        } else if (choice == 3) {
            cout << "Enter key to search: ";
            cin >> key;
            if (search(root, key)) {
                cout << "Key " << key << " found in the AVL tree.\n";
            } else {
                cout << "Key " << key << " not found in the AVL tree.\n";
            }
        } else if (choice == 4) {
            cout << "In-order display of AVL tree: ";
            inOrderDisplay(root);
            cout << endl;
        } else if (choice == 5) {
            cout << "BFS traversal: ";
            bfsTraversal(root);
        } else if (choice == 6) {
            cout << "DFS traversal (Pre-order): ";
            dfsTraversal(root);
            cout << endl;
        } else if (choice == 7) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
