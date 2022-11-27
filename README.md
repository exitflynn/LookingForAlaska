# LookingForAlaska _(because I couldn't settle on a name)_

A C++ program that uses Ternary Search Trees to search from a large data quickly and efficiently.
 
## Usage:
1. `torterra.cpp` contains the main code, compile it using `g++`.
```console
$ g++ torterra.cpp -o turtwig
```
2. Run the output file and pass the to-search file(s) as argument using the `-f` flag.
```console
$ ./turtwig -f words.txt
```
That should _ideally_ be it, if you face any bug feel free to open an issue!
 
# About the project 

Ternary Search Trees are a Data Structure similar to Binary Search Trees, the only difference being that each node includes three children. BST’s require rearrangement of entire data which accounts for extreme inefficiency when a dataset is very large. To counter this, the data structures trie’s can be used where each node has 26 children each corresponding to a possibility in the english alphabet. We would also need to include special characters and spaces which would only add to the extremely large amounts of space the trie would take up, be it only in storing the large amount of null pointers. Ternary Search Trees take care of both of these issues by not requiring any rearrangement, while not taking up too much space.
The project has a wide array of implementations, ranging from using it to search usernames to movie names from a database.

In order to demonstrate the power of this project, we will be implementing the user being able to search phrases / nearest-matching phrases in a directory containing a large number of .txt files.
If no such phrase is available, the closest-matching phrase along will be displayed as per user input provided to the system. 

Project Objectives 
To demonstrate the power of using ternary search trees for searching a large amount of data, very quickly while not taking up a lot of space as is the case with Tries. We plan to do this by using them for providing autocomplete and closest suggestion to a search term present in given files.

# Dataset Description

The dataset can be as large as the phonebook of a city or a directory containing a large number of research papers. To provide a demonstration for a general case, we have implemented in-file searching for any given files. The files can be given in the form of a directory path and more than one files can be added (not necessarily in the same directory).
# Features of the project 
- Search/Autocomplete for a given term FAST- You will be able to find a given term provided a list of source files.
- Memory Efficient- Using ternary tree as the primary data structure ensures that we do not tradeoff heavily on memory for gains in speed of searching/autocompletion.
- Specify Multiple Files- You can specify multiple files among which you want to search your text from.
- CLI- You can pass all the filepaths as parameters while running the executable directly from the CLI using the -f flag.
 
Data Structures Used are -

- Ternary Search Trees

- Vectors

- Just those two 



# Tries
We know of Binary Search Trees where each node has at most two children/subtrees. Tries are k-ary trees. Unlike BST’s a node in a trie doesn’t store its associated key, instead 	its position in the tree determines that key.


![image](https://user-images.githubusercontent.com/97532274/204037782-41196463-cdd6-45fd-a048-f3b402b2dc82.png)

A common application of Tries is seen in string-searching algorithms however they come with the drawback of taking up enormous amounts of space.






# Ternary Search Trees Though
A ternary search tree is a special trie data structure where the child nodes of a standard trie are ordered as a binary search tree. It has three children, a left subtree, a right subtree and a mid or an equal subtree.


![image](https://user-images.githubusercontent.com/97532274/204038271-85389394-9bca-49c4-9484-a95a43e5afe8.png)

The information stored in a trie for performing fast string-searching can be stored in ternary search trees, making it more efficient by reducing the storage requirements considerably.
This is what's been done at the heart of the project, using ternary-search trees to perform fast string-searching. It is easily seen how the applications of such an approach are (to some degree) endless and __NOT at all limited to searching local files__.
