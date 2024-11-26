package LE2.ex1;

public class BinarySearchTree {

    Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    public void addValue(int value){
        root = insert(root, value);
    }

    private Node insert(Node currentNode, int number){

        if(currentNode == null){
            return new Node(number);
        }

        if(number > currentNode.data){
            currentNode.right = insert(currentNode.right,number);
        }
        else if(number < currentNode.data){
            currentNode.left = insert(currentNode.left, number);
        }

        return currentNode;

    }

    public int height(){
        return calculusHeight(root);
    }


    private int calculusHeight(Node root){
        if(root == null){
            return 0;
        }
        int right_height = calculusHeight(root.right);
        int left_height = calculusHeight(root.left);
        if(right_height > left_height){
            return right_height + 1;
        }
        else{
            return left_height + 1;
        }
    }


}
