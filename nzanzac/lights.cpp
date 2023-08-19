#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct E {
    int cars;
    int time;
    E(int c, int t): cars(c), time(t) {}
};

int main() {
    int green_length, red_length;
    int queue_length, time, total_cars = 0, s, num;
    char c;

    cin >> green_length >> red_length >> queue_length >> time >> s;

    int most_seconds = time, most_cars = queue_length;
    queue<E> q;
    q.emplace(queue_length, 0);

    while (s--) {
        cin >> c >> num;
        E front = q.front();
        if (c == 'G') {
            total_cars += num;
            queue_length -= num;
            if (num == 0) {
                time += green_length;
                continue;
            }
            most_seconds = max(most_seconds, time-front.time);
            while (total_cars >= front.cars) {
                most_seconds = max(most_seconds, time-front.time);
                q.pop();
                if (q.empty()) break;
                front = q.front();
            }
            time += green_length;
        } else {
            queue_length += num;
            q.emplace(total_cars+queue_length, time);
//            cout << "Adding " << total_cars+queue_length << " cars and " << time << " time to queue" << endl;
            most_cars = max(most_cars, queue_length);
            time += red_length;
        }
//        cout << c << ": " << total_cars << " total cars, at time " << time << " with " << most_seconds << " highest seconds and " << most_cars << " most cars. " << queue_length << " cars in queue\n";
//        cout << "Current front was " << front.cars << " at time " << front.time << "\n";
    }
    cout << "Longest queue was " << most_cars << " vehicle" << (most_cars == 1 ? "." : "s.") << endl;
    cout << "Longest through time was " << most_seconds/60 << " minute" << (most_seconds/60 == 1 ? " " : "s ");
    cout << "and " << most_seconds%60 << " second" << (most_seconds%60 == 1 ? "." : "s.") << endl;
}

