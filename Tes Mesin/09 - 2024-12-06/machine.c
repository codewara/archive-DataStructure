#include "library.h"

void createTree (Tree* T, Details D) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->detail = D;
    node->sibling = NULL;
    node->child = NULL;
    T->root = node;
}

void addChild (Node* parent, Details D) {
    // Condition to check if the root existed
    if (parent) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->detail = D;
        newNode->child = NULL;
        
        // Condition if the parent node doesn't have a child 
        if (parent->child == NULL) {
            newNode->sibling = NULL;
            parent->child = newNode;
        }
        // Otherwise, we'll have to append it to the end of the child list
        else {            // Condition where there's only 1 child
            if (parent->child->sibling == NULL) {
                newNode->sibling = parent->child;
                parent->child->sibling = newNode;
            }
            else {
                // Loop through to find the last child of the list
                Node* last = parent->child;
                while (last->sibling != parent->child) {
                    last = last->sibling;
                }
                newNode->sibling = parent->child;
                last->sibling = newNode;
            }
        }
    }
}

void delAll (Node* parent) {
    // Condition to check if parent existed
    if (parent) {
        // Condition to check if the parent has a child
        if (parent->child) {
            // Condition where there's only 1 child
            if (!parent->child->sibling) {
                delAll (parent->child);
                free (parent);
            }
            // Condition where there are multiple children
            else {
                Node* current = parent->child;
                Node* target;
                
                // Loop through to delete the children sequentially
                while (current->sibling != parent->child) {
                    target = current;
                    current = current->sibling;
                    delAll (target);
                }
                if (current) delAll (current);
                // Delete isolated child
                free (parent);
            }
        }
         // Delete isolated parent
        else free (parent);
    }
}

void delChild (Node* target, Node* parent) {
    // Condition where the parent exist
    if (parent != NULL && target != NULL) {
        Node* current = parent->child;
        if (current != NULL) { 
            // Condition where there's only 1 child 
            if (current->sibling == NULL) {
                // Found condition
                if (parent->child == target) {
                    delAll (parent->child);
                    parent->child = NULL;
                }
                else printf("[!] Node %c has only one child (%c) and it's not the target", parent->detail.name, parent->child->detail.name);
            }
            // Condition where there are multiple children
            else {
                Node* prev = NULL;
                int found = 0;
                
                // Loop until every child is checked
                while (current->sibling != parent->child && found != 0) {
                    // Found condition
                    if (current == target) found = 1;
                    else {
                        prev = current;
                        current = current->sibling;
                    }
                }
                
                // Check the last remaining child, if it's the target, 
                if (current == target && found == 0) found = 1;
                if (found == 1) {
                    Node* last = parent->child;
                    
                    // Loop throught to the last child
                    while (last->sibling != parent->child) {
                        last = last->sibling;
                    }
                    
                    // Prev is not initialized since the target is parent->child in the initial loop
                    if (prev == NULL) {
                        // Condition where there is only 2 children
                        if (current->sibling == last && last->sibling == parent->child) {
                            parent->child = last;
                            last->sibling = NULL;
                        }
                        // Condition where the children count is above 2
                        else {
                            parent->child = current->sibling;
                            last->sibling = parent->child;
                        }
                    }
                    // Normal last child condition
                    else {
                        // Condition where target is last, but there's only 2 children
                        if (prev == parent->child && last->sibling == parent->child) {
                            parent->child->sibling = NULL;
                        }
                        // Normal condition where target is last and there is more than 2 children
                        else {
                            prev->sibling = current->sibling;
                            current->sibling = NULL;
                        }
                    }
                    delAll (current);
                }
                else printf("[!] Node with the name %c is not found", target->detail.name);
            }
        }
    }
}


Node* findNode (Node* root, Details find) {
    Node* result = NULL;
    // Condition where root exists
    if (root != NULL) {
        // Found condition
        if (root->detail.name == find.name) result = root;
        else {
            Node* current = root->child;
            // Condition where current exists
            if (current != NULL) {
                // Condition where current is an only child
                if (current->sibling == NULL) {
                    if (current->detail.name == find.name) result = current; // Found condition
                    else result = findNode (current, find); // If not found, look for it recursively
                }   
                // Condition where there are multiple children
                else {
                    int found = 0;
                    // Check each child of root
                    while (current->sibling != root->child && found == 0) {
                        // Found condition
                        if (current->detail.name == find.name) {
                            result = current;
                            found = 1;
                        }
                        // If not found, search recursively and laterally
                        else {
                            result = findNode (current, find);
                            current = current->sibling;
                            if (result != 0) found = 1;
                        }
                    } 
                    // Process the last node, by now current should point to the last sibling 
                    if (found == 0) {
                        if (current->detail.name == find.name) result = current; // Found condition
                        else result = findNode (current, find); // If not found, look for it recursively
                    }
                }
            }
        }
    }
    return result;
}

void printPre (Node* root) {
    // Condition where root exist
    if (root != NULL) {
        printf(" %c", root->detail.name);

        Node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                printPre (current);
            } 
            // Condition where there are multiple children
            else {
                // Print preorder for each sibling
                while (current->sibling != root->child) {
                    printPre (current);
                    current = current->sibling;
                }
                // Print the last sibling
                printPre (current);
            }
        }
    }
}

void printPost (Node* root) {
    // Condition where root exist
    if (root != NULL) {
        Node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                printPost (current);
            } 
            // Condition where there are multiple children
            else {
                // Print preorder for each sibling
                while (current->sibling != root->child) {
                    printPost (current);
                    current = current->sibling;

                }
                // Print the last sibling
                printPost (current);
            }
        }
        printf(" %c", root->detail.name);
    }
}

void copyTree (Node *root1, Node **root2) {
    if(root1 != NULL){
        (*root2) = (Node *) malloc (sizeof(Node));
        (*root2)->detail = root1->detail;

        (*root2)->sibling = root1->sibling;
        (*root2)->child = root1->child;
        if(root1->child != NULL){
            if(root1->child->sibling == NULL){
                /*jika memiliki satu Node anak*/
                copyTree (root1->child, &(*root2)->child);
            }

            else{
                /*jika memiliki banyak Node anak*/
                Node *ptr1 = root1->child;
                Node *ptr2 = (*root2)->child;

                while(ptr1->sibling != root1->child){
                    copyTree (ptr1, &ptr2);
                    ptr1 = ptr1->sibling;
                    ptr2 = ptr2->sibling;
                }
                /*memproses Node anak terakhir karena
                belum terproses dalam pengulangan*/
                copyTree (ptr1, &ptr2);
            }
        }
    }
}

int treecmp(Node *root1, Node *root2){
    int result = 1;
    if((root1 != NULL)&&(root2 != NULL)){
        if(root1->detail.name == root2->detail.name){
            result = 0;
        }
        else{
            if((root1->child != NULL) && (root2->child != NULL)){
                if(root1->child->sibling == NULL) result = treecmp(root1->child, root2->child);
                else {

                    Node *bantu1 = root1->child;
                    Node *bantu2 = root2->child;

                    while(bantu1->sibling != root1->child){
                        if((bantu1 != NULL) && (bantu2 != NULL)){
                            result = treecmp(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else{
                            result = 0;
                            break;
                        }

                    }
                    /*memproses Node anak terakhir karena belum terproses dalam pengulangan*/
                    result = treecmp(bantu1, bantu2);
                }
            }
        }
    }
    else{
        if((root1 != NULL) || (root2 != NULL)){
            result = 0;
        }
    }
    return result;
}
