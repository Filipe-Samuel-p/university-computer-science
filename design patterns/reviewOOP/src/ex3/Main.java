package ex3;

public class Main {

    public static void main(String[] args) {

        
        Employee gerente = new manager("Carlos", 5000, 2000);
        
        Employee desenvolvedor = new Developer("Ana", 4000, 500, 3);

        gerente.exibirSalario();
        desenvolvedor.exibirSalario();
    }
}
