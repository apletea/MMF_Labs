package pages;

import driver.Driver;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;


public class TimetablePage extends Page {

    private final String BASE_URL = "https://p.turkishairlines.com/en-int/flights/fly-different/";

    private final Logger logger   = LogManager.getRootLogger();

    public TimetablePage(WebDriver webDriver) {
        super(webDriver);
        PageFactory.initElements(this.webDriver, this);
    }

    @FindBy(id = "origin_Combobox")
    private WebElement inputOrigin;

    @FindBy(id = "destination_Combobox")
    private WebElement inputDestination;

    @FindBy(id = "getTimeTable")
    private WebElement getTimeTableBtn;

    @Override
    public void open() {
        webDriver.navigate().to(BASE_URL);
        logger.info("Time Table page opened");
    }

    public void searchTimetable(String origin, String destination){
        inputOrigin.sendKeys(origin);
        inputDestination.sendKeys(destination);
        searchBtn.click();
        logger.info("search time table performed");
    }

}
