package lab6;

/**
 * Created by apletea on 6.4.17.
 */
public class Flattop extends VarBoat {
    public void shoot(){
        System.out.println("Shoot from Flattop");
    }

    public void upFlyyes(){
        System.out.println("Flyues in the air");
    }

    public Flattop() {
        System.out.println("Creating flattop");
    }

    @Override
    public String toString() {
        return "Flattop{} " + super.toString();
    }
}
