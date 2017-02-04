// Doubly Linked List to BST
// Andrew Le
// EMAIL: andrewle19@csu.fullerton.edu
// 12/1/15

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Global arrary for transfering names between dll and binary tree
string nameTransfer[1000];

// Global arrary for transfering middle intial 
string middleTransfer[1000];
class List
{
private:
	// student object node struct
	struct student{
		string intials; // intials of student
		string firstname; // student name 
		string lastname; // student last name
		string middleintial; // middle intial
		student *next; // node next pointer
		student *prev; // node previous pointer
		int nodenumber;

	};
	int nodenumber = 0; // the node number
	student* head; // head of list
	student* temp; // temp node
	student* tail; // tail pontiner
	student* current;

public:
	// default constuctor
	List()
	{
		head = NULL;
		tail = NULL;
		temp = NULL;
		current = NULL;
	}

	// Fill Student ClassRoom 
	// parameter list: studetn Firstname, student intials , student Lastname
	void FillStudentClassroom(string my_name, string my_intials, string my_lastname, string middleintial)
	{
		student* n = new student; // create new node student pointer
		n->next = NULL; // make it point to Null this will put node at the end of the list
		n->prev = NULL; // make previous point to null;
		// add data to story
		n->firstname = my_name;
		n->intials = my_intials;
		n->lastname = my_lastname;
		n->middleintial = middleintial;
		n->nodenumber = nodenumber;

		if (head != NULL) // if the head already exists
		{
			tail->next = n; // tail will will be at the end so insert the new node after the tail
			n->prev = tail; // make the new node prev point to the old tail
			tail = n; // make new node the tail
		}
		else // if list is not made
		{
			head = n; // head will equal new node
			tail = n; // tail will equal new node
		}

		nodenumber++;
	}

	// Print List Forward
	// Displays list using the next node till gets to the end starting at head
	void PrintForward()
	{
		temp = head; // starts at the front of the list
		cout << '\n';
		cout << "Classroom List" << endl;
		while (temp != NULL)
		{
			cout << "Student FirstName: " << temp->firstname << endl;
			cout << "Student Last Name: " << temp->lastname << endl;
			cout << "Student Intials: " << temp->intials << endl;
			cout << "Node Number " << temp->nodenumber << endl;
			cout << '\n';
			temp = temp->next; // advances the list
		}
	}

	// Print Backwards
	// Displays list starting from the end the tail to the beggining the head
	void PrintBack()
	{
		temp = tail; // starts at the back of the list
		cout << '\n';
		cout << "Classroom List" << endl;
		while (temp != NULL)
		{

			cout << "Student FirstName: " << temp->firstname << endl;
			cout << "Student Last Name: " << temp->lastname << endl;
			cout << "Student Intials: " << temp->intials << endl;
			cout << "Node Number " << temp->nodenumber << endl;
			cout << '\n';
			temp = temp->prev; // advances the list
		}
	}


	int SizeList()
	{
		temp = head; // start at the head of the list
		int counter = 0; // counter for students
		while (temp != NULL)
		{
			counter++; // increment counter for every node
			temp = temp->next; // traverse and advance the list
		}
		return counter;

	}


	// Load Dummy Data
	void DummyData()
	{
		FillStudentClassroom("Lauren", "LYT", "Takata","Y");
		FillStudentClassroom("Andrew", "ADL", "Le","D");
		FillStudentClassroom("Stalin", "SMS", "Su","M");
		FillStudentClassroom("Kosei", "KEA", "Arima","E");
		FillStudentClassroom("Benny", "BAJ", "Jets", "A");
		FillStudentClassroom("Tom", "TFB", "Brady","F");
		FillStudentClassroom("Richard", "RMR", "Rodgers", "R");
		FillStudentClassroom("Phillip", "PVR", "Rivers", "V");

	}

	// Transfers the first names in list to the global string arrary
	void getFirstName()
	{
		temp = head;
		int i = 0;
		while (temp != NULL) // traverse until empty
		{
			nameTransfer[i++] = temp->firstname;  // place names inside array
			temp = temp->next; // treverse list
		}
	}

	// Transfer the Last names in the list to global string arrary
	void getLastName()
	{
		temp = head;
		int i = 0;
		while (temp != NULL) // traverse until empty
		{
			nameTransfer[i++] = temp->lastname;  // place names inside array
			temp = temp->next; // treverse list
		}

	}

	// Transfer the intials in the list to global string arrary
	void getIntials()
	{
		temp = head;
		int i = 0;
		while (temp != NULL) // traverse until empty
		{
			nameTransfer[i++] = temp->intials;  // place names inside array
			temp = temp->next; // treverse list
		}
	}

	// Transfers the middle intials in the list to global string arrary
	void getMiddleI()
	{
		temp = head;
		int i = 0;
		while (temp != NULL) // traverse until empty
		{
			middleTransfer[i++] = temp->middleintial;  // place names inside array
			temp = temp->next; // treverse list
		}
	}

};

// binary search tree
class BST
{
private:

	struct node
	{
		int nodenumber; // node number
		int rightnumber = 0; // right numbver of children
		int leftnumber = 0; // left number of children
		string data; // store data like intials last name or first name
		string middleintial; // stores middle intial just in case there are two first names
		node *right; // right pointer > root
		node *left; // left pointer < root
	};
	bool found = false; // to search for a key and stop recursion
	node* root;
	node* temp;
	int nodenumber = 0; // keeps track of node number

	// Inserts new node into the tree
	// Parameter: data needed to be added, ptr that will be the root allows easier insertion 
	// return none
	void AddNodePrivate(string data, string middle, node* rootPTR)
	{
		temp = rootPTR; // temp will be the root ptr to determine the left number and right number 
		if (root == NULL) // if the tree is empty
		{
			root = CreateNode(data, middle);// create the new node and make the root point to it

		}

		else if (data < rootPTR->data) // if the tree exists place the data on the left if it is less than the root
		{
			if (rootPTR->left != NULL) // the root->left already exists
			{
				AddNodePrivate(data, middle, rootPTR->left); // use recursion to go through it again if the data is less than the root on then if will go on the left of this

			}
			else
			{
				rootPTR->left = CreateNode(data, middle); // create new node then point it to root->left
				temp->leftnumber = rootPTR->left->nodenumber; // left child
			}
		}

		// if the data is greater than the root put it on the right
		else if (data > rootPTR->data)
		{
			if (rootPTR->right != NULL) // if the root->right already exists
			{
				AddNodePrivate(data, middle, rootPTR->right); // Use Recursion to see if the data is greater or less than root->right 
			}
			else
			{
				rootPTR->right = CreateNode(data, middle); // creates new node places it on right
				temp->rightnumber = rootPTR->right->nodenumber; // right child
			}
		}
		// case if the key or data already exists within the node
		else if (data == rootPTR->data)
		{
			// if middle is less put on left side
			if (middle < rootPTR->middleintial)
			{
				if (rootPTR->left != NULL) // the root->left already exists
				{
					AddNodePrivate(data, middle, rootPTR->left); // use recursion to go through it again if the data is less than the root on then if will go on the left of this
				}
				else
				{
					rootPTR->left = CreateNode(data, middle); // create new node then point it to root->left
					temp->leftnumber = rootPTR->left->nodenumber; // left child
				}
			}
			// if middle is greater put right side
			else if (middle > rootPTR->middleintial)
			{
				if (rootPTR->right != NULL) // if the root->right already exists
				{
					AddNodePrivate(data, middle, rootPTR->right); // Use Recursion to see if the data is greater or less than root->right 
				}
				else
				{
					rootPTR->right = CreateNode(data, middle); // creates new node places it on right
					temp->rightnumber = rootPTR->right->nodenumber; // right child
				}
			}
		}
	}

	// Print out in order
	void DisplayTreePrivate(node* rootptr)
	{
		if (rootptr != NULL) // if the tree exists
		{
			if (rootptr->left != NULL)  // if the left side is not empty print that out first
			{
				DisplayTreePrivate(rootptr->left); // recursivly go through the left side of the tree
			}
			cout << "Student: " << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out 

			if (rootptr->right != NULL)
			{
				DisplayTreePrivate(rootptr->right); // recursivly go through the right side of the tree
			}
		}
		else // if the tree is empty
		{
			cout << "Tree is Empty" << endl;
		}
	}

	// Print out tree pre order
	void DisplayTreePrivate2(node* rootptr)
	{
		if (rootptr != NULL)
		{
			cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out 
			if (rootptr->left != NULL)  // if the left side is not empty print that out first
			{
				DisplayTreePrivate2(rootptr->left); // recursivly go through the left side of the tree
			}

			if (rootptr->right != NULL) // if right side is not empty
			{
				DisplayTreePrivate2(rootptr->right); // recursivly go through the right side of the tree
			}
		}
		else // if the tree is empty
		{
			cout << "Tree is Empty" << endl;
		}
	}


	// Print out Tree Post Order
	void DisplayTreePrivate3(node* rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL)  // if the left side is not empty print that out first
			{
				DisplayTreePrivate3(rootptr->left); // recursivly go through the left side of the tree
			}
			if (rootptr->right != NULL) // if right side is not empty
			{
				DisplayTreePrivate3(rootptr->right); // recursivly go through the right side of the tree
			}
			cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out 

		}
		else // if the tree is empty
		{
			cout << "Tree is Empty" << endl;
		}
	}

	// Display the tree with right and left children shown
	void DisplayTreeChild(node* rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->data == ""){
				cout << "";
			}
			else
			{
				cout << "Student: " << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out 
				// if the left number or left child is NULL or 0
				if (rootptr->leftnumber == 0)
				{
					cout << "Left Child Node: NULL";
				}
				else // if there is a left child
				{
					cout << "Left Child Node: " << rootptr->leftnumber;
				}
				// if the right number or right child is NULL or 0
				if (rootptr->rightnumber == 0)
				{
					cout << " Right Child Node: NULL";
				}
				else
				{
					cout << " Right Child Node: " << rootptr->rightnumber;
				}
				cout << endl;
				cout << '\n';
				if (rootptr->left != NULL)  // if the left side is not empty print that out first
				{
					DisplayTreeChild(rootptr->left); // recursivly go through the left side of the tree
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					DisplayTreeChild(rootptr->right); // recursivly go through the right side of the tree
				}
			}
		}
		else // if the tree is empty
		{
			cout << "Tree is Empty" << endl;
		}
	}

	// Searches for a key in a pre order traversal
	// parameter: key is the disired searched item
	void SearchKeyPrePrivate(string key, node* rootptr)
	{

		if (rootptr != NULL)
		{
			if (found == false) // stops recursion if found
			{
				cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out

				if (rootptr->data == key) // check if the key is equal to the data we traverse through
				{
					found = true;
					cout << key << " found in BST " << endl;

				}
				else
				{
					if (rootptr->left != NULL)  // if the left side is not empty print that out first
					{
						SearchKeyPrePrivate(key, rootptr->left); // recursivly go through the left side of the tree
					}

					if (rootptr->right != NULL) // if right side is not empty
					{
						SearchKeyPrePrivate(key, rootptr->right); // recursivly go through the right side of the tree
					}
				}
			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}

	// Searches for key in In Order Traversal
	// parameter key is the disired searched item
	void SearchKeyInOrderPrivate(string key, node* rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				SearchKeyInOrderPrivate(key, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{
				cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out
				if (rootptr->data == key) // check if the key is true or not
				{
					found = true;
					cout << key << " found in BST " << endl;
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					SearchKeyInOrderPrivate(key, rootptr->right); // recursivly go through the right side of the tree
				}

			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}


	// Searchs for Key in Post Order Traversal
	// Parameter key is the disired searched item
	void SearchKeyPostPrivate(string key, node* rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL)  // if the left side is not empty print that out first
			{
				SearchKeyPostPrivate(key, rootptr->left); // recursivly go through the left side of the tree
			}
			if (rootptr->right != NULL) // if right side is not empty
			{
				SearchKeyPostPrivate(key, rootptr->right); // recursivly go through the right side of the tree
			}
			if (found == false) // stops recursion if found
			{


				cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl;
				if (rootptr->data == key) // check if the key is equal to the data we traverse through
				{
					found = true;
					cout << key << " found in BST " << endl;
				}
			}

		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}

	// Search for a key the if found update the node
	// paramter key is the disired searched item, tree choice is the users choice in trees to update
	void UpdateNodeP(string key, int treechoice, node* rootptr)
	{
		string newkey; // update key if found
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				UpdateNodeP(key, treechoice, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{
				cout << rootptr->data << " nodenumber:" << rootptr->nodenumber << endl; // print root ptr out
				if (rootptr->data == key) // check if the key is true or not
				{
					found = true;
					cout << key << " found in BST " << endl;
					if (treechoice == 1)
					{
						cout << "What is the new First Name: " << endl;
						cin >> newkey;
					}
					else if (treechoice == 2)
					{
						cout << "What is the new Last Name: " << endl;
						cin >> newkey;

					}
					else if (treechoice == 3)
					{
						cout << "What is the new Intials " << endl;
						cin >> newkey;
					}
					rootptr->data = newkey;
					cout << "Node updated Traverse Tree(menu option) to see the Results" << endl;
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					UpdateNodeP(key, treechoice, rootptr->right); // recursivly go through the right side of the tree
				}

			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}

	// Search for key by using the node number
	// parameter node number is the disired searched node number
	void SearchbyNodeP(int nodenumber, node* rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				SearchbyNodeP(nodenumber, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{

				if (rootptr->nodenumber == nodenumber) // check if the key is true or not
				{
					found = true;
					cout << "Nodenumber: " << nodenumber << " found in BST Key: " << rootptr->data << endl;
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					SearchbyNodeP(nodenumber, rootptr->right); // recursivly go through the right side of the tree
				}

			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}


	// Find Height of BST
	// parameter root
	// returns the biggest height of both sides starting at the root
	int FindHeightP(node* rootptr)
	{

		int leftheight;
		int rightheight;

		if (rootptr != NULL)
		{
			leftheight = FindHeightP(rootptr->left);
			rightheight = FindHeightP(rootptr->right);
			return max(leftheight, rightheight) + 1;
		}
		else
		{
			return -1;
		}
	}

	// Find the Predessesor
	void FindParentP(int nodenumber, node *rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				FindParentP(nodenumber, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{

				if (rootptr->leftnumber == nodenumber) // check if the key is true or not
				{
					found = true;
					cout << "Student: " << rootptr->data << " is the parent/predecessor to nodenumber: " << nodenumber << endl;
				}
				if (rootptr->rightnumber == nodenumber) // check if the key is true or not
				{
					found = true;
					cout << "Student: " << rootptr->data << " is the parent/predecessor to nodenumber: " << nodenumber << endl;
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					FindParentP(nodenumber, rootptr->right); // recursivly go through the right side of the tree
				}

			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}

	// Find the Children or Child
	void FindChildP(int nodenumber, node *rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				FindChildP(nodenumber, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{

				if (rootptr->nodenumber == nodenumber) // if node number if ound
				{
					found = true;
					if (rootptr->left != NULL) // if the left child is not empty print it
					{
						cout << "NodeNumber: " << nodenumber << " left successor/nodenumber: " << rootptr->leftnumber;
					}
					else
					{
						cout << "NodeNumber: " << nodenumber << " left successor/nodenumber: NULL ";
					}
					if (rootptr->right != NULL) // if the right child is not empty print it
					{
						cout << " right successor/nodenumber: " << rootptr->rightnumber << endl;
					}
					else
					{
						cout << " right successor/nodenumber: NULL" << endl;
					}
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					FindChildP(nodenumber, rootptr->right); // recursivly go through the right side of the tree
				}
			}
		}
		else // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
	}

	void DeleteNodeP(int nodenumber, node *rootptr)
	{
		if (rootptr != NULL)
		{
			if (rootptr->left != NULL) // if left side not empty go through left side first
			{
				DeleteNodeP(nodenumber, rootptr->left); // recursivly go through the left side of the tree
			}
			if (found == false) // stops recursion if found
			{

				if (rootptr->nodenumber == nodenumber) // if node number if ound
				{
					found = true;
					cout << "Student: " << rootptr->data << " deleted from BST" << endl;
					
					if (rootptr->left == NULL && rootptr->right == NULL)
					{
						rootptr->data = "";
					}
				}

				if (rootptr->right != NULL) // if right side is not empty
				{
					DeleteNodeP(nodenumber, rootptr->right); // recursivly go through the right side of the tree
				}
			}
		}
	}
public:

	// defualt constructor
	BST()
	{
		root = NULL;
	}

	//Create new Node
	// Parameter: data to insert
	// returns a new node
	node* CreateNode(string data,string middleintial)
	{
		node* newNode = new node; // make new node
		newNode->data = data; // assign it data
		newNode->middleintial = middleintial; // assign the key with middle intial
		newNode->nodenumber = nodenumber; // puts in node number
		newNode->right = NULL;
		newNode->left = NULL;

		nodenumber++; // increments node number when added / created
		return newNode;
	}

	// inserts data creating tree
	// allows the user not to worry about the adress by calling the AddNodePrivate Function
	void AddNode(string data,string middle)
	{
		AddNodePrivate(data,middle,root); // calling the add node private which will add a node to a specific address
	}

	// Display the Tree in order from left to right 
	// Allows user not to worry about the address by calling Display Tree Private
	void DisplayTreeOrder()
	{
		DisplayTreePrivate(root);
	}

	// Display Tree Pre order root then left to right
	void DisplayTreePre()
	{
		DisplayTreePrivate2(root);
	}

	// Display Tree Post order left than right then root
	void DisplayTreePost()
	{
		DisplayTreePrivate3(root);
	}

	// Searches for key in pre order
	// Allows user not to worry about address
	void SearchKeyPre(string key)
	{
		found = false;
		cout << '\n';
		SearchKeyPrePrivate(key, root);

		if (found == false)
		{
			cout << "Key " << key << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Searches for key in Order 
	// Allows user not to worry about adress
	void SearchKeyInOrder(string key)
	{
		found = false;
		cout << '\n';
		SearchKeyInOrderPrivate(key, root);

		if (found == false)
		{
			cout << "Key " << key << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Searchs for key in Post Order
	// Allows user not to worry about adress

	void SearchKeyPost(string key)
	{
		found = false;
		cout << '\n';
		SearchKeyPostPrivate(key, root);

		if (found == false)
		{
			cout << "Key " << key << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Size of Binary Search Tree
	void SizeTree()
	{
		cout << "The BST has " << nodenumber << " nodes" << endl;
	}

	// Update Node Tree
	// Allows user not to worry about address
	void UpdateNode(string key, int treechoice)
	{
		found = false;
		UpdateNodeP(key, treechoice, root);
		if (found == false)
		{
			cout << "Key " << key << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Search for key node by using node number
	// allows user not to worry about address
	void SearchbyNode(int nodenumber)
	{
		found = false;
		cout << '\n';
		SearchbyNodeP(nodenumber, root);

		if (found == false)
		{
			cout << "Nodenumber: " << nodenumber << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Display the Whole Tree with the right child number and left child number
	void DisplayTree()
	{
		DisplayTreeChild(root);
	}

	// finds the height of the tree then prints the result
	void FindHeight()
	{
		int height = FindHeightP(root); // height of tree
		if (height == -1) // if the tree is empty
		{
			cout << "Tree is empty" << endl;
		}
		else
		{
			cout << "Height of BST: " << height << endl;
		}
		cout << '\n';
	}

	// Find the parent or predessesor
	void FindParent(int nodenumber)
	{
		found = false;
		FindParentP(nodenumber, root);
		
		if (found == false)
			{
				cout << "Nodenumber: " << nodenumber << " was not found in BST" << endl;
			}

		cout << '\n';
	}

	// Find the Children
	void FindChild(int nodenumber)
	{
		found = false;
		FindChildP(nodenumber, root);

		if (found == false)
		{
			cout << "Nodenumber: " << nodenumber << " was not found in BST" << endl;
		}

		cout << '\n';
	}

	// Delete the Node
	void DeleteNode(int nodenumber)
	{
		found = false;
		DeleteNodeP(nodenumber, root);

		if (found == false)
		{
			cout << "Nodenumber: " << nodenumber << " was not found in BST" << endl;
		}

		cout << '\n';
	}
};

int main()
{
	//Global arrary for transfering names between dll and binary tree
	string nameTransfer[1000];

	// Global arrary for transfering middle intial 
	string middleTransfer[1000];
	List Studentlist;
	BST SearchTreeFN;
	BST SearchTreeLN;
	BST SearchTreeI;

	int choice; // user choice
	int userchoice;
	bool quit = false;
	bool quit2 = false;

	while (quit == false)
	{
		cout << "Binary Search Tree Menu " << endl;
		cout << "0: Quit " << endl;
		cout << "1: Doubly Linked List Menu" << endl;
		cout << "2: Create BST for First Name" << endl;
		cout << "3: Create BST for Last Name " << endl;
		cout << "4: Create BST for Intials " << endl;
		cout << "5: Display BST" << endl;
		cout << "6: Add Node to BST" << endl;
		cout << "7: Traverse FirstName BST Pre/Post/InOrder" << endl;
		cout << "8: Traverse LastName BST Pre/Post/InOrder" << endl;
		cout << "9: Traverse Intials BST Pre/Post/InOrder" << endl;
		cout << "10: Display BST with node numbers and intials only" << endl;
		cout << "11: Search BST for Key in PreOrder " << endl;
		cout << "12: Search BST for Key in InOrder " << endl;
		cout << "13: Search BST for Key in PostOrder " << endl;
		cout << "14: Search BST by Nodenumber then print Key " << endl; // 8.37
		cout << "15: Determine Size of BST " << endl;
		cout << "16: Update Node Content " << endl;
		cout << "17: Find the Height of BST" << endl;
		cout << "18: Find the Predecessor or Parent" << endl;
		cout << "19: Find the Successors or Children" << endl;
		cout << "20: Delete Node in BST " << endl;
		cout << "21: Dummy Data for DLL(Recommended to run first)" << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;

		// quit program
		if (choice == 0)
		{
			cout << "Quiting Program" << endl;
			return 0;
		}

		// DLL menu
		else if (choice == 1)
		{
			while (quit2 == false)
			{
				cout << '\n';
				cout << "Doubly Linked List Menu" << endl;
				cout << "0: Quit " << endl;
				cout << "1: Fill Student Classroom List" << endl;
				cout << "2: Print Forward " << endl;
				cout << "3: Print Backwards " << endl;
				cout << "4: Size of List " << endl;
				cout << "Enter Choice(0-4): " << endl;
				cin >> userchoice;
				cout << '\n';
				// quit list
				if (userchoice == 0)
				{
					cout << "Back to Main Menu" << endl;
					quit2 = true;
				}
				else if (userchoice == 1)
				{
					string firstname;
					string lastname;
					string Intials;
					string middleintial;

					cout << "What is FirstName: " << endl;
					cin >> firstname;
					cout << "What is LastName: " << endl;
					cin >> lastname;
					cout << "What is the Intials: " << endl;
					cin >> Intials;
					cout << "What is the middleintial" << endl;
					cin >> middleintial;

					Studentlist.FillStudentClassroom(firstname, lastname, Intials, middleintial);
				}
				else if (userchoice == 2)
				{
					Studentlist.PrintForward();
				}
				else if (userchoice == 3)
				{
					Studentlist.PrintBack();
				}
				else if (userchoice == 4)
				{
					cout << "Student list contains " << Studentlist.SizeList() << " students" << endl;
				}
			}
		}
		// create BST First Name
		else if (choice == 2)
		{
			int userchoice; // let user choose
			bool valid = false; // valid or not

			Studentlist.getFirstName(); // puts names into the array transfer
			Studentlist.getMiddleI();

			for (int i = 0; i < Studentlist.SizeList(); i++) // runs the add node until the list is empty
			{
				SearchTreeFN.AddNode(nameTransfer[i], middleTransfer[i]);  // adds node creating tree
			}
			cout << '\n';
			cout << "First Name Tree created:" << endl;

			while (valid == false)
			{
				cout << "Display Tree:" << endl;
				cout << "0: Dont Display Tree" << endl;
				cout << "1: Display in Order" << endl;
				cout << "2: Display in Pre Order " << endl;
				cout << "3: Display in Post Order " << endl;
				cout << "Enter Choice(0-3): " << endl;
				cin >> userchoice;
				cout << '\n';
				// Does not Display
				if (userchoice == 0)
				{
					valid = true;
				}
				// Display in Order
				else if (userchoice == 1)
				{
					SearchTreeFN.DisplayTreeOrder(); // displays nodes in order
					valid = true;
				}
				// Display in Pre Order
				else if (userchoice == 2)
				{
					SearchTreeFN.DisplayTreePre(); // display pre order
					valid = true;
				}
				else if (userchoice == 3)
				{
					SearchTreeFN.DisplayTreePost(); // display post order
					valid = true;
				}
				else
				{
					cout << "Choice not valid Please Enter(0-3)" << endl;
				}
			}
			cout << '\n';
		}

		// create BST Last Name
		else if (choice == 3)
		{
			int userchoice; // let user choose
			bool valid = false; // valid or not

			Studentlist.getLastName(); // puts last names into arrary transfer
			Studentlist.getMiddleI();
			for (int i = 0; i < Studentlist.SizeList(); i++) // runs the add node until the list is empty
			{
				SearchTreeLN.AddNode(nameTransfer[i], middleTransfer[i]);  // adds node creating tree
			}

			cout << "Last Name Tree created:" << endl;

			while (valid == false)
			{
				cout << "Display Tree:" << endl;
				cout << "0: Dont Display Tree" << endl;
				cout << "1: Display in Order" << endl;
				cout << "2: Display in Pre Order " << endl;
				cout << "3: Display in Post Order " << endl;
				cout << "Enter Choice(0-3): " << endl;
				cin >> userchoice;
				cout << '\n';
				// Does not Display
				if (userchoice == 0)
				{
					valid = true;
				}
				// Display in Order
				else if (userchoice == 1)
				{
					SearchTreeLN.DisplayTreeOrder(); // displays nodes in order
					valid = true;
				}
				// Display in Pre Order
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTreePre(); // display pre order
					valid = true;
				}
				else if (userchoice == 3)
				{
					SearchTreeLN.DisplayTreePost(); // display post order
					valid = true;
				}
				else
				{
					cout << "Choice not valid Please Enter(0-3)" << endl;
				}
			}
			cout << '\n';

		}

		// create BST for Intials

		else if (choice == 4)
		{
			bool valid = false; // valid  choice
			int userchoice; // user choice


			Studentlist.getIntials();
			Studentlist.getMiddleI();

			for (int i = 0; i < Studentlist.SizeList(); i++) // runs the add node until the list is empty
			{
				SearchTreeI.AddNode(nameTransfer[i], middleTransfer[i]);  // adds node creating tree
			}

			cout << '\n';
			cout << "Intials Tree created:" << endl;

			while (valid == false)
			{
				cout << "Display Tree:" << endl;
				cout << "0: Dont Display Tree" << endl;
				cout << "1: Display in Order" << endl;
				cout << "2: Display in Pre Order " << endl;
				cout << "3: Display in Post Order " << endl;
				cout << "Enter Choice(0-3): " << endl;
				cin >> userchoice;
				cout << '\n';
				// Does not Display
				if (userchoice == 0)
				{
					valid = true;
				}
				// Display in Order
				else if (userchoice == 1)
				{
					SearchTreeI.DisplayTreeOrder(); // displays nodes in order
					valid = true;
				}
				// Display in Pre Order
				else if (userchoice == 2)
				{
					SearchTreeI.DisplayTreePre(); // display pre order
					valid = true;
				}
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTreePost(); // display post order
					valid = true;
				}
				else
				{
					cout << "Choice not valid Please Enter(0-3)" << endl;
				}
			}
			cout << '\n';

		}

		// Display Whole BST with right child and left child
		else if (choice == 5)
		{
			bool valid = false; // verifys user input
			int userchoice; // takes users input

			while (valid == false)
			{
				cout << "Which BST would you like to Display" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: Last Name BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3)" << endl;
				cin >> userchoice;
				cout << '\n';

				// First name BST
				if (userchoice == 1)
				{
					SearchTreeFN.DisplayTree();
					valid = true;
				}

				// Last name BST
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTree();
					valid = true;
				}

				// Intials BST
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTree();
					valid = true;
				}
				else
				{
					cout << "Choice Invalid Try Again" << endl;
				}
			}
			cout << '\n';
		}

		// Add a new node to the BST
		else if (choice == 6)
		{
			bool valid = false; // check if choice is valid
			int userchoice; // enter user choice
			string name;
			string middleintial;

			while (valid == false)
			{
				cout << "Which List would you like to Add A Node to?" << endl;
				cout << "1:First Name List " << endl;
				cout << "2:Last Name List " << endl;
				cout << "3:Intials List " << endl;
				cout << "Enter Choice(1-3) " << endl;
				cin >> userchoice; // get user choice
				cout << '\n';

				// Adding node to the First Name
				if (userchoice == 1)
				{
					cout << "What is the Student's First Name? " << endl;
					cin >> name;
					cout << "What is the Student's Middle Intial" << endl;
					cin >> middleintial;

					SearchTreeFN.AddNode(name, middleintial);// add node to the tree

					cout << name << " added to the tree" << endl;
					cout << '\n';
					//display the tree
					SearchTreeFN.DisplayTreePre();
					valid = true;
				}
				// Adding node to the last name tree
				else if (userchoice == 2)
				{
					cout << "What is the Student's Last Name? " << endl;
					cin >> name;
					cout << "What is the Student's Middle Intial" << endl;
					cin >> middleintial;

					SearchTreeLN.AddNode(name, middleintial);
					cout << name << " added to the tree" << endl;
					cout << '\n';
					// display the tree
					SearchTreeLN.DisplayTreePre();
					valid = true;
				}
				// Adding node to the Intials tree
				else if (userchoice == 3)
				{
					cout << "What is the Student's Intials? " << endl;
					cin >> name;
					cout << "What is the Student's Middle Intial" << endl;
					cin >> middleintial;

					SearchTreeI.AddNode(name, middleintial);
					cout << name << " added to the tree" << endl;
					cout << '\n';
					// display the tree
					SearchTreeI.DisplayTreePre();
					valid = true;
				}
				else
				{
					cout << "Invalid Choice Try Again " << endl;
				}
			}
			cout << '\n';
		}

		// Traverse First Name Bst
		else if (choice == 7)
		{
			bool valid = false; // verifys user input
			int userchoice; // takes users input

			while (valid == false)
			{
				cout << "How would you like to Traverse BST" << endl;
				cout << "1: In Order" << endl;
				cout << "2: Pre Order" << endl;
				cout << "3: Post Order" << endl;
				cout << "Enter Choice(1-3)" << endl;
				cin >> userchoice;
				cout << '\n';
				// In Order Traverse
				if (userchoice == 1)
				{
					SearchTreeFN.DisplayTreeOrder();
					valid = true;
				}

				// Pre Order Traversal
				else if (userchoice == 2)
				{
					SearchTreeFN.DisplayTreePre();
					valid = true;
				}
				// Post Order Traversal
				else if (userchoice == 3)
				{
					SearchTreeFN.DisplayTreePost();
					valid = true;
				}
				else
				{
					cout << "Choice Invalid Try Again" << endl;
				}
			}
			cout << '\n';
		}

		// Traverse Last Name BST
		else if (choice == 8)
		{
			bool valid = false; // verifys user input
			int userchoice; // takes users input

			while (valid == false)
			{
				cout << "How would you like to Traverse BST" << endl;
				cout << "1: In Order" << endl;
				cout << "2: Pre Order" << endl;
				cout << "3: Post Order" << endl;
				cout << "Enter Choice(1-3)" << endl;
				cin >> userchoice;
				cout << '\n';
				// In Order Traverse
				if (userchoice == 1)
				{
					SearchTreeLN.DisplayTreeOrder();
					valid = true;
				}

				// Pre Order Traversal
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTreePre();
					valid = true;
				}
				// Post Order Traversal
				else if (userchoice == 3)
				{
					SearchTreeLN.DisplayTreePost();
					valid = true;
				}
				else
				{
					cout << "Choice Invalid Try Again" << endl;
				}
			}
			cout << '\n';
		}

		// Traverse Intials BST
		else if (choice == 9)
		{
			bool valid = false; // verifys user input
			int userchoice; // takes users input

			while (valid == false)
			{
				cout << "How would you like to Traverse BST" << endl;
				cout << "1: In Order" << endl;
				cout << "2: Pre Order" << endl;
				cout << "3: Post Order" << endl;
				cout << "Enter Choice(1-3)" << endl;
				cin >> userchoice;
				cout << '\n';
				// In Order Traverse
				if (userchoice == 1)
				{
					SearchTreeI.DisplayTreeOrder();
					valid = true;
				}

				// Pre Order Traversal
				else if (userchoice == 2)
				{
					SearchTreeI.DisplayTreePre();
					valid = true;
				}
				// Post Order Traversal
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTreePost();
					valid = true;
				}
				else
				{
					cout << "Choice Invalid Try Again" << endl;
				}
			}
			cout << '\n';
		}
		// Display BST with node numbers and Intials
		else if (choice == 10)
		{
			SearchTreeI.DisplayTreePre();
		}

		// Search for Key in BST
		else if (choice == 11)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				string key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					cout << "Enter the First Name Key to Be Searched " << endl;
					cin >> key;
					SearchTreeFN.SearchKeyPre(key);
					valid = true; // end loop
				}
				// Last Name BST Search
				else if (userchoice == 2)
				{
					cout << "Enter the Last Name Key to be Searched " << endl;
					cin >> key;
					SearchTreeLN.SearchKeyPre(key);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					cout << "Enter the Intials Key to be Searched " << endl;
					cin >> key;
					SearchTreeI.SearchKeyPre(key);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Search for Key in BST in Order Search
		else if (choice == 12)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				string key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					cout << "Enter the First Name Key to Be Searched " << endl;
					cin >> key;
					SearchTreeFN.SearchKeyInOrder(key);
					valid = true; // end loop
				}
				// Last Name BST Search
				else if (userchoice == 2)
				{
					cout << "Enter the Last Name Key to be Searched " << endl;
					cin >> key;
					SearchTreeLN.SearchKeyInOrder(key);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					cout << "Enter the Intials Key to be Searched " << endl;
					cin >> key;
					SearchTreeI.SearchKeyInOrder(key);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Search for Key in BST Post Order
		else if (choice == 13)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				string key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					cout << "Enter the First Name Key to Be Searched " << endl;
					cin >> key;
					SearchTreeFN.SearchKeyPost(key);
					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					cout << "Enter the Last Name Key to be Searched " << endl;
					cin >> key;
					SearchTreeLN.SearchKeyPost(key);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					cout << "Enter the Intials Key to be Searched " << endl;
					cin >> key;
					SearchTreeI.SearchKeyPost(key);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Search BST by node number then print out the key
		else if (choice == 14)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice
			int searchnumber; // takes the search node number
			while (valid == false)
			{
				cout << "Which BST would you like to search?" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				// First Name BST
				if (userchoice == 1)
				{
					cout << "What is the Node number you would like to search?" << endl;
					cin >> searchnumber;

					SearchTreeFN.SearchbyNode(searchnumber);
					valid = true;
				}
				// Last Name BST
				else if (userchoice == 2)
				{
					cout << "What is the Node number you would like to search?" << endl;
					cin >> searchnumber;
					SearchTreeLN.SearchbyNode(searchnumber);
					valid = true;
				}
				// Intials BST
				else if (userchoice == 3)
				{
					cout << "What is the Node number you would like to search?" << endl;
					cin >> searchnumber;
					SearchTreeI.SearchbyNode(searchnumber);
					valid = true;
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}

		}
		// Determine the Size of BST
		else if (choice == 15)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like the Size Of" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				// First Name BST
				if (userchoice == 1)
				{
					SearchTreeFN.SizeTree();
					cout << '\n';
					valid = true;
				}
				// Last Name BST
				else if (userchoice == 2)
				{
					SearchTreeLN.SizeTree();
					cout << '\n';
					valid = true;
				}
				// Intials BST
				else if (userchoice == 3)
				{
					SearchTreeI.SizeTree();
					cout << '\n';
					valid = true;
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Update Node Contents
		else if (choice == 16)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				string key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					cout << "Enter the First Name Key to Be Searched " << endl;
					cin >> key;
					SearchTreeFN.UpdateNode(key, userchoice);
					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					cout << "Enter the Last Name Key to be Searched " << endl;
					cin >> key;
					SearchTreeLN.UpdateNode(key, userchoice);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					cout << "Enter the Intials Key to be Searched " << endl;
					cin >> key;
					SearchTreeI.UpdateNode(key, userchoice);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Find the Height of the BST
		else if (choice == 17)
		{

			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like the Height To" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				string key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					SearchTreeFN.FindHeight();
					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					SearchTreeLN.FindHeight();
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					SearchTreeI.FindHeight();
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}


		}

		// Find the Parent or Predessor

		else if (choice == 18)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search for Predecessor" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				int key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					SearchTreeFN.DisplayTree();

					cout << "Enter the NodeNumber to be searched? " << endl;
					cin >> key;
					SearchTreeFN.FindParent(key);
					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeLN.FindParent(key);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeI.FindParent(key);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}
		// Find the Successor of node
		else if (choice == 19)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice

			while (valid == false)
			{
				cout << "Which BST would you like to Search for Predecessor" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				int key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					SearchTreeFN.DisplayTree();

					cout << "Enter the NodeNumber to be searched? " << endl;
					cin >> key;
					SearchTreeFN.FindChild(key);
					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeLN.FindChild(key);
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeI.FindChild(key);
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Delete Node
		else if (choice == 20)
		{
			bool valid = false; // checks if user input is valid
			int userchoice; // takes user choice
			int userchoice2;
			bool valid2 = false;
			while (valid == false)
			{
				cout << "Which BST would you like to Search for Predecessor" << endl;
				cout << "1: First Name BST" << endl;
				cout << "2: LastName BST" << endl;
				cout << "3: Intials BST" << endl;
				cout << "Enter Choice(1-3): " << endl;
				cin >> userchoice; // takes user choice
				int key; // user key to search

				// First Name BST Search
				if (userchoice == 1)
				{
					SearchTreeFN.DisplayTree();

					cout << "Enter the NodeNumber to be searched? " << endl;
					cin >> key;
					SearchTreeFN.DeleteNode(key);
					while (valid2 == false)
					{
						cout << "Would you like to Print out BST" << endl;
						cout << "1: Yes / 2: No" << endl;
						cout << "Enter Choice(1-2):" << endl;
						cin >> userchoice2;

						if (userchoice2 == 1)
						{
							SearchTreeFN.DisplayTree();
							valid2 = true;
						}
						else if (userchoice2 == 2)
						{
							valid2 = true;
						}
						else
						{
							cout << "Invalid Choice Try Again " << endl;
						}
					}

					valid = true; // end loop
				}

				// Last Name BST Search
				else if (userchoice == 2)
				{
					SearchTreeLN.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeLN.DeleteNode(key);

					while (valid2 == false)
					{
						cout << "Would you like to Print out BST" << endl;
						cout << "1: Yes / 2: No" << endl;
						cout << "Enter Choice(1-2):" << endl;
						cin >> userchoice2;

						if (userchoice2 == 1)
						{
							SearchTreeLN.DisplayTree();
							valid2 = true;
						}
						else if (userchoice2 == 2)
						{
							valid2 = true;
						}
						else
						{
							cout << "Invalid Choice Try Again " << endl;
						}
					}
					valid = true; // end loop
				}
				else if (userchoice == 3)
				{
					SearchTreeI.DisplayTree();
					cout << "Enter the NodeNumber to be searched?  " << endl;
					cin >> key;
					SearchTreeI.DeleteNode(key);
					while (valid2 == false)
					{
						cout << "Would you like to Print out BST" << endl;
						cout << "1: Yes / 2: No" << endl;
						cout << "Enter Choice(1-2):" << endl;
						cin >> userchoice2;

						if (userchoice2 == 1)
						{
							SearchTreeI.DisplayTree();
							valid2 = true;
						}
						else if (userchoice2 == 2)
						{
							valid2 = true;
						}
						else
						{
							cout << "Invalid Choice Try Again " << endl;
						}
					}
					valid = true; // end loop
				}
				else
				{
					cout << "Invalid Choice Try Again" << endl;
				}
			}
		}

		// Dummy Data
		else if (choice == 21)
		{
			Studentlist.DummyData(); // inputs dummy data
			cout << "Dummy Data Inserted" << endl;
		}

		//Test Script
		else if (choice == 22)
		{
			Studentlist.DummyData(); // inputs dummy data

			Studentlist.getIntials();
			Studentlist.getMiddleI();

			for (int i = 0; i < Studentlist.SizeList(); i++) // runs the add node until the list is empty
			{
				SearchTreeI.AddNode(nameTransfer[i], middleTransfer[i]);  // adds node creating tree
			}

			cout << '\n';
			cout << "Intials Tree created:" << endl;
			cout << "Display BST with Selected Contents " << endl;
			SearchTreeI.DisplayTree();
			cout << "Traverse BST in Order" << endl;
			SearchTreeI.DisplayTreeOrder();
			cout << "Traverse BST Pre Order" << endl;
			SearchTreeI.DisplayTreePre();
			cout << "Traverse BST Post Order" << endl;
			SearchTreeI.DisplayTreePost();
			cout << "Add Node Function(adding YLT)" << endl;
			SearchTreeI.AddNode("YLT","L");
			cout << "Search Pre Order(Searching for SMS): " << endl;
			SearchTreeI.SearchKeyPre("SMS");
			cout << "Search In Order(Searching for LYT)" << endl;
			SearchTreeI.SearchKeyInOrder("SMS");
			cout << "Search Post Order(Searching for TFB)" << endl;
			SearchTreeI.SearchKeyPost("TFB");
			cout << "Search By Node Number(Searching for 5)" << endl;
			SearchTreeI.SearchbyNode(5);
			cout << "BST SIZE Function" << endl;
			SearchTreeI.SizeTree();
			cout << "Update Node Function(Searching for 3)" << endl;
			SearchTreeI.UpdateNode("Kent",3);
			cout << "BST Height " << endl;
			SearchTreeI.FindHeight();
			cout << "BST Find Predessesor(using Node 2 for example)" << endl;
			SearchTreeI.FindParent(2);
			cout << "BST Find Successor(using Node 0 for example) " << endl;
			SearchTreeI.FindChild(0);
			cout << "Delete Node Function(using Node 5 for example)" << endl;
			SearchTreeI.DeleteNode(5);

				
		}
	}
	system("pause");
	return 0;
}

