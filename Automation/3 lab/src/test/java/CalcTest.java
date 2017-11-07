import org.junit.Test;
import static junit.framework.TestCase.assertEquals;
public class CalcTest {

    private Calc cals;

    @Test
    public final void add1(){
        double actual = cals.add(1,9);
        double trueAns = 10;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void add2(){
        double actual = cals.add(-1,9);
        double trueAns = 8;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void add3(){
        double actual = cals.add(1,-9);
        double trueAns = -8;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void add4(){
        double actual = cals.add(11,9);
        double trueAns = 20;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void add5(){
        double actual = cals.add(-1,-9);
        double trueAns = -10;
        assertEquals(trueAns,actual);
    }


    @Test
    public final void diff1(){
        double actual = cals.diff(1,9);
        double trueAns = -8;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void diff2(){
        double actual = cals.diff(-1,9);
        double trueAns = -10;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void diff3(){
        double actual = cals.diff(1,-9);
        double trueAns = 10;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void diff4(){
        double actual = cals.diff(11,9);
        double trueAns = 2;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void diff5(){
        double actual = cals.diff(5,5);
        double trueAns = 0;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void mult1(){
        double actual = cals.mult(5,5);
        double trueAns = 25;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void mult2(){
        double actual = cals.mult(5,10);
        double trueAns = 50;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void mult3(){
        double actual = cals.mult(-5,5);
        double trueAns = -25;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void mult4(){
        double actual = cals.mult(5,-5);
        double trueAns = -25;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void mult5(){
        double actual = cals.mult(-5,-5);
        double trueAns = 25;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void div1(){
        double actual = cals.divv(1,2);
        double trueAns = 0.5;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void div2(){
        double actual = cals.divv(2,2);
        double trueAns = 1;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void div3(){
        double actual = cals.divv(-1,2);
        double trueAns = -0.5;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void div4(){
        double actual = cals.divv(1,-2);
        double trueAns = -0.5;
        assertEquals(trueAns,actual);
    }

    @Test
    public final void div5(){
        double actual = cals.divv(-1,-2);
        double trueAns = 0.5;
        assertEquals(trueAns,actual);
    }



}
