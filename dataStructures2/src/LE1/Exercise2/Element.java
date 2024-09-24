package LE1.Exercise2;

public class Element {

    int priority;
    int order;

    public Element(int order, int priority) {
        this.order = order;
        this.priority = priority;
    }

    public int comparison(Element otherElement){
        if(this.priority != otherElement.priority){
            return Integer.compare(this.priority,otherElement.priority);
        }
        else{
            return Integer.compare(this.order, otherElement.order);
        }
    }
}
