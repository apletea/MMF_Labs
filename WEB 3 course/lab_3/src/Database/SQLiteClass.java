package Database;

import javax.naming.NamingException;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
/**
 * Created by apletea on 14/12/16.
 */
public class SQLiteClass {
        public static Connection con;
        public static Statement stat;
        public static ResultSet rs;

        public static void Conn() throws ClassNotFoundException, SQLException, NamingException{
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb","apletea", "qwerty");
        }

    public static void addName(String name) throws ClassNotFoundException, SQLException {
        try {
            Conn();
            stat = con.createStatement();
            PreparedStatement statement = con.prepareStatement("INSERT INTO NAMES (NAME) VALUES (?)");
            statement.setString(1, name);
            statement.execute();
            statement.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        finally {
            stat.close();
            CloseDB();
        }
    }

    public static void CloseDB() throws ClassNotFoundException, SQLException {
        con.close();
    }

    public static ArrayList<String> getAllNames() throws ClassNotFoundException, SQLException, NamingException
    {
        ArrayList<String> names = new ArrayList<String>();

        Conn();
        stat = con.createStatement();
        ResultSet rs = stat.executeQuery("SELECT NAME FROM NAMES ");

        while (rs.next()) {
            names.add(rs.getString("NAME"));
        }

        rs.close();
        stat.close();
        CloseDB();

        return names;
    }

}
