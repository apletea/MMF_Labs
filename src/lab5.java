import java.util.ArrayList;
import java.util.List;

/**
 * Created by apletea on 1.4.17.
 */
public class lab5 {

    private static Catalog catalog;
    public final  void init(){
        catalog = new Catalog();
        catalog.addObjects(new User(1, "Dima"), new Book(1,"5 negretyt"));
        catalog.addObjects(new User(2, "Dima Krasavchik"), new Book(10,"white Bin black eyra"));
        catalog.addObjects(new User(3, "Dima Molodec"), new Book(11,"In the cathces on river"));
        catalog.addObjects(new User(4, "Dima Horoshiy"), new Book(12,"I am Legend"));
        catalog.addObjects(new User(5, "Sasha Zry Tak"), new Book(13,"Bitch"));
    }
    public static void main(String [] args){
        lab5 lab = new lab5();
        lab.init();
        System.out.println(catalog);

    }

    private  class User{
        int id;
        String name;

        User(int id, String name){
            this.id = id;
            this.name = name;
        }

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        @Override
        public String toString() {
            return "User{" +
                    "id=" + id +
                    ", name='" + name + '\'' +
                    '}';
        }
    }

    private  class Book{
        int id;
        String name;


        Book(int id, String name){
            this.id = id;
            this.name = name;
        }

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        @Override
        public String toString() {
            return "Book{" +
                    "id=" + id +
                    ", name='" + name + '\'' +
                    '}';
        }
    }


    public  class Catalog{
        List<Book> bookList;
        List<User> userList;

        Catalog(){
            this.bookList = new ArrayList<>();
            this.userList = new ArrayList<>();
        }

        Catalog(Book book, User user){
            bookList.add(book);
            userList.add(user);
        }

        public List<Book> getBookList() {
            return bookList;
        }

        public void setBookList(List<Book> bookList) {
            this.bookList = bookList;
        }

        public List<User> getUserList() {
            return userList;
        }

        public void setUserList(List<User> userList) {
            this.userList = userList;
        }

        public void addObjects(User user, Book book){
            bookList.add(book);
            userList.add(user);
        }

        @Override
        public String toString() {
            return "Catalog{" +
                    "bookList=" + bookList +
                    ", userList=" + userList +
                    '}';
        }
    }

}
