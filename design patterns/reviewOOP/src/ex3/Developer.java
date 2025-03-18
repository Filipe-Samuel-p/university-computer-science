package ex3;

public class Developer extends Employee{

    private double bonusByProject;
    private int quantityProjects;

    public Developer(String nome, double baseSalary, double bonusByProject, int quantityProjects) {
        super(nome, baseSalary);
        this.bonusByProject = bonusByProject;
        this.quantityProjects = quantityProjects;
    }

    @Override
    public double calcularSalario() {
        return baseSalary + (bonusByProject * quantityProjects);
    }


}

