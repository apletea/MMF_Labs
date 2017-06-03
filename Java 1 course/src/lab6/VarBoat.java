package lab6;

/**
 * Created by apletea on 6.4.17.
 */
public abstract class VarBoat implements Boat {

    abstract public void shoot();

    public void move(){
        System.out.println("Moving");

    }

    public void stop(){
        System.out.println("Stoped");
    }

    public VarBoat() {
        System.out.println("Creating Bar Boat");
    }

    @Override
    public String toString() {
        return "VarBoat{}";
    }
}
