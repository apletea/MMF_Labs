package pages;

import driver.Driver;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.apache.logging.log4j.Logger;
import org.openqa.selenium.support.FindBy;
import org.apache.logging.log4j.LogManager;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.support.ui.ExpectedConditions;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class MainPage extends Page{
    private final Logger logger   = LogManager.getRootLogger();

    private final String BASE_URL = "https://p.turkishairlines.com/en-int/";

    public MainPage(WebDriver webDriver) {
        super(webDriver);
        PageFactory.initElements(this.webDriver, this);
    }

    @FindBy(id = "select-member")
    private WebElement signInBtn;

    @FindBy(id = "MemberId")
    private WebElement inputLogin;

    @FindBy(id = "Password")
    private WebElement inputPassword;

    @FindBy(className = "btn-b2-login")
    private WebElement signInSubmitBtn;
    
    
    
    @FindBy(id="select-lang")
    WebElement changeLanguageBtn;

    @FindBy(xpath = "//a[@data-iso='EN']")
    WebElement languageToChoose;


    @Override
    public void open() {
        webDriver.navigate().to(BASE_URL);
        logger.info("Main page opened");
    }

    public void login(String username, String password) {
        signInBtn.click();
        inputLogin.sendKeys(username);
        inputPassword.sendKeys(password);
        signInSubmitBtn.submit();
        logger.info("Sign In performed");
    }

    public void changeLanguage(){
        changeLangeageBtn.click();
        logger.info("click on dropdown to change language");
        languageToChoose.click();
        Driver.getDriver().manage().timeouts().setScriptTimeout(30, TimeUnit.SECONDS);
        logger.info("choose language");
    }
}
