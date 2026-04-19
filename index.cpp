#include <iostream>
using namespace std;

// Enum for door types
enum Door {
    EXIT,
    TRAP,
    START
};

// Function to convert door to string
string doorToString(Door d) {
    switch(d) {
        case EXIT: return "Safe Exit ";
        case TRAP: return "Trap ";
        case START: return "Back to Start ";
    }
    return "Unknown";
}

// Decision logic function
Door chooseDoor(bool isGuardAlert, bool hasMap, bool hearsNoise) {
    
    // Rule 1: If guard is alert → avoid risky move → go back
    if (isGuardAlert) {
        return START;
    }

    // Rule 2: If player has a map → choose safe exit
    if (hasMap) {
        return EXIT;
    }

    // Rule 3: If hears suspicious noise → likely trap
    if (hearsNoise) {
        return TRAP;
    }

    // Default safe fallback
    return START;
}

int main() {
    bool isGuardAlert = false;
    bool hasMap = true;
    bool hearsNoise = false;

    Door result = chooseDoor(isGuardAlert, hasMap, hearsNoise);

    cout << "Chosen Door: " << doorToString(result) << endl;

    return 0;
}
