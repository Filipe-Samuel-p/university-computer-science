package LE1;

public class Exercise1 {

    public static void main(String[] args) {

        int[] array = createVector(10);
        int[] copy1 = copyArray(array);
        int[] copy2 = copyArray(copy1);

        long startTime = System.currentTimeMillis();
        ///
        long endTime = System.currentTimeMillis();
        long finalTime = endTime - startTime;

        long startTime2 = System.currentTimeMillis();
        ////
        long endTime2 = System.currentTimeMillis();
        long finalTime2 = endTime2 - startTime2;

        long startTime3 = System.currentTimeMillis();
        ///
        long endTime3 = System.currentTimeMillis();
        long finalTime3 = endTime3 - startTime3;

        System.out.println("Bubble sort: " + finalTime);
        System.out.println("Selection sort: " + finalTime2);
        System.out.println("Insertion sort: " + finalTime3);

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


}
