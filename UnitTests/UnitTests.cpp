#include <QtTest>
#include "../Eventures/src/event_url.h"
#include "../Eventures/src/process_raw.h"
#include "../Eventures/src/data_fetch.h"

// add necessary includes here

class UnitTests : public QObject
{
    Q_OBJECT

    private slots:
        void EmptyUrlTest();
        void ValidUrlTest();
//        void processJsonValidTest();
//        void processJsonInvalidCredentialsTest();
//        void ProcessJsonInvalidURLTest();
        void ValidEmptyDataFetchTest();

    };


    void UnitTests::EmptyUrlTest()
    {
        std::string expectedResult = "https://api.eventfinda.co.nz/v2/events.json?";
        std::string urlResult = event_url("", "", "", "", "", "", "");
        QVERIFY(expectedResult == urlResult);
    }


    void UnitTests::ValidUrlTest(){
        std::string search = "music";					// General search parameter
        std::string fields = "name,url,description~150,datetime_start,datetime_end,point,location_summary"; // Fields to retrieve
        std::string coords = "-45.87416,170.50361"; // Format: latitude,longitude
        std::string radius = "5";					// Distance in kilometers
        std::string start_date = "2023-01-07";		// Defaults to now; format: YYYY-MM-DD
        std::string num_rows = "5";					// Number of rows (items) to return
        std::string row_offset = "1";				// Row offset - for paging
        std::string expectedResult = "https://api.eventfinda.co.nz/v2/events.json?autocomplete=music&fields=event:(name,url,description~150,datetime_start,datetime_end,point,location_summary)&point=-45.87416,170.50361&radius=5&start_date=2023-01-07&rows=5&offset=1";
        std::string urlResult =  event_url(search, fields, coords, radius, start_date, num_rows, row_offset);
        QVERIFY(expectedResult == urlResult);
    }

//    void UnitTests::processJsonValidTest()
//    {
//        std::string apiUrl = "https://api.eventfinda.co.nz/v2/events.json?fields=event:(name,url,description~150,datetime_start,datetime_end,point,location_summary)&rows=5&";
//        std::string username = "eventure";
//        std::string password = "5jryqspxvxkk";
//        int expectedResult = 0;
//        int processResult = process_json(apiUrl, username, password);
//        QVERIFY(expectedResult == processResult);
//    }


//    void UnitTests::processJsonInvalidCredentialsTest()
//    {
//        std::string apiUrl = "https://api.eventfinda.co.nz/v2/events.json?fields=event:(name,url,description~150,datetime_start,datetime_end,point,location_summary)&rows=5&";
//        std::string username = "evnture";
//        std::string password = "5jryqsxvxkk";
//        int expectedResult = 1;
//        int processResult = process_json(apiUrl, username, password);
//        QVERIFY(expectedResult == processResult);
//    }

//    void UnitTests::ProcessJsonInvalidURLTest(){
//        std::string apiUrl = "https://api.eventfinda.co.nz/v2/evnts.json?fields=event:(name,url,description~150,datetime_start,datetime_end,point,location_summary)&rows=5&";
//        std::string username = "eventure";
//        std::string password = "5jryqspxvxkk";
//        int expectedResult = 1;
//        int processResult = process_json(apiUrl, username, password);
//        QVERIFY(expectedResult == processResult);
//    }

    void UnitTests::ValidEmptyDataFetchTest(){
        std::string apiUrl = "https://api.eventfinda.co.nz/v2/events.json?fields=event:(name,url,datetime_end,point,location_summary)&rows=2&end_date=2022-08-27";
        std::string username = "eventure";
        std::string password = "5jryqspxvxkk";
        std::string expectedResult = "{\"@attributes\":{\"count\":0},\"events\":[]}";
        std::string fetchResult = fetchDataFromAPI(apiUrl, username, password);
        QVERIFY(expectedResult == fetchResult);
    }



QTEST_APPLESS_MAIN(UnitTests)

#include "UnitTests.moc"
