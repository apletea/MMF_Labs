import java.util.Scanner;

/**
 * Created by apletea on 11.3.17.
 */
/*id, Номер квартиры, Площадь, Этаж, Количество комнат, Улица,
Тип здания, Срок эксплуатации.
Создать массив объектов. Вывести:
a)	 список квартир, имеющих заданное число комнат;
b)	 список квартир, имеющих заданное число комнат и  расположенных
на этаже, который находится в заданном промежутке;
c)	 список квартир, имеющих площадь, превосходящую заданную.*/
public class Part3A {

    static public void main(String ... args){
        House [] houses = initHouses();
        Scanner sc = new Scanner(System.in);
        int rooms = sc.nextInt();
        int floarMin = sc.nextInt();
        int floarMax = sc.nextInt();
        float square = sc.nextFloat();
        for (House ho:houses
             ) {
            System.out.println(ho);
        }
        System.out.println("Часть А");

        for (int i = 0 ; i < 5 ; i++){
            if (houses[i].getRooms() == rooms)
                System.out.println(houses[i]);
        }
        System.out.println("Часть Б");
        for (int i = 0 ; i < 5; i++){
            if (houses[i].getRooms() == rooms && houses[i].getFloar()>floarMin && houses[i].getFloar()<floarMax)
                System.out.println(houses[i]);
        }
        System.out.println("Часть С");
        for (int i = 0 ; i < 5; ++i){
            if (houses[i].getSquare() > square)
                System.out.println(houses[i]);
        }
    }

    static private House[] initHouses(){
        House[] ans = new House[5];
        ans[0] = new House(1,2,50.0,2,1,"Воронянского",1);
        ans[1] = new House(2,3,72.0,3,5,"Воронянского",2);
        ans[2] = new House(3,2,85.1,4,4,"Воронянского",3);
        ans[3] = new House(4,1,46.2,5,3,"Воронянского",2);
        ans[4] = new House(5,3,89.5,6,2,"Воронянского",2);

        return ans;
    }
}

class House{

   private int id;
    private int number;
    private double square;
    private int floar;
    private int rooms;
    private String streeet;
    private int type;
    private String expluatationEnd;

    public House() {
        id = 0;
        number = 0;
        square = 0;
        floar = 0;
        rooms = 0;
        streeet = "Неизвестная улица";
        type = 0;
        expluatationEnd = "Скоро";
    }

    House(int id, int number, double square , int floar, int rooms, String street, int type){
        this.id = id;
        this.number = number;
        this.square = square;
        this.floar = floar;
        this.rooms = rooms;
        this.streeet = street;
        this.type = type;
        this.expluatationEnd = "2050";
    }

    public void setId(int id){
        this.id = id;
    }
    public int getId(){
        return  this.id;
    }

    public int getNumber() {
        return number;
    }

    public double getSquare() {
        return square;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public void setSquare(double square) {
        this.square = square;
    }

    public void setFloar(int floar) {
        this.floar = floar;
    }

    public void setRooms(int rooms) {
        this.rooms = rooms;
    }

    public void setStreeet(String streeet) {
        this.streeet = streeet;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void setExpluatationEnd(String expluatationEnd) {
        this.expluatationEnd = expluatationEnd;
    }

    public int getFloar() {

        return floar;
    }

    public int getRooms() {
        return rooms;
    }

    public String getStreeet() {
        return streeet;
    }

    public int getType() {
        return type;
    }

    public String getExpluatationEnd() {
        return expluatationEnd;
    }

    @Override
    public String toString() {
        return "House{" +
                "id=" + id +
                ", number=" + number +
                ", square=" + square +
                ", floar=" + floar +
                ", rooms=" + rooms +
                ", streeet='" + streeet + '\'' +
                ", type=" + type +
                ", expluatationEnd='" + expluatationEnd + '\'' +
                '}';
    }



}
