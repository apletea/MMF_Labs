package test.by.korbut.first.point;

import by.korbut.first.point.Logic;
import by.korbut.first.point.Point;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;


public class TestLogic {
    @Test
    public void getLenghtTest(){
        Point p = new Point(3, 4);
        Logic logic = new Logic();
        assertEquals("Значения не совпадают", logic.findLenght(p), 5, 0);
    }
    @Test
    public void getQuarantTest(){
        Point p = new Point(3, 4);
        Logic logic = new Logic();
        assertTrue(logic.findQuadrant(p) == 1);
    }
}