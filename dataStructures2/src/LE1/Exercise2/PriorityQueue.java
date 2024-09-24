package LE1.Exercise2;

public class PriorityQueue {

    protected Element[] heap;
    protected int size;
    protected int auxOrder;

    public PriorityQueue(int capacity) {
        this.heap = new Element[capacity];
        this.size = 0;
        this.auxOrder = 100; // um valor alto só para funcionar como uma "senha"
    }
}
