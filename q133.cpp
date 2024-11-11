

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

Node *findMin(Node *root) 
{
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}


Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
    {
        cout << "\nEntered Node is not present in BST.\n";
        return root;
    }
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else 
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        cout << data << " deleted from the tree.\n";
    }
    return root;
}



Node *search(Node *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}


void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


void display(Node *root, int space = 0, int height = 10)
{
    if (root == nullptr)
        return;

    space += height;
    display(root->right, space);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << ' ';
    cout << root->data << "\n";

    display(root->left, space);
}
void menu()
{
    cout << "\n--- Binary Search Tree Operations ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. In-order Traversal\n";
    cout << "5. Pre-order Traversal\n";
    cout << "6. Post-order Traversal\n";
    cout << "7. Display Tree\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Node *root = nullptr;
    int choice, value;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << value << " inserted into the tree.\n";
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "Tree structure:\n";
                display(root);
            }
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "Tree structure:\n";
                display(root);
            }

            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value) != nullptr)
                cout << value << " found in the AVL tree.\n";
            else
                cout << value << " not found in the AVL tree.\n";
            break;
        case 4:
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "In-order traversal: ";
                inorder(root);
                cout << endl;
            }
            break;
        case 5:
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "Pre-order traversal: ";
                preorder(root);
                cout << endl;
            }
            break;
        case 6:
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "Post-order traversal: ";
                postorder(root);
                cout << endl;
            }

            break;
        case 7:
            if (root == nullptr)
            {
                cout << "\nTree is empty";
            }
            else
            {
                cout << "Tree structure:\n";
                display(root);
            }
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
