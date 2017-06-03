package forNick.lab4;

/**
 * Created by apletea on 31.5.17.
 */
public class A {

   /* Создать объект класса Государство, используя классы Область, Район,
    Город. Методы: вывести на  консоль столицу, количество областей, пло-
    щадь, областные центры*/
    public static void main(String ... args){
        Country con = new Country();
        setAll(con);
        System.out.println(con.name+con.nname+con.nnname+con.nnnname);

    }


    static void setAll(Country con){
        con.name = "Belarus";
        con.nname = " 6 областей";
        con.nnname = " площадь 240000 тыс.км";
        con.nnnname = " Областные центры :Минск, Гомель, Гродно, Витебск, Брест, Могилёв";
    }
    static class Country extends Region{
        String name;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Country country = (Country) o;

            return name != null ? name.equals(country.name) : country.name == null;
        }

        @Override
        public int hashCode() {
            return name != null ? name.hashCode() : 0;
        }

        public String getName() {

            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }

    static class Region extends  District{
        String nname;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Region region = (Region) o;

            return nname != null ? nname.equals(region.nname) : region.nname == null;
        }

        @Override
        public int hashCode() {
            return nname != null ? nname.hashCode() : 0;
        }
    }

    static class District extends City{
        String nnname;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            District district = (District) o;

            return nnname != null ? nnname.equals(district.nnname) : district.nnname == null;
        }

        @Override
        public int hashCode() {
            return nnname != null ? nnname.hashCode() : 0;
        }
    }

   static class City {
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            City city = (City) o;

            return nnnname != null ? nnnname.equals(city.nnnname) : city.nnnname == null;
        }

        @Override
        public int hashCode() {
            return nnnname != null ? nnnname.hashCode() : 0;
        }

        String nnnname;
    }
}
