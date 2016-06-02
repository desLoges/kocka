#ifndef BACKEND_H
#define BACKEND_H

#include <map>
#include <list>
#include <vector>
#include <string>
#include <ctime>
#include <cstdio>

/* ************************************************************************** */
/* Data structures                                                            */
/* ************************************************************************** */

enum Days {
    MONDAY = 0b01,
    TUESDAY = 0b10,
    WEDNESDAY = 0b100,
    THURSDAY = 0b1000,
    FRIDAY = 0b10000,
    SATURDAY = 0b100000,
    SUNDAY = 0b1000000
};

typedef unsigned UserID;
struct User;

typedef unsigned DriveID;
struct Drive;

struct ReservationID{
    DriveID driveid;
    std::tm date;
};

struct Reservation;
struct Database;

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */

Database * newDatabase();
void freeDatabase(Database *db);

Reservation * reserveTicket(Database *db, DriveID driveid, const std::tm * const time, UserID userid);
void printDrives(const Database *db, const char* destination, FILE *stream = stdout);
void printReservations(const Database *db, UserID id);


#endif // BACKEND_H
