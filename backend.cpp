#include "backend.h"

/* ************************************************************************** */
/* Data structures                                                            */
/* ************************************************************************** */

struct User {
    UserID id;

    std::string name;
    std::string email;
};

struct Drive {

    DriveID id;

    struct Departure {
        unsigned hours;
        unsigned minutes;
    };

    unsigned max_capacity;

    enum Days repeat_days;

    std::vector<Departure> departures;

    std::string destination;

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
};

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */

Database *newDatabase() {
    return new Database();
}

void freeDatabase(Database *db) {
    delete db;
}
