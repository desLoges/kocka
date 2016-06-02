#include "backend.h"

/* ************************************************************************** */
/* Data structures                                                            */
/* ************************************************************************** */

struct User {
    UserID id;

    std::string name;
    std::string email;
};

struct Destination {
    DestID id;
    std::string name;
    double distance;
};

struct Drive {

    DriveID id;

    unsigned max_capacity;

    enum Days repeat_days;

    std::vector<Departure> departures;

    DestID destination;

};

struct Reservation {

    ReservationID id;
    std::vector<UserID> users;

    bool checked;
};

struct Database {
    std::map<DriveID, Drive> drives;

    std::map<ReservationID, Reservation> reservations;

    std::map<UserID, User> users;

    std::map<DestID, Destination> destinations;

    DriveID driveidpool;
    UserID useridpool;
    DestID destidpool;

};

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */

Database *newDatabase() {
    static Database *db = nullptr;

    if(!db) {
        // DB init
        db = new Database();
        db->driveidpool = 0;
        db->destidpool = 0;
        db->useridpool = 0;
    }

    return db;
}

void freeDatabase(Database *db) {
    delete db;
}

void addDrive(Database *db, unsigned capacity, Days repeatdays, std::vector<Departure> *departures, DestID destid) {
    Drive drive;

    drive.id = db->driveidpool;
    drive.departures = *departures;
    drive.max_capacity = capacity;
    drive.repeat_days = repeatdays;
    drive.destination = destid;

    db->drives[db->driveidpool] = drive;

    db->driveidpool++;
}

const Drive *getDrive(Database *db, DriveID driveid) {
    std::map<DriveID, Drive>::iterator it = db->drives.find(driveid);
    if(it == db->drives.end()) return nullptr;

    return &(it->second);
}
