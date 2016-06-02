#ifndef BACKEND_H
#define BACKEND_H

#include <map>
#include <list>
#include <string>
#include <ctime>


typedef std::time_t Date;

struct Drive {

    typedef unsigned ID;

private:

    Date departure_;

public:

    unsigned getCapacity() const;

    const Date& getDeparture() const;

};

struct Reservation {

    typedef unsigned ID;

};


struct Database {

    typedef std::list< Drive> DriveStore;

    struct DriveStoreSubset{
        DriveStore::const_iterator from;
        DriveStore::const_iterator to;
    };

    typedef std::map<Reservation::ID, Reservation> ReservationStore;
private:

    DriveStore drives_;
    ReservationStore reservations_;

public:

    bool reserveTicket(Drive::ID driveid, const std::string& name);

    const DriveStoreSubset getDrives(const Date& from, const Date& to) {

        DriveStoreSubset subset;
        subset.from = drives_.end();
        subset.to = drives_.end();

        for(DriveStore::const_iterator it = drives_.begin(); it != drives_.end(); it++) {
            if(subset.from == drives_.end() && it->getDeparture() >= from) subset.from = it;
            if(it->getDeparture() <= to) subset.from = it;
        }

        return subset;
    }

    const DriveStoreSubset getDrives() {
        DriveStoreSubset subset;
        subset.from = drives_.start();
        subset.to = drives_.end();
        return subset;
    }


};



#endif // BACKEND_H
