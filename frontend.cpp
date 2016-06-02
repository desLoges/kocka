#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "frontend.h"

using namespace std;

void get_listOfDrives(list_details_t* list_details) {

	printf(
			"\n################################################################################");
	printf("\nAvailable destinations: <PRAHA, ZLIN, OLOMOUC>"); //TODO: change constant destination for real cities from db
	printf("\nYour Destination: ");
	getline(cin, list_details->drive_dest);
	list_details->drive_dest.erase(
			std::remove(list_details->drive_dest.begin(),
					list_details->drive_dest.end(), '\n'),
			list_details->drive_dest.end());
	printf("Departure time (hours -> hh): ");
	getline(cin, list_details->depart_hours);
	list_details->depart_hours.erase(
			std::remove(list_details->depart_hours.begin(),
					list_details->depart_hours.end(), '\n'),
			list_details->depart_hours.end());
//	printf("Departure Month: ");
//	getline(cin, list_details->depart_months);
//	list_details->depart_months.erase(
//			std::remove(list_details->depart_months.begin(),
//					list_details->depart_months.end(), '\n'),
//			list_details->depart_months.end());
//	printf("Departure Day: ");
//	getline(cin, list_details->depart_days);
//	list_details->depart_days.erase(
//			std::remove(list_details->depart_days.begin(),
//					list_details->depart_days.end(), '\n'),
//			list_details->depart_days.end());
	printf(
			"\nYour search details for: \n - City: %s\n - hour: %s:00",
			list_details->drive_dest.c_str(),
			//list_details->depart_months.c_str(),
			//list_details->depart_days.c_str(),
			list_details->depart_hours.c_str());
	printf("\nDrives:");
	//TODO: call list function
	printf(
			"\n################################################################################");
}

int set_reservations(reservation_details_t* reservation_details) {
	int ret = 0;

	printf(
			"\n################################################################################");

	printf("\n RESERVATION");

	printf("\nYour drive ID: ");
	getline(cin, reservation_details->ID_drive);
	reservation_details->ID_drive.erase(
			std::remove(reservation_details->ID_drive.begin(),
					reservation_details->ID_drive.end(), '\n'),
			reservation_details->ID_drive.end());

	printf("\nYour user ID: ");
	getline(cin, reservation_details->ID_user);
	reservation_details->ID_user.erase(
			std::remove(reservation_details->ID_user.begin(),
					reservation_details->ID_user.end(), '\n'),
			reservation_details->ID_user.end());

	//	printf("Departure time (hours): ");
//	getline(cin, list_details->depart_hours);
//	list_details->depart_hours.erase(std::remove(list_details->depart_hours.begin(), list_details->depart_hours.end(), '\n'), list_details->depart_hours.end());
	printf("Departure Month: ");
	getline(cin, reservation_details->depart_months);
	reservation_details->depart_months.erase(
			std::remove(reservation_details->depart_months.begin(),
					reservation_details->depart_months.end(), '\n'),
			reservation_details->depart_months.end());
	printf("Departure Day: ");
	getline(cin, reservation_details->depart_days);
	reservation_details->depart_days.erase(
			std::remove(reservation_details->depart_days.begin(),
					reservation_details->depart_days.end(), '\n'),
			reservation_details->depart_days.end());
	printf(
			"\nYour reservation details for drive ID %s\n - date: %s.%s",
			reservation_details->ID_drive.c_str(),
			reservation_details->depart_months.c_str(),
			reservation_details->depart_days.c_str()
			);

	//TODO: call reservation function
	printf(
			"\n################################################################################");

	return ret;
}
