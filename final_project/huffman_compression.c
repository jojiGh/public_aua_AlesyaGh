#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation

/* defining a nested node structure
each node has to have a character (data) and a frequency, which represents it
besides that, it can also have left and right nodes
in case it doesn't, it is considered a leaf */
struct Node {
  char symb;
  unsigned freq; // declaring an unsigned integer for it to have only positive values
  struct Node *left, *right;
};

/* defining a nested heap of nodes structure
as heap can be described as an array, we can assign it its maximum and current sizes*/
struct Heap {
  unsigned cur_size;
  unsigned max_size;
  struct Node **array; // creating an array of node pointers
};

// creating nodes
struct Node *new_node(char symb, unsigned freq) {
  struct Node *holder;
  holder = (struct Node*)malloc(sizeof(struct Node)); // allocating memory for Node structure
  // accessing members of the structure and assigning them values using pointer
  holder->left = NULL;
  holder->right = NULL;
  holder->symb = symb;
  holder->freq = freq;

  return holder;
}

// creating a heap
struct Heap *create_heap(unsigned max_size) {
  struct Heap *Heap = (struct Heap*)malloc(sizeof(struct Heap));

  Heap->cur_size = 0; // setting the initial value to 0

  Heap->max_size = max_size; // allowing the max_size value to be assigned from the parameter

  Heap->array = (struct Node**)malloc(Heap->max_size * sizeof(struct Node*)); // allocating memory for the array with the size of max_size times Node's size
  
  return Heap;
}

// declaring a void function to swap nodes if they are not placed in ascending order
void swap_node(struct Node **a, struct Node **b) {
  struct Node *temp = *a;
  *a = *b;
  *b = temp;
}

// function to create a heap data structure
void heapify(struct Heap *Heap, int idx) {
  int least = idx;
  int left = 2 * idx + 1; // index of left child
  int right = 2 * idx + 2; // index of right child

  // if left child's index is less than the current size of the array and its frequency is less than the frequency of the least element in it
  // then the least index is assigned with the left node's index
  if (left < Heap->cur_size && Heap->array[left]->freq < Heap->array[least]->freq) {
    least = left;
  }

  // if right child's index is less than the current size of the array and its frequency is less than the frequency of the least element in it
  // then the least index is assigned with the right node's index
  if (right < Heap->cur_size && Heap->array[right]->freq < Heap->array[least]->freq) {
    least = right;
  }

// if the least index does not equal to the specified parameter, then the swap_node function is called
// and the least element is swapped witht the current element
// and the heap structure is created
  if (least != idx) {
    swap_node(&Heap->array[least], &Heap->array[idx]);
    heapify(Heap, least);
  }
}

// function for extracting node with the least value from heap
struct Node *extract_least(struct Heap *Heap) {
  struct Node *holder = Heap->array[0]; // pointing to the first element in the array
  Heap->array[0] = Heap->array[Heap->cur_size - 1]; // assigning array's last element (node) to the first element

  --Heap->cur_size; // prefix decrement operator applied to the current size of the array => the least element is extracted
  heapify(Heap, 0); // creating heap data structure again

  return holder; // returning the parent node
}

// function to add new node to heap
void insert_node(struct Heap *Heap, struct Node *heap_node) {
  ++Heap->cur_size; // incrementing current size of the array
  int i = Heap->cur_size - 1; // assigning the last index to the integer i

  // the loop works shile int i is true and the frequency of the node (that has to be inserted in heap) is less than that of array's certain element
  while (i && heap_node->freq < Heap->array[(i - 1) / 2]->freq) {
    // the element from array with satisfying condition is assigned with the value of the child
    Heap->array[i] = Heap->array[(i - 1) / 2];
    i = (i - 1) / 2; // for the next iteration
  }
  Heap->array[i] = heap_node;
}

// building heap
void build_heap(struct Heap *Heap) {
  int n = Heap->cur_size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    heapify(Heap, i);
}

// checking if the node is a leaf
int is_leaf(struct Node *root) {
  return !(root->left) && !(root->right);
}

// creating a heap with max_size equal to cur_size
// and inserts all character of symb[] in it
// at the beginning cur_size of heap is equal to max_size
struct Heap *create_n_build_heap(char symb[], int freq[], int cur_size) {
  struct Heap *Heap = create_heap(cur_size);

  for (int i = 0; i < cur_size; ++i) {
    Heap->array[i] = new_node(symb[i], freq[i]);
  }

  Heap->cur_size = cur_size;
  build_heap(Heap);

/*
  for (int q = 0; q < cur_size; q++) {
    prinTf("%c", Heap->array[q]);
  }
*/

  return Heap;
}

// checking if size of heap is 1
int check_if_one(struct Heap *Heap) {
  return (Heap->cur_size == 1);
}

// building the Huffman tree
struct Node *build_tree(char symb[], int freq[], int cur_size) {
  struct Node *left, *right, *top; // creating left, right, and top nodes
  struct Heap *Heap = create_n_build_heap(symb, freq, cur_size); // creating and building a heap

  // the loop iterates until the size of heap becomes 1
  while (!check_if_one(Heap)) {
    // assigning the extracted least frequency values to left and right nodes of heap
    left = extract_least(Heap);
    right = extract_least(Heap);

    // creating a new parent node with frequency = sum of the two child nodes' frequencies
    // adding the node to heap
    // '$' is an identifier, a special character used for nodes
    top = new_node('$', left->freq + right->freq);

    // assigning left and right nodes to the left and right sides of the parent node
    top->left = left;
    top->right = right;

    insert_node(Heap, top);
  }

// we are left with the root node => the tree is complete
  return extract_least(Heap);
}

// printing the main array
void print_arr(int arr[], int n) {
  int i;

  for (i = 0; i < n; ++i) {
    printf("%d", arr[i]);
  }

  printf("\n");
}

// assigning 0 and 1 to the left and right child nodes, correspondingly
// and printing the code from the root of the tree
void print_code(struct Node *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    print_code(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    print_code(root->right, arr, top + 1);
  }

  if (is_leaf(root)) {
    printf("%c - ", root->symb);
    print_arr(arr, top);
  }
}

// used for printing the tree
void huffman_code(char symb[], int freq[], int cur_size) {
  struct Node *root = build_tree(symb, freq, cur_size);

  // taking array length as 100 because its exact lenght is unknown
  int array[100], top = 0;

  print_code(root, array, top);
}

// the main function, which prints out everything for the user
int main() {
  char array[] = {'D', 'e', 's', 'I', 'i', '\'', 'O', 't', 'm'};
  int freq[] = {7, 14, 2, 9, 23, 6, 30, 12, 4};

  int cur_size = sizeof(array) / sizeof(array[0]);

  huffman_code(array, freq, cur_size);
}