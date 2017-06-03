package by.korbut.first.point;
import org.junit.Assert;
import org.junit.Test;
public class Logic {
    public double findLenght(Point point){
        return Math.hypot(point.getX(), point.getY());
    }
    public int findQuadrant(Point point){
        if(point.getX()>0 && point.getY()>0){
            return 1;
        }
        if(point.getX()<0 && point.getY()>0){
            return 2;
        }
        if(point.getX()<0 && point.getY()<0){
            return 3;
        }
        if(point.getX()>0 && point.getY()<0){
            return 4;
        }
        return 0;
    }
}
