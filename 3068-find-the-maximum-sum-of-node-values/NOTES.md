* Considering last point, you can choose not just any conected nodes to perform XOR but any two from the tree because in the tree you always have a path from one node to another (this is why array edges is useless). Of course I need to explain this. Imagine you have 3 nodes 0, 1, 2 and edges (0, 1) and (0, 2) (the same tree as in the description section) and look on picture.
​
![](https://assets.leetcode.com/users/images/b308c0c2-5e52-46d0-afa9-0548373e93d7_1716096338.847658.png)
​
* So, we are managed to XOR two nodes which haven't edge beetwen them, in such way I can XOR some node after the second node and so on. Considering that in the tree all nodes have some path between them we can XOR any pair of nodes we want. Now, let's move on to the approaches which based on this observations.