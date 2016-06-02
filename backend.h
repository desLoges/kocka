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

typedef unsigned DestID;
struct Destination;

typedef unsigned DriveID;
struct Drive;

struct ReservationID {
    DriveID driveid;
    std::tm date;
};

struct Departure {
    unsigned hours;
    unsigned minutes;
};

struct Reservation;
struct Database;

/* ************************************************************************** */
/* Database functions                                                         */
/* ************************************************************************** */

Database * newDatabase();
void freeDatabase(Database *db);

void addDrive(Database *db,
              unsigned capacity,
              enum Days repeatdays,
              std::vector<Departure> *departures,
              DestID destid);

void addDestination(Database *db, const char *name, double distance);

void addUser(Database *db, const char* name, const char* email);

Reservation * reserveTicket(Database *db,
                            DriveID driveid,
                            const std::tm * const time,
                            UserID userid);

const Drive *getDrive(Database *db, DriveID driveid);

void printDrives(const Database *db, const char* destination, Departure departure,
                 FILE *stream = stdout);

void printReservations(const Database *db, UserID id);


#endif // BACKEND_H
