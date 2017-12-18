package steps;

import driver.Driver;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.openqa.selenium.WebDriver;


public class Steps {

    protected WebDriver driver;

    protected final Logger logger = LogManager.getRootLogger();

    public void init() {
        driver = Driver.getDriver();
    }

    public void closeDriver() {
        Driver.closeDriver();
    }

}