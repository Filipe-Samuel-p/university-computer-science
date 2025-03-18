package ex2;

public class Main {

    public static void main(String[] args) {

        Person person1 = new Person("Filipe", 24);
        System.out.println("Idade do filipe: " + person1.getAge());
        person1.setAge(27);
        System.out.println("Nova idade " + person1.getAge());


    }
}
