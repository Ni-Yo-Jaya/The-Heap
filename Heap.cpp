#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void Max_Heapify(vector<int> arr,int root){

    /* 
     * @brief restore the heap property when a node vioaltes it.
     * @param array refernce to the array which contains the heap
     * @param root reference to the parent index of the sub tree
     * @return void modified array which satisfy the heap property
     * 
     * @complexity O(log n) - can derive by the second case of the master theorem


    */

    int left = root * 2;        // taking the index of the left node
    int right = root * 2 + 1;   // taking the index of the right node
    int heap_size = arr.size(); // taking the heap size
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
    Max_Heapify(arr,max);

}