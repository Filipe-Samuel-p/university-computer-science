package LE2.ex2;

import LE2.ex1.BinarySearchTree;

public class Main {

    public static void main(String[] args) {

        AvlTree avlTree = new AvlTree();

        int[] array = createVector(10);

        for(int element:array){
            avlTree.addValue(element);
        }

        System.out.println("Percuso Pré-ordem: ");
        avlTree.preOrder();

        System.out.println("Percuso Em-ordem: ");
        avlTree.inOrder();

        System.out.println("Percuso Pós-ordem: ");
        avlTree.postOrder();
    }

    private static int[] createVector(int size){

        int[] vector = new int[size];
        for(int index = 0; index < vector.length;index++){
            vector[index] = (int) (Math.random() * 101);
        }
        return vector;
    }
}
