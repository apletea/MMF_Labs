package forNick.lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by apletea on 31.5.17.
 */
public class A {
    /*Abiturient: id, Фамилия, Имя, Отчество, Адрес, Телефон, Оценки.
    Создать массив объектов. Вывести:
    a)	 список абитуриентов, имеющих неудовлетворительные оценки;
    b)	 список абитуриентов, у которых сумма баллов выше заданной;
    c)	 выбрать заданное число n абитуриентов, имеющих самую высокую
    сумму баллов (вывести также полный список абитуриентов, имеющих
            полупроходную сумму).*/
    static String  secondNames[] = {"Гресский","Комаровский","Жук","Войлоков","Конопляник"};
    static String fathersNames[] ={"Олегович","Юрьевич","Никитович","Дмитриевич","Владимирович"};


  public static void main(String ... args){
      Abiturent arr[] = new Abiturent[10];
      System.out.println("Список всех абитурентов");
      for (int i = 0 ; i < 10; ++i){
          List<Integer> marks = new ArrayList<>();
          marks.add((int)(Math.random()*10+1));
          marks.add((int)(Math.random()*10+1));
          marks.add((int)(Math.random()*10+1));
          marks.add((int)(Math.random()*10+1));
          marks.add((int)(Math.random()*10+1));
          arr[i] = new Abiturent(i, secondNames[i % 5], fathersNames[4 - i % 5], secondNames[i % 5] + fathersNames[4 - i % 5], String.valueOf((int)(Math.random() * 100000000 + 1000000)),marks);
          System.out.println(arr[i]);
      }
      System.out.println("a)\t список абитуриентов, имеющих неудовлетворительные оценки;");
      for (int i = 0 ; i < arr.length; ++i){
          for (int j = 0; j < arr[i].matks.size(); ++j){
              if (arr[i].matks.get(j) < 4) {
                  System.out.println(arr[i]);
                  break;
              }
          }
      }
      System.out.println("b)\t список абитуриентов, у которых сумма баллов выше заданной;");
      Scanner sc = new Scanner(System.in);
      System.out.println("Введите сумму");
      int sum = sc.nextInt();
      for (int i = 0 ; i < arr.length; ++i){
          int tmp  = 0;
          for (int j = 0; j < arr[i].matks.size(); ++j){
              tmp += arr[i].matks.get(j);
          }
          if (tmp >= sum)
              System.out.println(arr[i]);
      }
      System.out.println("c)\t выбрать заданное число n абитуриентов, имеющих самую высокую\n" +
              "сумму баллов (вывести также полный список абитуриентов, имеющих\n" +
              "полупроходную сумму).");
      System.out.println("Введите n абитурентов");
      int n = sc.nextInt();
      for(int i = 0; i < n && i < arr.length; ++i ){
          System.out.println(arr[i]);
      }
  }


  static class Abiturent{
      int id;
      String secondName;
      String fatherName;
      String adress;
      String phone;
      List<Integer> matks;

      public Abiturent(int id, String secondName, String fatherName, String adress, String phone, List<Integer> matks) {
          this.id = id;
          this.secondName = secondName;
          this.fatherName = fatherName;
          this.adress = adress;
          this.phone = phone;
          this.matks = matks;
      }

      public int getId() {
          return id;
      }

      @Override
      public String toString() {
          return "Abiturent{" +
                  "id=" + id +
                  ", secondName='" + secondName + '\'' +
                  ", fatherName='" + fatherName + '\'' +
                  ", adress='" + adress + '\'' +
                  ", phone='" + phone + '\'' +
                  ", matks=" + matks +
                  '}';
      }

      public void setId(int id) {
          this.id = id;
      }

      public String getSecondName() {
          return secondName;
      }

      public void setSecondName(String secondName) {
          this.secondName = secondName;
      }

      public String getFatherName() {
          return fatherName;
      }

      public void setFatherName(String fatherName) {
          this.fatherName = fatherName;
      }

      public String getAdress() {
          return adress;
      }

      public void setAdress(String adress) {
          this.adress = adress;
      }

      public String getPhone() {
          return phone;
      }

      public void setPhone(String phone) {
          this.phone = phone;
      }

      public List<Integer> getMatks() {
          return matks;
      }

      public void setMatks(List<Integer> matks) {
          this.matks = matks;
      }
  }
}
