package test;

/**
 * Created by apletea on 12.2.17.
 */
public class TestSolution{}
/*@RunWith(Parameterized.class)
public class TestSolution {

    @Parameterized.Parameters
    public static Collection<Object[]> data(){
        return Arrays.asList(new Object[][]{
                { new ArrayList<Integer>(),1,2,3,4},{ new ArrayList<Integer>(),1,2,3,4,100},
                { new ArrayList<Integer>(102),1,2,102},{ new ArrayList<Integer>(102),102,101,100},
                { new ArrayList<Integer>(),101,202,303},{ new ArrayList<Integer>(),1000,1234}
        });
    }

    private  int fInput;
    private  ArrayList<Integer>  fExpected;

    public TestSolution(ArrayList<Integer> expected, int ... input){
        fInput = input;
        fExpected = expected;
    }

    @Test
    public void isSatisfiedTest(){
        Solution solution = new Solution();
        List<Integer> ans = new ArrayList<>();

        assertEquals("Значения не совпадают", solution.isSateisfied(fInput), fExpected );

    }
}*/
