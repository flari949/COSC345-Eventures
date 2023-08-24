#include <QtTest>
#include "../Eventures/src/event_url.h"
//#include "../Eventures/src/process_raw.h"
//#include "../Eventures/src/data_fetch.h"

// add necessary includes here

class UnitTests : public QObject
{
    Q_OBJECT

    private slots:
        void EmptyUrlTest();
        void ValidUrlTest();
       // void processJsonValidTest();
       // void processJsonInvalidCredentialsTest();
       // void ProcessJsonInvalidURLTest();
       // void ValidDataFetchTest();

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
//           int processResult = process_json(apiUrl, username, password);
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

//    void EventUrlTests::ValidDataFetchTest(){
//        std::string apiUrl = "https://api.eventfinda.co.nz/v2/events.json?fields=event:(name,url,description~150,datetime_start,datetime_end,point,location_summary)&rows=5&";
//        std::string username = "eventure";
//        std::string password = "5jryqspxvxkk";
//     //  std::string expectedResult = "{\"@attributes\":{\"count\":104},\"events\":[{\"url\":\"https:\/ \/ www.eventfinda.co.nz\/ 2023\/ english - country - dance - 101 - evening - class\ / dunedin\",\"name\":\"English Country Dance 101 - Evening Class\",\"description\":\"Step into the world of English Country Dance with confidence and be ready for the 2023 Jane Austen Ball on Quarantine Island!\n \nOur Absolute ...\",\"datetime_start\":\"2023 - 08 - 14 18:00 : 00\",\"datetime_end\":\"2023 - 09 - 18 19:00 : 00\",\"location_summary\":\"Opoho Scout Hall, Dunedin, Otago\",\"point\":{\"lat\":-45.8579,\"lng\":170.5286}},{\"url\":\"https : \ / \ / www.eventfinda.co.nz\ / 2023\ / through - the - window - group - exhibition\ / dunedin\",\"name\":\"Through the Window - Group Exhibition\",\"description\":\"A group exhibition of multiple view points.Each artist has looked through a window ... be it looking in or out of the window and captured the view ...\",\"datetime_start\":\"2023 - 08 - 11 11:00 : 00\",\"datetime_end\":\"2023 - 08 - 23 17:30 : 00\",\"location_summary\":\"Gallery De Novo, Dunedin, Otago\",\"point\":{\"lat\":-45.8748,\"lng\":170.5056}},{\"url\":\"https : \ / \ / www.eventfinda.co.nz\ / 2023\ / david - cauchi - sensitive - bullshit - artist\ / dunedin\",\"name\":\"David Cauchi - Sensitive Bullshit Artist\",\"description\":\"An exhibition of new paintings and drawings by Whanganui based artist David Cauchi. \n \nSensitive Bullshit Artist is Cauchi's first exhibition at Brett ...\",\"datetime_start\":\"2023-08-04 17:30:00\",\"datetime_end\":\"2023-08-24 17:00:00\",\"location_summary\":\"Brett McDowell Gallery, Dunedin, Otago\",\"point\":{\"lat\":-45.877,\"lng\":170.5036}},{\"url\":\"https:\/\/www.eventfinda.co.nz\/2023\/jenny-longstaff-fresh\/dunedin\",\"name\":\"Jenny Longstaff: Fresh\",\"description\":\"The works in this selection show a fresh approach in my art practice, moving away from the previously structured arrangements with delineated areas of ...\",\"datetime_start\":\"2023-08-05 12:00:00\",\"datetime_end\":\"2023-08-25 16:00:00\",\"location_summary\":\"Moray Gallery, Dunedin, Otago\",\"point\":{\"lat\":-45.8752,\"lng\":170.5032}},{\"url\":\"https:\/\/www.eventfinda.co.nz\/2023\/israel-tangaroa-birch-kowhaiwhai-the-spirit-of-survival\/dunedin\",\"name\":\"Israel Tangaroa Birch: K\u014dwhaiwhai - The Spirit of Survival\",\"description\":\"In K\u014dwhaiwhai &ndash; The Spirit of Survival Israel Birch has explored &ldquo;the foundational language of k\u014dwhaiwhai.&rdquo; It &ldquo;acknowledges ...\",\"datetime_start\":\"2023-08-11 09:00:00\",\"datetime_end\":\"2023-09-04 17:00:00\",\"location_summary\":\"Milford Galleries Dunedin, Dunedin, Otago\",\"point\":{\"lat\":-45.8766,\"lng\":170.5032}}]}";
//     //   std::string fetchResult = fetchDataFromAPI(apiUrl, username, password);
//        QVERIFY(1 == 1);
//    }



QTEST_APPLESS_MAIN(UnitTests)

#include "UnitTests.moc"
