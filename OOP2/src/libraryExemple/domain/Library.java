package libraryExemple.domain;

import java.util.ArrayList;
import java.util.Scanner;

public class Library {

    Scanner input = new Scanner(System.in);

    private User user;
    private ArrayList<User> listOfRegister = new ArrayList<>();

    public Integer amountOfBooks;
    public ArrayList<Book> listOfBooks = new ArrayList<>();


    public void register(){
        System.out.print("\n--- Iniciando cadastro ----\n");
        System.out.print("Digite seu nome: ");
        String name = input.nextLine();
        System.out.print("Digite seu email: ");
        String email = input.nextLine();
        System.out.print("Digite uma senha: ");
        String password = input.nextLine();
        System.out.print("Digite seu tipo de usuário: ");
        String userType = input.nextLine();
        if(userType.equals("professor")){
            System.out.println("\n--- Bem vindo professor(a) ---\n");
            System.out.print("Digite seu departamento: ");
            String department = input.nextLine();
            System.out.print("Digite sua área de pesquisa: ");
            String researchArea = input.nextLine();
            User professor = new Professor(email,name,
                    password,userType,department,researchArea);
            listOfRegister.add(professor);
        }
        else if(userType.equals("estudante")){
            System.out.println("\n---- Bem vindo aluno ----\n");
            System.out.print("Digite seu curso: ");
            String course = input.nextLine();
            System.out.print("Por favor, informe seu CR: ");
            double cr = input.nextDouble();
            User student = new Student(email,name,password,userType,course,cr);
            listOfRegister.add(student);
        }
        else{
            System.out.println("\n---- Bem vindo funcionário ----\n");
            System.out.println("Digite seu departamento: ");
            String department = input.nextLine();
            User employee = new Employee(email,name,password,userType,department);
            listOfRegister.add(employee);
        }

        System.out.println("\n--- Cadastro realizado ----\n");
    }


    public boolean isRegister(String name){

        for(User user: listOfRegister){
            if(user.getName().equals(name)){
                return true;
            }
        }
        return false;
    }

    public void addBook(){
        System.out.print("Digite seu nome: ");
        String name = input.nextLine();
        if(isRegister(name)) {
            System.out.println("\n ---- Adicionando um filme ----\n");
            System.out.print("Digite o título da obra: ");
            String title = input.nextLine();
            //Talvez seja interessante botar uma funcao para verificar se um livro ja existe
            System.out.print("Digite o ano de lançamento da obra: ");
            int year = input.nextInt();
            System.out.print("Digite o nome do autor da obra: ");
            String nameAuthor = input.nextLine();
            System.out.println("Digite o genero da obra: ");
            String gender = input.nextLine();

            Book book = new Book(nameAuthor, gender, title, year);
            int newQuantity = book.getQuantity() + 1;
            book.setQuantity(newQuantity);
            listOfBooks.add(book);
        }
        else{
            System.out.println("\n Voce não esta cadastrado \n");
        }
    }

    public boolean verificationBook(String name){
        for(Book book: listOfBooks){
            if(book.getTitle().equals(name)){
                System.out.println("\n Livro encontrado: \n");
                System.out.println("Titulo: " + book.getTitle());
                System.out.println("Autor: " + book.getAuthor());
                System.out.println("Ano: " + book.getYear());
                System.out.println("Genero: " + book.getGender());
                System.out.println("Quantidade disponivel: " + book.getQuantity());
                return true;
            }
        }
        return false;
    }

    public void getBook(String title){
        System.out.print(" Digite seu nome: ");
        String name = input.nextLine();
        if(isRegister(name)){
            for(Book book: listOfBooks){
                if(book.getTitle().equals(title)){
                    System.out.println("\n Livro Encontrado");
                    listOfBooks.remove(book);
                    System.out.println("\nLivro emprestado");
                    return;
                }
            }
            System.out.println("Livro não encontrado");
        }
        else{
            System.out.println("\n Voce não esta cadastrado\n");
        }
    }

    public void showListOfBooks(){

        for(Book book:listOfBooks){
            System.out.println("\n");
            System.out.println("\n Livro encontrado: \n");
            System.out.println("Titulo: " + book.getTitle());
            System.out.println("Autor: " + book.getAuthor());
            System.out.println("Ano: " + book.getYear());
            System.out.println("Genero: " + book.getGender());
            System.out.println("Quantidade disponivel: " + book.getQuantity());
        }
    }

    public void verificationRegister(String name, String password){
        for(User user:listOfRegister){
            if(user.getName().equals(name) && user.getPassword().equals(password)){
                System.out.print("\n");
                System.out.println(user.toString());
                return;
            }
        }
        System.out.println("Acesso inválido");
    }




}
