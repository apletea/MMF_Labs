package steps;

import org.junit.Assert;

import pages.TimetablePage;

public class TimetablePageSteps extends Steps{

    public void initBrowser(){
        super.init();
    }

    public void searchTimetable(String origin, String destination){
        TimetablePage timetablePage = new TimetablePage(driver);
        timetablePage.open();
        timetablePage.searchTimetable(origin, destination);
    }

    public void isOnTimetablePage(){
        WebElement infoFly = driver.findElement(By.className("show-info-fly"));
        if(infoFly != null)
            return true;
        return false;
    }
}