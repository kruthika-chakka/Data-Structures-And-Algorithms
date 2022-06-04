# Question
  - Write a program to implement a delete operation from BST.
  - You will have to write the program to insert nodes in the BST also (we already did the algorithm in detail in the class for insert).
  - Insert the following nodes in the order mentioned here.
    40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46
  - Do an inorder traversal.  Take screen shot
Operations:
  - Now delete 40 (you decide predecessor or successor).
  - Do inorder traversal again. Take screen shot
  - Now delete 20
  - Do inroder traversal. Take screen shot.
Submit the code.
Submit the screen shots.

README:
1. The code had been exceuted in dev c++ IDE. But any other environments shouldn't be a problem
2. In each question, when the code is run, the binary search tree is to be created by the user. 
	- Prompts have been given for the same in the following format:
		> 1.Add to BST/ 2.quit prompt is shown when the program is run
		> Create a new node in BST and insert by giving "1" as input and pressing enter
		> User is then asked to enter the value to be stored in node. Only integers will be accepted.
		> This process will repeat till the user enters "2" as input to quit creating the BST 
3. As soon as the user quits the binary tree creation sequence, deletion sequence is activated after the inorder traversal of the tree is displayed.
4. Delete sequence works the same as insert sequence. 
	- Prompts have been given for the same in the following format:
		> 1.Delete from BST/ 2.quit prompt is shown when the program is run
		> To delete a new node in the created BST, give "1" as input and press enter
		> User is then asked to enter the key to the node that is to be deleted. Only integers will be accepted.
		> After deletion, the inorder traversal of the tree is printed
		> This process will repeat till the user enters "2" as input to quit creating the linked list 
