package LE2.ex1;

public class Node {

    public int data;
    public int height; // inseri aqui pois não irá afetar nada. Melhor que criar outra func.
    public Node left;
    public Node right;

    public Node() {}
    public Node(int data) {
        this.data = data;
        this.height = 1;
    }
}
