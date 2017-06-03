package lab4b;

/**
 * Created by apletea on 23.3.17.
 */
public class Stone {
    public int weight;
    public int transparency;

    public Stone (){
        this.weight = 0;
        this.transparency = 0;
    }

    public Stone(int weight, int transparency) {
        this.weight = weight;
        this.transparency = transparency;
    }

    @Override
    public String toString() {
        return "Stone{" +
                "weight=" + weight +
                ", transparency=" + transparency +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Stone stone = (Stone) o;

        if (weight != stone.weight) return false;
        return transparency == stone.transparency;
    }

    @Override
    public int hashCode() {
        int result = weight;
        result = 31 * result + transparency + 'a';
        return result;
    }

    public int getWeight() {

        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getTransparency() {
        return transparency;
    }

    public void setTransparency(int transparency) {
        this.transparency = transparency;
    }
}
