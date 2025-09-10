#include "Auton.h"
#include "main.h"
#include "robodash/api.h"

rd::Selector selector({
    {"red_left_auton", red_left_auton},
    {"red_right_auton", red_right_auton},
    {"blue_left_auton", blue_left_auton},
    {"blue_right_auton", blue_right_auton},
    {"skills_auton", skills_auton},
});


void autonomous() { 
    selector.run_auton();
}

// Define autonomous routines
void red_left_auton() {
    
}

void red_right_auton() {
    // Red right autonomous code
}

void blue_left_auton() {
    // Blue left autonomous code
}

void blue_right_auton() {
    // Blue right autonomous code
}

void skills_auton() {
    // Skills autonomous code
}


