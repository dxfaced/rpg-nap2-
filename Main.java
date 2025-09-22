import java.util.Scanner;
class AtivEstru1{
    public static void main (String args[]){
        Scanner entrada = new Scanner(System.in);
        int [] idades = new int [10];
        
        for(int i = 0; i < idades.length; i++){
            System.out.println("Insira a idade " + (i+1) + ":");
            idades[i] = entrada.nextInt();

        }
        System.out.println("Idades maiores que 18:");
        for (int i = 0; i<idades.length; i++){
            if(idades[i]>18){
                System.out.println(idades[i]);
            }
        }
    }
}