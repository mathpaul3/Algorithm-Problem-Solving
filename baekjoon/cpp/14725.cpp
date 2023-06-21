#include <iostream>
#include <map>
using namespace std;

struct Room {
    string feed;
    map<string,Room*> next_level;

    Room(string f) {
        feed = f;
    }

    Room* insert(string f) {
        map<string,Room*>::const_iterator it = next_level.find(f);
        Room *result = it->second;
        if (it==next_level.end()) {
            Room* r = new Room(f);
            result = r;
            next_level.insert(make_pair(f, r));
        }
        return result;
    }

    void search(int depth) {
        for (auto it=next_level.begin(); it!=next_level.end(); it++) {
            int i=0;
            while (i++ != depth) cout << "--";
            cout << it->first << '\n';
            it->second->search(depth+1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Room entrance("entrance");
    int N;
    cin >> N;
    while (N--) {
        int K;
        Room* prev = &entrance;
        cin >> K;
        while (K--) {
            string feed;
            cin >> feed;
            prev = prev->insert(feed);
        }
    }
    entrance.search(0);
    return 0;
}