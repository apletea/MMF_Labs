package lab9;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by apletea on 27.4.17.
 */
public class A {

    static String FILE_NAME = "./файл";
    static List<String> words_list = new ArrayList<String>();



    public static void main(String ... args) throws FileNotFoundException {
        initwords();
        File file = new File(FILE_NAME);
        Scanner sc = new Scanner(file);
        String INPUT_FILE = sc.nextLine();
        File input = new File(INPUT_FILE);
        sc = new Scanner(input);
        int []count = new int[words_list.size()];
        while (sc.hasNextLine()){
            String tmp = sc.nextLine();
            String strs[] = tmp.split(" ");
            for (int i = 0; i < strs.length; ++i){
                for (int j = 0; j < words_list.size(); ++j){
                    if (strs[i].equals(words_list.get(j)))
                        count[j]++;
                }
            }
        }
        for (int i = 0; i < count.length; ++i){
            System.out.println(words_list.get(i));
        }
    }

    private static void initwords(){
        words_list.add("бой");
        words_list.add("вишня");
        words_list.add("море");
        words_list.add("поводок");
        words_list.add("дух");

    }
}
