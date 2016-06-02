#include <iostream>
#include <string>
#include "frontend.h"
#include "backend.h"



int main(const int argc, const char *argv[]) {

	list_details_t list_details;
	reservation_details_t reservation_details;

	Database db;

	get_listOfDrives(&list_details);

	set_reservations(&reservation_details);

	return 0;
}
