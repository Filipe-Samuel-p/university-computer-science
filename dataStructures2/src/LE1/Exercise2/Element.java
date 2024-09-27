package LE1.Exercise2;

public class Element {

    int priority;
    int order;
    int combination;

    public Element(int order, int priority) {
        this.order = order;
        this.priority = priority;
        this.combination = combinationCalculus();
    }

    private int combinationCalculus(){
        int K = 10;
        int M = 100;
        int aux1 = K - this.order;
        int aux2 = M * this.priority;
       return aux1 + aux2;
    }

    public int comparison(int otherElement) {

        if (combination > otherElement) {
            return 1;
        }
        else if (combination == otherElement){
            return 0;
        }
        return -1;
    }

    @Override
    public String toString() {
        return "Element {" +
                "order=" + order +
                ", priority=" + priority +
                '}';
    }
}
