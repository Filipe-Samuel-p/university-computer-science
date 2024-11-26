package LE2.ex1;

public class Main {

    public static void main(String[] args) {

        BinarySearchTree searchTree = new BinarySearchTree();
        AvlTree avlTree = new AvlTree();

        int[] array = createVector(10000);

        for(int element:array){
            searchTree.addValue(element);
            avlTree.addValue(element);
        }

        int altura = searchTree.height();
        System.out.println("Altura da árvore de pesquisa binária: " + altura);

        int altura2 = avlTree.height();
        System.out.println("Altura da árvore AVL: " + altura2);
    }

    private static int[] createVector(int size){

        int[] vector = new int[size];
        for(int index = 0; index < vector.length;index++){
            vector[index] = (int) (Math.random() * 101);
        }
        return vector;
    }

}
