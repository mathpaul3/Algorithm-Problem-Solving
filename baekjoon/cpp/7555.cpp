#include <iostream>
#include <sstream>
#define ANNE 0
#define BOB 1
#define CHARLEY 2
#define DAVE 3
#define EDWARD 4
#define FRANK 5
#define KARIN 6
#define CINEMA 0
#define COCKTAIL 1
#define DISCO 2
using namespace std;

void vote(int name, bool *exists, short *votes) {
    if (name==ANNE) votes[CINEMA]++;
    else if (name==BOB) {
        if (exists[DAVE] || exists[EDWARD] || !exists[ANNE]) {
            if (!exists[KARIN]) votes[COCKTAIL]++;
        } else if (exists[KARIN]) votes[DISCO]++;
        else if (exists[KARIN] && !(exists[DAVE] || exists[EDWARD] || !exists[ANNE])) votes[DISCO]++;
    } else if (name==CHARLEY) {
        if (exists[ANNE]) votes[CINEMA]++;
    } else if (name==EDWARD) {
        if (exists[ANNE] && !exists[CHARLEY]) votes[COCKTAIL]++;
        else votes[CINEMA]++;
    } else if (name==FRANK) {
        if (exists[ANNE]) votes[DISCO]++;
        else if (!exists[BOB] && !exists[ANNE]) votes[CINEMA]++;
    } else if (name==KARIN) {
        if (exists[CHARLEY]) votes[DISCO]++;
        else if (exists[ANNE]) votes[CINEMA]++;
        else votes[COCKTAIL]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int S;
    string PLACE[3]={"cinema", "cocktail bar", "disco"};
    cin >> S;
    cin.ignore();
    for (int scene=1; scene<=S; scene++) {
        bool existence[7]={0,};
        short votes[3]={0,}, place=3;
        string names, name;

        getline(cin, names);
        stringstream ss(names);
        
        while (getline(ss, name, ' ')) {
            if (name=="Anne") existence[ANNE] = true;
            else if (name=="Bob") existence[BOB] = true;
            else if (name=="Charly") existence[CHARLEY] = true;
            else if (name=="Dave") existence[DAVE] = true;
            else if (name=="Edward") existence[EDWARD] = true;
            else if (name=="Frank") existence[FRANK] = true;
            else if (name=="Karin") existence[KARIN] = true;
        }
        for (int person=0; person<7; person++)
            if (existence[person]) vote(person, existence, votes);

        if (votes[CINEMA]>votes[COCKTAIL] && votes[CINEMA]>votes[DISCO]) place = CINEMA;
        if (votes[COCKTAIL]>votes[CINEMA] && votes[COCKTAIL]>votes[DISCO]) place = COCKTAIL;
        if (votes[DISCO]>votes[CINEMA] && votes[DISCO]>votes[COCKTAIL]) place = DISCO;
        cout << "Scenario #" << scene << ":\n" << (place<3 ? PLACE[place] : "stay at the Hacienda") << "\n\n";
    }
    return 0;
}