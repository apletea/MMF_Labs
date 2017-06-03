package lab10;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Created by apletea on 3.5.17.1
 */
public class A {


    public static void main(String [] args) throws FileNotFoundException{
        List<String> list = new ArrayList<>();
        File file = new File("./Стихи");
        Scanner sc = new Scanner(file);
        while(sc.hasNextLine()){
            String tmp = sc.nextLine();
            tmp = tmp.trim();
            if (!tmp.equals(""))
            list.add(tmp);
        }
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String s, String t1) {
                return Integer.compare(s.length(), t1.length());
            }
        });
        System.out.println(list);
        for (int i = 0 ; i < list.size(); ++i){
            System.out.println(i + ":" + list.get(i));
        }

    }
}
