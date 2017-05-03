package lab7;

import java.util.Scanner;

/**
 * Created by apletea on 6.4.17.
 */
public class B {
     public static void main(String ... args){
         Scanner sc = new Scanner(System.in);
         String str = sc.nextLine();
         String strs[] = str.split(" ");
         for (char i = 'а'; i <= 'я'; ++i){
             boolean isWrite = false;
             for (int j = 0; j < strs.length; ++j){
                 String tmp = strs[j];
                 tmp = tmp.trim();
                 if (tmp.charAt(0)==i) {
                     System.out.print(" " + tmp);
                     isWrite = true;
                 }
             }
             if (isWrite)
             System.out.println("");
         }
    }
}

class Строка{
 String str;

    public Строка(String str) {
        this.str = str;
    }

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    @Override
    public String toString() {
        return "Строка{" +
                "str='" + str + '\'' +
                '}';
    }
}

class Предложение{
 String str;

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    public Предложение(String str) {
        this.str = str;
    }

    @Override
    public String toString() {
        return "Предложение{" +
                "str='" + str + '\'' +
                '}';
    }
}

class Символ{
  char symbol;

    public char getSymbol() {
        return symbol;
    }

    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }

    public Символ(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public String toString() {
        return "Символ{" +
                "symbol=" + symbol +
                '}';
    }
}

class Абзац{
  String str;

    public Абзац(String str) {
        this.str = str;
    }

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    @Override
    public String toString() {
        return "Абзац{" +
                "str='" + str + '\'' +
                '}';
    }
}

class Лексема {
    String str;

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    @Override
    public String toString() {
        return "Лексема{" +
                "str='" + str + '\'' +
                '}';
    }

    public Лексема(String str) {
        this.str = str;
    }
}

class Листинг {
    String str;

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    @Override
    public String toString() {
        return "Листинг{" +
                "str='" + str + '\'' +
                '}';
    }

    public Листинг(String str) {
        this.str = str;
    }
}
