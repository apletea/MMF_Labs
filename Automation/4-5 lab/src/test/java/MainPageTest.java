import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.openqa.selenium.JavascriptExecutor;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import steps.MainPageSteps;
import driver.Driver;

public class MainPageTest {

    private MainPageSteps steps;

    private final Logger logger  = LogManager.getRootLogger();

    private final String LOGIN               = "10011420753";
    private final String PASSWORD            = "K9H1X7";

    @BeforeMethod(description = "Init browser")
    public void setUp() {
        steps = new MainPageSteps();
        steps.initBrowser();
    }

    @Test
    public void performSignIn() {
        steps.signIn(LOGIN, PASSWORD);
        steps.isSignedIn();
    }

    @Test
    public void performChangeLanguage(){
        steps.changeLanguage();
        try {
            Thread.sleep(10000);
        } catch (Exception e) {
            System.out.println(e);
        }
        steps.isLanguageChanged();
    }

    @Test
    public void testLoadingPage(){
        steps.openMainPage();
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
