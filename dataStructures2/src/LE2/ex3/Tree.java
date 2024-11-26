package LE2.ex3;

import LE2.ex1.Node;

public class Tree {

    Node root;
    public Tree(){
        root = null;
    }

    public int height(){
        return calculusHeight(root);
    }

    public void addValue(int value){
        root = insert(root, value);
    }

    public void printTree() {
        printTree(root, 0);
    }

    private void printTree(Node node, int level) {
        if (node != null) {
            System.out.println(" ".repeat(level * 2) + (level + 1) + " (" + node.data+ ") [" + balancingFactor(node) + "]");
            printTree(node.left, level + 1);
            printTree(node.right, level + 1);
        }
    }


    private int node_height(Node node){
        return node == null ? 0:node.height;
    }

    private int balancingFactor(Node node){
        return node == null ? 0 :node_height(node.left) - node_height(node.right);
    }

    private void updateHeight(Node node){
        if(node != null){
            node.height = 1 + Math.max(node_height(node.left),node_height(node.right));
        }
    }

    private Node ll_Rotation(Node y){ // rotação simples a direita
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    private Node rr_Rotation(Node y){ //rotação simples a esquerda, por isso "right-right"
        Node x = y.right;
        Node T2 = x.left;

        x.left = y;
        y.right = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    private Node balance(Node node){
        updateHeight(node);
        int factor = balancingFactor(node);

        if(factor > 1 && balancingFactor(node.left) >= 0){ //esquerda-esquerda
            return ll_Rotation(node);
        }

        if(factor > 1 && balancingFactor(node.left) < 0){ // esquerda-direita
            node.left = rr_Rotation(node.left);
            return ll_Rotation(node);
        }

        if(factor < -1 && balancingFactor(node.right) > 0){// direita- esquerda
            node.right = ll_Rotation(node.right);
            return rr_Rotation(node);
        }

        return node;

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
        }else {
            return currentNode;
        }

        return balance(currentNode);

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
