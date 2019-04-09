test: 
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c test.cpp
	link test.obj BST.lib
	
app: 
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c PartB.cpp
	link PartB.obj BST.lib

clean:
	del *.obj
	del *.lib
	del *.exe