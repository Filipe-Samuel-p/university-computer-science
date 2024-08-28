package libraryExemple.main;

import libraryExemple.domain.Library;

import java.util.Scanner;

public class MainLibrary {


    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        Library library = new Library();
        int option;
        do{

            System.out.println("\n----- Biblioteca -----\n");
            System.out.println("[1]- Cadastratar usuario");
            System.out.println("[2]- Verificar cadastro de um usuário");
            System.out.println("[3]- verificar se um livro esta disponível");
            System.out.println("[4]- adicionar um livro na bibliotecar");
            System.out.println("[5]- Pegar emprestado um livro");
            System.out.println("[6]- Mostrar todos os livros disponíveis");
            System.out.println("[7]- Sair");
            System.out.print("Digite a opcao escolhida: ");
            option = input.nextInt();
            input.nextLine();

            switch (option){

                case 1:
                    library.register();
                    break;
                case 2:
                    System.out.print("Digite seu nome: ");
                    String name = input.nextLine();
                    if(library.isRegister(name)){
                        System.out.print("Digite sua senha: ");
                        String password = input.nextLine();
                        library.verificationRegister(name,password);
                    }
                    else{
                        System.out.println("Não esta cadastrado");
                    }
                    break;

                case 3:
                    System.out.print("Digite o Título do livro: ");
                    String title = input.nextLine();
                    if(library.verificationBook(title)){
                        System.out.println("Livro esta disponível");
                    }
                    else{
                        System.out.println("Livro não esta disponível");
                    }
                    break;

                case 4:
                    library.addBook();
                    break;

                case 5:
                    System.out.print("Digite o titulo do livro que deseja pegar: ");
                    String title2 = input.nextLine();
                    library.getBook(title2);
                    break;

                case 6:
                    library.showListOfBooks();
                    break;

                case 7:
                    break;

                default:
                    System.out.println("Digite uma opcao válida");
                    break;
            }

        }while(option != 7);

        input.close();
    }
}
