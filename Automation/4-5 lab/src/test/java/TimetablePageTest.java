import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import java.util.Set;
import org.openqa.selenium.JavascriptExecutor;
import steps.TimetablePageSteps;
import steps.Steps;
import driver.Driver;

import java.util.concurrent.TimeUnit;

public class TimetablePageTest {
    private TimetablePageSteps steps;

    private final String ORIGIN = "Vnukowo International Airport (VKO)";
    private final String DESTINATION = "Minsk National Airport (MSQ)";

    private final Logger logger  = LogManager.getRootLogger();

    @BeforeMethod(description = "Init browser")
    public void setUp() {
        steps = new TimetablePageSteps();
        steps.initBrowser();
    }

    @Test
    public void performSearchTimetable() {
        steps.searchTimetable(ORIGIN, DESTINATION);
        String parentWindow = Driver.getDriver().getWindowHandle();
        Set <String> handles =  Driver.getDriver().getWindowHandles();
        for(String windowHandle  : handles)
        {
            if(!windowHandle.equals(parentWindow))
            {
                Driver.getDriver().switchTo().window(windowHandle);
                Driver.getDriver().manage().timeouts().pageLoadTimeout(30, TimeUnit.SECONDS);
                steps.isOnTimetablePage();
            }
        }

    }

    @Test
    public void testLoadingPage(){
        steps.openTimetablePage();
        JavascriptExecutor js = (JavascriptExecutor) Driver.getDriver();
        long loadEventEnd = (Long) js.executeScript("return window.performance.timing.loadEventEnd;");
        long navigationStart = (Long) js.executeScript("return window.performance.timing.navigationStart;");
        logger.info("Page Load Time is " + (loadEventEnd - navigationStart)/1000 + " seconds.");
    }


    @AfterMethod(description = "Stop Browser")
    public void stopBrowser() {
        steps.closeDriver();
    }
}
