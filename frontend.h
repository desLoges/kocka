#include <string>

/***
 *
 */
typedef struct {
   std::string  drive_dest;
   std::string  depart_hours;
   std::string  depart_days;
   std::string  depart_months;
}list_details_t;


/***
 *
 */
typedef struct {
   std::string  ID_drive;
   std::string  ID_user;
   std::string  depart_hours;
   std::string  depart_days;
   std::string  depart_months;
}reservation_details_t;


///
void get_listOfDrives(list_details_t* list_details);
int set_reservations(reservation_details_t* reservation_details);
