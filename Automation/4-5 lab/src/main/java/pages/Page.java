package pages;

import org.openqa.selenium.WebDriver;

public abstract class Page {
    protected WebDriver webDriver;

    public abstract void open();

    public Page(WebDriver webDriver) {
        this.webDriver = webDriver;
    }
}
