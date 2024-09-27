package LE1.Exercise1;

import LE1.Exercise2.Element;

public class HeapSort {

    public static void main(String[] args) {

        int[] array = createVector(100000);
       // int[] copy1 = copyArray(array);

        long startTime = System.currentTimeMillis();
        heapSort(array);
        long endTime = System.currentTimeMillis();
        long finalTime = endTime - startTime;

        System.out.println("\n time: " + finalTime);
    }

    private static int[] createVector(int size){

        int[] vector = new int[size];
        for(int index = 0; index < vector.length;index++){
            vector[index] = (int) (Math.random() * 101);
        }
        return vector;
    }

    private static int[] copyArray(int[] array){
        int[] copy = new int[array.length];
        for(int index = 0; index < array.length; index++){
            copy[index] = array[index];
        }
        return copy;
    }

    private static void heapSort(int[] heap){

        for(int walker = 0; walker < heap.length; walker++){
            reheapUp(heap,walker);
        }

        for(int i = heap.length - 1; i > 0; i--){
            int aux = heap[0];
            heap[0] = heap[i];
            heap[i] = aux;
            reheapDown(heap,0,i);
        }
    }

    private static void reheapUp(int[] heap, int index) {

        if (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                int temp = heap[parentIndex];
                heap[parentIndex] = heap[index];
                heap[index] = temp;
                reheapUp(heap,parentIndex);
            }
        }
    }

    private static void reheapDown(int[] heap,int index, int size) {
        int leftSon = 2 * index + 1;
        int rightSon = 2 * index + 2;
        int largest = index;

        if (leftSon < size && heap[leftSon] > heap[largest]) {
            largest = leftSon;
        }

        if (rightSon < size && heap[rightSon] > heap[largest]) {
            largest = rightSon;
        }

        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            reheapDown(heap,largest,size - 1);
        }
    }

    private static void showArray(int[] array){
        for(int element:array){
            System.out.print(element + "\t");
        }
    }

}
