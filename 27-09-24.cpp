class MyCalendarTwo {
public:
    map<int, int> bookingCount;
    int maxOverlappedBooking;

    MyCalendarTwo() { maxOverlappedBooking = 2; }

    bool book(int start, int end) {
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;
        for (pair<int, int> bookings : bookingCount) {
            overlappedBooking += bookings.second;

            if (overlappedBooking > maxOverlappedBooking) {
                bookingCount[start]--;
                bookingCount[end]++;

                if (bookingCount[start] == 0) {
                    bookingCount.erase(start);
                }
                if (bookingCount[end] == 0) {
                    bookingCount.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};