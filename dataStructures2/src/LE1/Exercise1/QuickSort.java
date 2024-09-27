package LE1.Exercise1;

import java.util.Random;

public class QuickSort {

    public static void main(String[] args) {

        int[] array = createVector(100000);

        long startTime = System.currentTimeMillis();

        quickSort(array,0,array.length - 1);

        long endTime = System.currentTimeMillis();
        long finalTime = endTime - startTime;

        System.out.println("final time: " + finalTime);

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

    private static void quickSort(int[] array, int begin, int end) {
        if (begin < end) {
            int pivotIndex = partition(array, begin, end);
            quickSort(array, begin, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, end);
        }
    }

    private static int partition(int[] array, int begin, int end) {

        int mid = begin + (end - begin) / 2;
        int pivot = medianOfThree(array, begin, mid, end);

        if (pivot != array[end]) {
            int temp = array[pivot];
            array[pivot] = array[end];
            array[end] = temp;
        }

        pivot = array[end];
        int i = begin - 1;

        for (int j = begin; j < end; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i+1];
        array[i+1] = array[end];
        array[end] = temp;
        return i + 1;
    }

    private static int medianOfThree(int[] array, int begin, int mid, int end) {
        if (array[begin] > array[mid]) {
            int temp = array[begin];
            array[begin] = array[mid];
            array[mid] = temp;
        }
        if (array[begin] > array[end]) {
            int temp = array[begin];
            array[begin] = array[end];
            array[end] = temp;
        }
        if (array[mid] > array[end]) {
            int temp = array[mid];
            array[mid] = array[end];
            array[end] = temp;
        }
        return mid;
    }
    
    private static void showArray(int[] array){
        for(int element:array){
            System.out.print(element + "\t");
        }
    }
}
