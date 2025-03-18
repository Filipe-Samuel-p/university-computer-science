package ex3;

public class manager extends Employee{

    private double bonus;

    public manager(String nome, double baseSalary, double bonus) {
        super(nome, baseSalary);
        this.bonus = bonus;

    }

    @Override
    public double calcularSalario() {
        return baseSalary + bonus;
    }


}
