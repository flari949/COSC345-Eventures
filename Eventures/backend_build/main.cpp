#include <QApplication>
#include "../src/request.h"

int main()
{
    // Parameterised search values to be passed to the data retrieval function
    std::string search = "Dunedin"; // General search parameter
    std::string fields = "name,url,description~150,datetime_start,datetime_end,point,location_summary"; // Fields to retrieve
    std::string coords = "-36.84846,174.76334"; // Format: latitude,longitude --> Default : Auckland
    std::string radius = "5000"; // Distance in kilometers -> requires coordinate param be set
    std::string start_date = "2023-09-10"; // Defaults to now; format : YYYY-MM-DD
    std::string end_date = "2023-09-11"; // Defaults to 3 years from now; format : YYYY-MM-DD
    std::string num_rows = "10"; // Number of rows (items) to return
    std::string row_offset = "0"; // Row offset - for paging

    // Set event parameters
    std::vector<std::map<std::string, std::string>> _ = get_events(
        search, fields, coords, radius, start_date, end_date, num_rows, row_offset, false);
    // Get event array
    std::vector<std::map<std::string, std::string>> eventarr = get_events();
    return 0;
}
