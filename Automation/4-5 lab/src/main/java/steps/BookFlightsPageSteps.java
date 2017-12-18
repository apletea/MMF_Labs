package steps;

import org.junit.Assert;

import pages.BookFlightsPage;

public class BookFlightsPageSteps extends Steps{

    public void initBrowser(){
        super.init();
    }

    public void searchDestination(String originLocation, String destinationLocation, String departureDate, String returnDate){
        BookFlightsPage bookFlightsPage = new BookFlightsPage(driver);
        bookFlightsPage.open();
        bookFlightsPage.searchDestination(originLocation, destinationLocation, departureDate, returnDate);
    }

    public void isOnDestinationPage(){
        Assert.assertTrue("title should contain Turkish Airlines - Select",
                driver.getTitle().contains("Turkish Airlines - Select"));
    }
    
    public void openOnAirPage(){
        BookFlightsPage bookFlightsPage = new BookFlightsPage(driver);
        bookFlightsPage.open();
        bookFlightsPage.openOnAirPage();
    }

    public void isOnOnAirPage(){
        Assert.assertTrue("title should contain OnAir",
                driver.getTitle().contains("OnAir - onboard Turkish Airlines"));
    }

}
