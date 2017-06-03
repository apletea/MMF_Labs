package lab4b;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by apletea on 23.3.17.
 */
public class Necklace extends Stone {
    public int stonesCount;
    public int weight;
    public List<Stone> stones;

    Necklace(){
        this.stonesCount = 0;
        this.stones = new ArrayList<Stone>();
        this.weight = 0;
    }
    Necklace(List<Stone> stones){
        this.stones =stones;
        for (Stone st : stones){
            this.weight += st.weight;
            this.stonesCount +=1;
        }
    }
    public void addStone(Stone st){
        this.weight += st.weight;
        this.stonesCount +=1;
        this.stones.add(st);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;

        Necklace necklace = (Necklace) o;

        if (stonesCount != necklace.stonesCount) return false;
        if (weight != necklace.weight) return false;
        return stones != null ? stones.equals(necklace.stones) : necklace.stones == null;
    }

    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + stonesCount;
        result = 31 * result + weight;
        result = 31 * result + (stones != null ? stones.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return "Necklace{" +
                "stonesCount=" + stonesCount +
                ", weight=" + weight +
                ", stones=" + stones +
                '}';
    }
}
