package steps;

import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
import org.junit.Assert;
import java.util.concurrent.TimeUnit;

import pages.MainPage;

public class MainPageSteps extends Steps {

    public void initBrowser(){
        super.init();
    }

    public void signIn(String email, String password) {
        MainPage mainPage = new MainPage(driver);
        mainPage.open();
        mainPage.login(email, password);
    }

    public boolean isSignedIn() {
        WebElement memberContent = driver.findElement(By.className("member-content"));
        if(memberContent != null)
            return true;
        return false;
    }

    public void openMainPage(){
        MainPage mainPage = new MainPage(driver);
        mainPage.open();
    }

    public void changeLanguage(){
        MainPage mainPage = new MainPage(driver);
        mainPage.open();
        mainPage.changeLanguage();
    }

    public void isLanguageChanged(){
        WebElement langIso = driver.findElement(By.id("lang-iso"));
        driver.manage().timeouts().setScriptTimeout(10, TimeUnit.SECONDS);
        Assert.assertTrue("Language should be English",
                langIso.getAttribute("value").equals("EN"));
    }

}
