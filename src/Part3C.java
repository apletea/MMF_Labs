/**
 * Created by apletea on 11.3.17.
 */
public class Part3C {
    public static void main(String [] args){
        Circle circles[] = initCircles();
        for (int i = 0 ; i < circles.length; ++i){
            System.out.println(circles[i]);
        }
        System.out.println("Группа окружностей леащих на одной прямой");
        for(int i = 0; i < 3; ++i){
            System.out.println(circles[i]);
        }
        System.out.println("Наибольший периметр и площадь у круга " + 3 + " " + circles[2]);
        System.out.println("Наименьший периметр и площадь у круга" + 1 + " " +circles[0]);
    }

    private static Circle [] initCircles(){
        Circle res[] = new Circle[5];
        res[0] = new Circle(1.00,1.00,1.00);
        res[1] = new Circle(2.00,2.00,2.00);
        res[2] = new Circle(3.00,3.00,3.00);
        res[3] = new Circle(-4.00,-4.00,1.00);
        res[4] = new Circle(-3.00,-3.00,2.00);
        return res;
    }
}


class Circle {
     private double x;
     private double y;
     private double radius;


     public double perimeter(){
         return radius*2*Math.PI;
     }

     public double square(){
         return radius*radius*Math.PI;
     }

     public Circle(){
         this.x = 0;
         this.y = 0;
         this.radius = 1;
     }

     public Circle(double x, double y, double radius){
         this.x=x;
         this.y= y;
         this.radius = radius;
     }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        return "Circle{" +
                "x=" + x +
                ", y=" + y +
                ", radius=" + radius +
                '}';
    }
}
