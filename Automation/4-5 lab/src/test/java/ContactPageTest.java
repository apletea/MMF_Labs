import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import steps.ContactPageSteps;

public class ContactPageTest  {

    private ContactPageSteps steps;

    private final Logger logger  = LogManager.getRootLogger();

    @BeforeMethod(description = "Init browser")
    public void setUp() {
        steps = new ContactPageSteps();
        steps.initBrowser();
    }

    @Test
    public void performToAirport(){
        steps.toAirport();
        steps.isOnAirportPage();
    }

    @Test(description = "duration of the loading")
    public void performLoadingPage(){
        steps.loadPage();
    }

    @Test
    public void toAgentsPage(){
        steps.toAgentsPage();
        steps.isOnToAgentsPage();
    }

    @AfterMethod(description = "Stop Browser")
    public void stopBrowser() {
        steps.closeDriver();
    }

}
