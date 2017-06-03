package test;

import norma.Solution;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by apletea on 13.2.17.
 */
public class TestSolution {

    @Test
    public void testNorma(){
        Solution solution = new Solution();
        int [][] exp ={{1,3,0},{-1,-2,7},{0,1,1},{5,0,-3}};
        assertEquals("Значения не совпадают", solution.findNorm(exp),10);
    }

}
