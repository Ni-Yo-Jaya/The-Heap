#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void Max_Heapify(vector<int> &arr, int heap_size, int root){

    /* 
     * @brief restore the heap property when a node vioaltes it.
     * @param array refernce to the array which contains the heap
     * @param root reference to the parent index of the sub tree
     * @param heap_size refernce to the size of the heap
     * @return void modified array which satisfy the heap property
     * 
     * @complexity O(log n) - can derive by the second case of the master theorem


    */

    int left = root * 2;        // taking the index of the left node
    int right = root * 2 + 1;   // taking the index of the right node
    int max = root;             //initially consider the maximum is the root and store its index

    if(left < heap_size && arr[root] < arr[left]){ // comparing with the left node and the parent node
        max = left;                                // if the left node is bigger than the parent set max as left node index
    }

    if(right < heap_size && max < arr[root]){      // comparing with the right node and the max
        max = right;                               // if the  nodrighte is bigger than the max, set max as right node's index

    }

    if(max != root){
        swap(arr[max], arr[root]);
    }
    Max_Heapify(arr, heap_size, max);

}
//..................................................................................................................................//

void Build_Heap(vector<int> &arr){

    /*
     * @brief construct a heap from a random array
     * @param arr refernce to the random array
     * @return void modify the array as a heap
     * 
     * @complexity - O(n)
    
    */

    int heap_size = arr.size(); //taking the size of the array

    for(int i = (heap_size / 2)- 1; i >= 0; i--){  //appaly the heapify to non-leaf nodes

        Max_Heapify(arr, heap_size, i);
    }

}
//..................................................................................................................................//

void HeapSort(vector<int> &arr){

    /* 
     * @brief sort the heap
     * @param arr refer to a random array
     * @void modify the array in a sorted manner
     * 
     * complexity - O(nlog n)
    */

    Build_Heap(arr); //build a heap from a random array
    int heap_size = arr.size();  // taking the array size

    for(int i = heap_size-1; i >= 0; i--){ // iterate through the heap

        swap(arr[0],arr[heap_size-1]); // place the largest element which is the root of the heap to the last of the array
        heap_size--; // take the unsorted portion 
        Max_Heapify(arr, heap_size, 0); //heapify the unsorted array
    }


}