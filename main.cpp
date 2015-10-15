#include <iostream>

using namespace std;

/**

The Complete Singly Linked List
Program Reference in C++
by Amruth A. Pillai (@AmruthPillai on Facebook)
https://github.com/AmruthPillai


Graphical Representation of Linked List
---------------------------------------

    |-------------|
    | data | NULL |
    |-------------|
       tempNode

    |-------------|    |-------------|    |-------------|
    | data | link ---->| data | link ---->| data | NULL |
    |-------------|    |-------------|    |-------------|
       firstNode


Complete Functions List
-----------------------

O. Generic Functions
    0. Exit the Program
    1. Display Linked List

I. Insertion Operations
    1. Insert at Front
    2. Insert at Rear
    3. Insert before Key
    4. Insert after Key

II. Deletion Operations
    1. Delete from Front
    2. Delete from Rear
    3. Delete Key

III. Special Operations
    1. Count Number of Nodes
    2. Search for Key

**/

// Defining Singly Linked List Node Structure
struct node {
    int data;
    struct node *link;
};

// Defining a type NODE to reformat to type 'struct node *'
typedef struct node NODE;

class LinkedList {

// Private Declarations
private:
    NODE *firstNode;

// Public Declarations
public:

    // Default Constructor
    LinkedList() {
        firstNode = NULL;
    }

    // Destructor
    ~LinkedList() {
        delete firstNode;
    }

    // Generic Functions
    bool isListEmpty();
    void displayLinkedList();

    // Insertion Operations
    void insertAtFront();
    void insertAtRear();
    void insertBeforeKey();
    void insertAfterKey();

    // Deletion Operations
    void deleteFromFront();
    void deleteFromRear();
    void deleteKey();

};

/***************************
    I. Generic Functions
***************************/

/**
    0. Check if List is Empty
        Checks if the list is empty, returns true if it is.
**/
bool LinkedList :: isListEmpty() {

    // Linked List is said to be empty if the First Node is NULL
    if (firstNode == NULL)
        return true;
    else
        return false;

}

/**
    1. Display Linked List
        Display the List, pretty self-explanatory.
**/
void LinkedList :: displayLinkedList() {

    // Declare and Initialize cursor to First Node
    NODE * cursor = firstNode;

    // Check if List is Empty
    if ( isListEmpty() ) {
        cout << "The List is empty, nothing to Display!" << endl;
        return;
    }

    cout << "The Linked List is as follows:" << endl;

    // Traverse through the list
    while (cursor != NULL) {

        // Print Data in Current Cursor
        cout << "\t" << cursor -> data;

        cursor = cursor -> link;

    }

    cout << endl;

}

/******************************
    I. Insertion Operations
******************************/

/**
    1. Insert At Front
        Insert an element specified by the user at the beginning of the list.
**/
void LinkedList :: insertAtFront() {

    // Create a new Temporary Node
    NODE * tempNode = new NODE;

    // Initialize Temporary Node to NULL
    tempNode -> link = NULL;

    // Get User Input for the New Node
    cout << "Enter data for the new node: ";
    cin >> tempNode -> data;

    // Link Temporary Node to First Node
    tempNode -> link = firstNode;

    // Change First Node index to the New Node
    firstNode = tempNode;

}

/**
    2. Insert At Rear
        Insert an element specified by the user at the end of the list.
**/
void LinkedList :: insertAtRear() {

    // Declare and Initialize cursor to First Node
    NODE * cursor = firstNode;

    // Create a new Temporary Node
    NODE * tempNode = new NODE;

    // Initialize Temporary Node to NULL
    tempNode -> link = NULL;

    // Get User Input for the New Node
    cout << "Enter data for the new node: ";
    cin >> tempNode -> data;

    // If List is Empty, perform Insert at Front operation
    if ( isListEmpty() ) {

        // Link Temporary Node to First Node
        tempNode -> link = firstNode;

        // Change First Node index to the New Node
        firstNode = tempNode;

        return;

    }

    // Traverse till Last but One Node in List
    while (cursor -> link != NULL)
        cursor = cursor -> link;

    // Connect Last Node to the New Node
    cursor -> link = tempNode;

}

/**
    3. Insert Before a Key
        Insert an element specified by the user before a key in the list.
**/
void LinkedList :: insertBeforeKey() {

    // Declare keyElement
    int keyElement;

    // Query the User for the Key
    cout << "Enter the key you want to search for: ";
    cin >> keyElement;

    // Declare and Initialize cursor to First Node
    NODE * cursor = firstNode;

    // Declare and Initialize Pre-Cursor to follow the Cursor
    NODE * preCursor = cursor;

    // Create a new Temporary Node
    NODE * tempNode = new NODE;

    // Initialize Temporary Node to NULL
    tempNode -> link = NULL;

    // Get User Input for the New Node
    cout << "Enter data for the new node: ";
    cin >> tempNode -> data;

    // If keyElement is first Node in the List, perform Insert at Front
    if (cursor -> data == keyElement) {
        tempNode -> link = cursor;
        firstNode = tempNode;
        return;
    }

    // Traverse through the list
    while (cursor != NULL) {

        // If keyElement was found, break from loop
        if (cursor -> data == keyElement)
            break;

        preCursor = cursor;
        cursor = cursor -> link;

    }

    // If the keyElement was not found in the List, print appropriate message
    if (cursor == NULL) {
        cout << "The key element was not found in the list, operation aborted!" << endl;
        return;
    }

    // Connect Pre-Cursor to the new Node
    preCursor -> link = tempNode;

    // Connect new Node to current Cursor
    tempNode -> link = cursor;

}

/**
    4. Insert After a Key
        Insert an element specified by the user after a key in the list.
**/
void LinkedList :: insertAfterKey() {

    // Declare keyElement
    int keyElement;

    // Query the User for the Key
    cout << "Enter the key you want to search for: ";
    cin >> keyElement;

    // Declare and Initialize cursor to First Node
    NODE * cursor = firstNode;

    // Create a new Temporary Node
    NODE * tempNode = new NODE;

    // Initialize Temporary Node to NULL
    tempNode -> link = NULL;

    // Get User Input for the New Node
    cout << "Enter data for the new node: ";
    cin >> tempNode -> data;

    // Traverse through the list
    while (cursor != NULL) {

        // If keyElement was found, break from loop
        if (cursor -> data == keyElement)
            break;

        cursor = cursor -> link;

    }

    // Connect new Node to the Next Node
    tempNode -> link = cursor -> link;

    // Connect current Cursor to the new Node
    cursor -> link = tempNode;

}

/******************************
    II. Deletion Operations
******************************/

/**
    1. Delete from Front
        Delete the first element in the list.
**/
void LinkedList :: deleteFromFront() {

    // If List is Empty, perform Insert at Front operation
    if ( isListEmpty() ) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    // Declare and Initialize cursor to First Node
    NODE * cursor = firstNode;

    // Change the first Node index to the next cursor node
    firstNode = cursor -> link;

    // Delete cursor
    delete cursor;

}

/**
    2. Delete from Rear
        Delete the last element in the list.
**/
void LinkedList :: deleteFromRear() {

    // If List is Empty, perform Insert at Front operation
    if ( isListEmpty() ) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    // Declare and Initialize Cursor to First Node
    NODE * cursor = firstNode;

    // Declare and Initialize Pre-Cursor to NULL
    NODE * preCursor = cursor;

    // If there exists only one Node in list
    if (cursor -> link == NULL) {

        // Make first Node point to NULL
        firstNode = NULL;

        // Delete Cursor Element
        delete cursor;

        return;

    }

    // Traverse till last node, then break
    while (cursor -> link != NULL) {
        preCursor = cursor;
        cursor = cursor -> link;
    }

    // Pre-Cursor set to NULL
    preCursor -> link = NULL;

    // Delete Cursor Element
    delete cursor;

}

/**
    3. Delete Key
        Delete a specified element in the list.
**/
void LinkedList :: deleteKey() {

    // If List is Empty, perform Insert at Front operation
    if ( isListEmpty() ) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    // Declare and Initialize Cursor to First Node
    NODE * cursor = firstNode;

    // Declare and Initialize Pre-Cursor to Cursor
    NODE * preCursor = cursor;

    // Declare keyElement
    int keyElement;

    // Query the User for the Key
    cout << "Enter the key you want to search for: ";
    cin >> keyElement;

    if (cursor -> link == NULL) {

        // Make first Node point to NULL
        firstNode = NULL;

        // Delete Cursor Element
        delete cursor;

        return;

    }

    // Traverse through the list
    while (cursor != NULL) {

        // If keyElement was found in the list, break from loop
        if (cursor -> data == keyElement)
            break;

        preCursor = cursor;
        cursor = cursor -> link;
    }

    // Connect Pre-Cursor to the next-to-next Cursor
    preCursor -> link = cursor -> link;

    // Delete current cursor element
    delete cursor;

}

int main()
{
    int choice = 1;

    // Creating Object for Linked List
    LinkedList * listObj = new LinkedList();

    cout << "Welcome to the Complete Singly Linked List Reference!" << endl;
    cout << "by Amruth A. Pillai (@AmruthPillai)" << endl;

    while (choice) {

        cout << endl << "Operations" << endl;
        cout << "\t0. Exit the Program" << endl;
        cout << "\t1. Display Linked List" << endl;
        cout << "\t2. Insertion Operations" << endl;
        cout << "\t3. Deletion Operations" << endl;
        cout << "\t4. Special Functions" << endl;

        // Take User Input
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        // 1. Display Linked List
        case 1:
            listObj -> displayLinkedList();
            break;

        // 2. Insertion Operations
        case 2:
            cout << endl << "I. Insertion Operations" << endl;
            cout << "\t1. Insert at Front" << endl;
            cout << "\t2. Insert at Rear" << endl;
            cout << "\t3. Insert before a Key" << endl;
            cout << "\t4. Insert after a Key" << endl;

            // Take User Input
            cout << endl << "Enter your choice: ";
            cin >> choice;

            switch (choice) {

            // 1. Insert at Front
            case 1:
                listObj -> insertAtFront();
                break;

            // 2. Insert at Rear
            case 2:
                listObj -> insertAtRear();
                break;

            // 3. Insert before a Key
            case 3:
                listObj -> insertBeforeKey();
                break;

            // 4. Insert after a Key
            case 4:
                listObj -> insertAfterKey();
                break;

            }

            break;

        // 3. Deletion Operations
        case 3:
            cout << endl << "II. Deletion Operations" << endl;
            cout << "\t1. Delete from Front" << endl;
            cout << "\t2. Delete from Rear" << endl;
            cout << "\t3. Delete Key" << endl;

            // Take User Input
            cout << endl << "Enter your choice: ";
            cin >> choice;

            switch (choice) {

            // 1. Delete from Front
            case 1:
                listObj -> deleteFromFront();
                break;

            // 2. Delete from Rear
            case 2:
                listObj -> deleteFromRear();
                break;

            // 3. Delete Key
            case 3:
                listObj -> deleteKey();
                break;

            break;

            }

        }

    }

    return 0;
}
