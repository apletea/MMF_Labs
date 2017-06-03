package lab9;

/**
 * Created by apletea on 11.5.17.
 */
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class С {
///V5 !!!!
    public static void main(String ... args) throws IOException {
        File input = new File("./ученики");
        FileOutputStream ouput = new FileOutputStream("./7+");
        Scanner sc = new Scanner(input);
        int length = 0;
        while (sc.hasNextLine()){
            String str = sc.nextLine();
            String strs[] = str.split(" ");
            System.out.println(strs[1] + strs[2] + strs[3]);
            int avg = Integer.parseInt(strs[1])+Integer.parseInt(strs[2]) +Integer.parseInt(strs[3]);
            avg /= 3;
            if (avg >= 7) {
                ouput.write((strs[0] + "\n").getBytes(), 0, strs[0].getBytes().length);
                ouput.write('\n');
            }
        }
    }
}
