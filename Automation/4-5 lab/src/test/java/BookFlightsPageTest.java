import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import java.util.Set;
import org.openqa.selenium.JavascriptExecutor;
import steps.BookFlightsPageSteps;
import steps.Steps;
import driver.Driver;

import java.util.concurrent.TimeUnit;

public class BookFlightsPageTest {
    private BookFlightsPageSteps steps;

    private final String ORIGINLOCATION = "Minsk National Airport (MSQ), Misnk";
    private final String DESTINATIONLOCATION = "Dubai International Airport (DXB), Dubai";
    private final String DEPARTUREDATE = "16.12.2017";
    private final String RETURNDATE = "23.12.2017";

    private final Logger logger  = LogManager.getRootLogger();

    @BeforeMethod(description = "Init browser")
    public void setUp() {
        steps = new BookFlightsPageSteps();
        steps.initBrowser();
    }

    @Test
    public void performSearchDestination() {
        steps.searchHotel(ORIGINLOCATION, DESTINATIONLOCATION, DEPARTUREDATE, RETURNDATE);
        String parentWindow = Driver.getDriver().getWindowHandle();
        Set <String> handles =  Driver.getDriver().getWindowHandles();
        for(String windowHandle  : handles)
        {
            if(!windowHandle.equals(parentWindow))
            {
                Driver.getDriver().switchTo().window(windowHandle);
                Driver.getDriver().manage().timeouts().pageLoadTimeout(30, TimeUnit.SECONDS);
                steps.isOnDestinationPage();
            }
        }

    }
    
    @Test
    public void performOpenOnAirPage(){
        steps.openOnAirPage();
        steps.isOnOnAirPage();
    }


    @AfterMethod(description = "Stop Browser")
    public void stopBrowser() {
        steps.closeDriver();
    }
}
