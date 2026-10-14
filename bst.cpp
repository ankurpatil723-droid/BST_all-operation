
#include <iostream>
using namespace std;

// Create a node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// 1. Insert a node
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// 2. Search for a value
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// 3. Find minimum value
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

// 4. Find maximum value
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

// 5. Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 6. Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 7. Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}



// 8. Delete a node
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Case 1: No child
        if (root->left == nullptr &&
            root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,
                                 temp->data);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Inorder\n";
        cout << "4. Display Preorder\n";
        cout << "5. Display Postorder\n";
        cout << "6. Find Minimum\n";
        cout << "7. Find Maximum\n";
        cout << "8. Delete\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted (if not duplicate).\n";
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Value found!\n";
            else
                cout << "Value not found!\n";
            break;

        case 3:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 6: {
            Node* temp = findMin(root);
            if (temp)
                cout << "Minimum: " << temp->data << endl;
            else
                cout << "Tree is empty.\n";
            break;
        }

        case 7: {
            Node* temp = findMax(root);
            if (temp)
                cout << "Maximum: " << temp->data << endl;
            else
                cout << "Tree is empty.\n";
            break;
        }

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;
            if (search(root, value)) {
                root = deleteNode(root, value);
                cout << "Value deleted.\n";
            } else {
                cout << "Value not found!\n";
            }
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    
    return 0;
}
