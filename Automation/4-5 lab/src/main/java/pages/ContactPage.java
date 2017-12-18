package pages;

import driver.Driver;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class ContactPage extends Page {

    private final String BASE_URL = "https://p.turkishairlines.com/en-int/any-questions/";

    private final Logger logger   = LogManager.getRootLogger();

    public ContactPage(WebDriver webDriver) {
        super(webDriver);
        PageFactory.initElements(this.webDriver, this);
    }

    @Override
    public void open() {
        webDriver.navigate().to(BASE_URL);
        logger.info("Contact page opened");
    }

    @FindBy(linkText = "Help")
    WebElement airportBtn;
    
    @FindBy(linkText = "Social Help")
    WebElement agentsBtn;

    public void toAirport(){
        airportBtn.click();
    }

    public void toAgents(){ 
        agentsBtn.click(); 
    }

}
