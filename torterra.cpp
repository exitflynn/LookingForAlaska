#include <bits/stdc++.h>
using namespace std;

// Define the Node of the tree
struct Node {
	char data;
	int end;
	struct Node* left;
	struct Node* eq;
	struct Node* right;
};

// Function to create a Node
Node* createNode(char newData)
{
	struct Node* newNode = new Node();
	newNode->data = newData;
	newNode->end = 0;
	newNode->left = NULL;
	newNode->eq = NULL;
	newNode->right = NULL;
	return newNode;
}

// Function to insert a word in the tree
void insert(Node** root, string word, int pos = 0)
{

	// Base case
	if (!(*root))
		*root = createNode(word[pos]);

	// If the current character is less than root's data, then it is inserted in the left subtree

	if ((*root)->data > word[pos])
		insert(&((*root)->left), word,
			pos);

	// If current character is more than root's data, then it is inserted in the right subtree

	else if ((*root)->data < word[pos])
		insert(&((*root)->right), word,
			pos);

	// If current character is same as that of the root's data

	else {
		// If it is the end of word

		if (pos + 1 == word.size())
			// Mark it as the end of word
			(*root)->end = 1;

		// If it is not the end of the string, then current character inserted in the equal subtree

		else
			insert(&((*root)->eq), word, pos + 1);
	}
}

// Function to traverse the ternary search tree
void traverse(Node* root, vector<string>& ret, char* buff, int depth = 0)
{
	// Base case
	if (!root)
		return;
	// The left subtree is traversed first
	traverse(root->left, ret, buff, depth);

	// Store the current character
	buff[depth] = root->data;

	// If the end of the string is detected, store it in the final ans
	if (root->end) {
		buff[depth + 1] = '\0';
		ret.push_back(string(buff));
	}

	// Traverse the equal subtree
	traverse(root->eq, ret, buff, depth + 1);

	// Traverse the right subtree
	traverse(root->right, ret, buff, depth);
}

// Utility function to find all the words
vector<string> util(Node* root,
					string pattern)
{
	// Stores the words to suggest
	char buffer[1001];

	vector<string> ret;

	traverse(root, ret, buffer);

	if (root->end == 1)
		ret.push_back(pattern);
	return ret;
}

// Function to autocomplete based on the given prefix and return the suggestions
vector<string> autocomplete(Node* root, string pattern)
{	
	vector<string> words;
	int pos = 0;

	// If pattern is empty return an empty list
	if (pattern.empty())
		return words;

	// Iterating over the characters of the pattern and find it's corresponding node in the tree

	while (root && pos < pattern.length()) {

		// If current character is smaller
		if (root->data > pattern[pos]) {
			// Search the left subtree
			if (root->left==NULL) {
				words.push_back("-NO WORD FOUND-");
				return words;
			}
			root = root->left;
		}
		// current character is greater
		else if (root->data < pattern[pos]) {
			// Search right subtree
			if (root->right==NULL) {
				cout << "Nothing Found. There is ";
				return words;
			}
			root = root->right;
		}
		// If current character is equal
		else if (root->data == pattern[pos]) {
		
			// Search equal subtree since character is found, move to the next character in the pattern
			if (root->eq==NULL) {
				cout << "[✓]";
				return words;
			}
			root = root->eq;
			pos++;
		}

		else
			return words;

	}

	words = util(root, pattern);

	return words;
}


void print(vector<string> sugg,
		string pat)
{
	for (int i = 0; i < sugg.size();
		i++)
		cout << pat << sugg[i].c_str()
			<< "\n";
}

void getwords (string filename, vector<string> &vecstr)
{
    string line; 
    ifstream myfile (filename);
    string word; 
    if (myfile.is_open()) 
    {
        while (myfile >> word) 
        {
            vecstr.push_back(word);
        }
        myfile.close(); 
    }
    else cout << "can't open the file"; 
}

void searchingHandler(Node* tree) {

	cout << "Enter word to search: ";
	string pat;
	cin >> pat;
	vector<string> sugg
		= autocomplete(tree, pat);
	if (sugg.size() == 0) {
		cout << "None";
	}
	else {
		print(sugg, pat);
	};
};

void submain(string filename, vector <string> &V) {
	getwords(filename, V);
	Node* tree = NULL;
	cout << "Adding data. \n";
	for (string str : V)
		insert(&tree, str);
	cout << "Done. \n";
	while(true){
		searchingHandler(tree);
	}
}

int main(int argc, char* argv[]) {
	vector <string> V;
	if (strcmp(argv[1], "-f") == 0){
		for (int i = 0; i < argc-2; i++) {
			submain(argv[i+2],V);
		};
	};
	return 0;
}
