package ex3;

public class Employee {

    protected String name;
    protected double baseSalary;

    public Employee(String nome, double baseSalary) {
        this.name = nome;
        this.baseSalary = baseSalary;
    }

    public double calcularSalario() {
        return 0;
    }

    public void exibirSalario() {
        System.out.println(name + " tem um salário de: R$" + calcularSalario());

    }
}
