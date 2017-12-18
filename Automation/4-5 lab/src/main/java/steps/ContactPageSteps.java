package steps;

import org.junit.Assert;
import pages.ContactPage;

public class ContactPageSteps extends Steps {

    public void initBrowser(){ 
        super.init(); 
    }

    public void toAirport(){
        ContactPage contactPage = new ContactPage(driver);
        contactPage.open();
        contactPage.toAirport();
    }

    public void isOnAirportPage(){
        Assert.assertTrue("title should be equal Schiphol | Travel your way at Amsterdam Airport Schiphol",
                driver.getTitle().equals("Schiphol | Travel your way at Amsterdam Airport Schiphol"));
    }

    public void loadPage(){
        ContactPage contactPage = new ContactPage(driver);
        contactPage.loadPage();
    }

    public void toAgentsPage(){
        ContactPage contactPage = new ContactPage(driver);
        contactPage.open();
        contactPage.toAgents();
    }

    public void isOnToAgentsPage(){
        Assert.assertTrue("title should be equal Agency - Turkish Airlines",
                driver.getTitle().equals("Agency - Turkish Airlines"));
    }

}
