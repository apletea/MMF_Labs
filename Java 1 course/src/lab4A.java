import java.util.ArrayList;
import java.util.List;

/**
 * Created by apletea on 23.3.17.
 */
public class lab4A {


    public static void main(String [] args){
        try {

            List<planet> planets = new ArrayList<>();
            for (int i = 0; i < 5; ++i) {
                planets.add(new planet(" " + i));
            }
            List<moon> moons = new ArrayList<>();
            for (int i = 0; i < 5; ++i) {
                moons.add(new moon(" " + i));
            }
            star sr = new star("Sun");
            starSystem ss = new starSystem(planets, sr, moons);
            System.out.println(ss);
            System.out.println("кол-во планет в системе " + ss.planets.size());
            System.out.println("название звезды " + ss.sr);
            ss.addNewStartObject(new planet("planet"));
            System.out.println(ss);
        }
        catch (Exception e){
            System.out.println("something went wrong");
        }
    }

}

class starSystem {
    star sr;
    List<planet> planets;
    List<moon> moons;
    List<starObject> starObjectList;
    starSystem(){
        this.sr = new star("Sun");
    }

    starSystem(List<planet> planets, star sr, List<moon> moons){
        this.moons = moons;
        this.planets = planets;
        this.sr  =sr;
        starObjectList = new ArrayList<>();
        starObjectList.add(sr);
    }
    public void addNewStartObject(starObject object){
        starObjectList.add(object);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        starSystem that = (starSystem) o;

        if (sr != null ? !sr.equals(that.sr) : that.sr != null) return false;
        if (planets != null ? !planets.equals(that.planets) : that.planets != null) return false;
        return moons != null ? moons.equals(that.moons) : that.moons == null;
    }

    @Override
    public int hashCode() {
        int result = sr != null ? sr.hashCode() : 0;
        result = 31 * result + (planets != null ? planets.hashCode() : 0);
        result = 31 * result + (moons != null ? moons.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return "starSystem{" +
                "sr=" + sr +
                ", planets=" + planets +
                ", moons=" + moons +
                '}';
    }
}

class  starObject{

}

class planet extends starObject{
    String name;

    public planet(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        planet planet = (planet) o;

        return name != null ? name.equals(planet.name) : planet.name == null;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }

    public planet createPlanet(){
        return new planet("planet");
    }

    @Override
    public String toString() {
        return "planet{}";
    }

}

class star extends starObject{
    String name;

    public star(String name) {
        this.name = name;
    }

    public star createStart(String name){
        return new star(name);
    }

    @Override
    public String toString() {
        return "star{" +
                "name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        star star = (star) o;

        return name != null ? name.equals(star.name) : star.name == null;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}

class moon extends starObject{
    String name;

    public moon(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public moon createMoon(){
        return new moon("moon");
    }

    @Override
    public String toString() {
        return "moon{}";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        moon moon = (moon) o;

        return name != null ? name.equals(moon.name) : moon.name == null;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}
