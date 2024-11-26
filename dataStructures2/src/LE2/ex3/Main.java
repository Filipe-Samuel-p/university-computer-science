package LE2.ex3;

public class Main {

    public static void main(String[] args) {

        Tree tree = new Tree();

        int[] array = {70, 60, 80, 50, 65, 75, 85, 45, 55, 90};

        for(int element:array){
            tree.addValue(element);
        }

        tree.printTree();

    }
}
