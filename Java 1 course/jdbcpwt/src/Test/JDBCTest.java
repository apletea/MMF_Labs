package Test;

/*Напишите программу, которая возвращает наибольшее
    число палиндром, которое является произведением двух простых пятизначных чисел, а также возвращает сами сомножители.*/
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class JDBCTest  {

    @Test
    public void testTask(){
        task.JDBC test = new task.JDBC();
        int ans = 999949999;
        assertEquals("Значения не совпадают", test.main(10000,99999), ans);
    }

}
