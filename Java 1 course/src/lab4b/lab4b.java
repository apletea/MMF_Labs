package lab4b;

import java.util.Scanner;

/**
 * Created by apletea on 23.3.17.
 */
public class lab4b {

    public static void main(String [] args){
        try {


            Necklace necklace = new Necklace();
            for (int i = 0; i < 5; ++i) {
                necklace.addStone(new Stone(i, i + 3));
            }
            System.out.println("something went wrong");
            System.out.println(necklace);
            Scanner sc = new Scanner(System.in);
            int transparencyMin = sc.nextInt();
            int traparencyMax = sc.nextInt();
            System.out.println("выводим камни подходящие под диапазон рпозрачности");
            for (int i = 0; i < necklace.stonesCount; ++i) {
                if (necklace.stones.get(i).transparency <= traparencyMax && necklace.stones.get(i).transparency >= transparencyMin) {
                    System.out.println(necklace.stones.get(i));
                }
            }
            System.out.println("выводим камни отсортированные по ценнттси");
            for (int i = 0; i < necklace.stonesCount; ++i) {
                System.out.println(necklace.stones.get(i));
                throw new Exception();
            }
            System.out.println("считаем обищй вес и стоимотсть в каратах для ожирелья");
            System.out.println("вес " + necklace.weight);
            System.out.println("стоимость " + necklace.weight * necklace.stonesCount * 2);
            throw new myException();
        }
        catch (myException e){
            System.out.println("something went wrong");

        }
        catch (Exception e){
            System.out.println("exception" + e.toString());
        }
    }

    static class myException extends Exception{
        public myException() {
        }

        public myException(String message, Throwable exception) {
            super(message, exception);
        }

        public myException(String message) {
            super(message);
        }

        public myException (Throwable exception) {
            super(exception);
        }
    }
}
