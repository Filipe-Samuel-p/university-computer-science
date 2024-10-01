package LE1.Exercise2;

import java.util.Arrays;

public class PriorityQueue {

    protected Element[] heap;
    protected int size;
    protected int auxOrder;


    public PriorityQueue(int capacity) {
        this.heap = new Element[capacity];
        this.size = 0;
        this.auxOrder = 0;
    }

    public void insert(int value) {

        auxOrder = size + 1;
        if (size == heap.length) {
            throw new IllegalStateException("Heap está cheio!");
        }
        Element newElement = new Element(auxOrder, value);
        heap[size] = newElement;
        size++;
        reheapUp(size - 1);
    }


    public void remove(){
        if(size == 0) {
            throw new IllegalArgumentException("Heap vazio");
        }

        heap[0] = heap[size - 1]; //talvez, se o array fosse um "ArrayList", poderia eliminar a antiga raiz
        size--;
        reheapDown(0);
    }

    private void reheapUp(int index) {
        if (index > 0) {

            int parentIndex = (index - 1) / 2;
            if (heap[index].comparison(heap[parentIndex].combination) > 0) {
                Element temp = heap[parentIndex];
                heap[parentIndex] = heap[index];
                heap[index] = temp;

                reheapUp(parentIndex);
            }
        }
    }

    private void reheapDown(int index) {
        int leftSon = 2 * index + 1;
        int rightSon = 2 * index + 2;
        int largest = index;

        if (leftSon < size && heap[leftSon].comparison(heap[largest].combination) > 0) {
            largest = leftSon;
        }

        if (rightSon < size && heap[rightSon].comparison(heap[largest].combination) > 0) {
            largest = rightSon;
        }

        if (largest != index) {
            Element temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            reheapDown(largest);
        }
    }


    public void showQueue(){
        for (Element element : heap) {
            System.out.print(element.combination + "\t");
        }
    }

}
