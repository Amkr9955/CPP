 // Input : Delete 20 in below tree
//        10
//      /    \         
//  20     30
//             \
//             40

// Output:    
//        10
//    /      \             
// 40        30

// 1.Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete. 
// 2.Replace the deepest rightmost node’s data with the node to be deleted. 
// 3.Then delete the deepest rightmost node.

//first approach:bfs but well have to do 2 bfs which gives runtime error
//https://www.geeksforgeeks.org/deletion-binary-tree/

// To avoid the above error and also to avoid doing BFS twice (1st iteration while searching the rightmost deepest node, and 2nd while deleting the rightmost deepest node),
// we can store the parent node while first traversal and after setting the rightmost deepest node’s data to the node needed deletion, easily delete the rightmost deepest node.
