#include <stdio.h>
#include <math.h>

// Constants
const double G = 6.67430e-11; // gravitational constant in m^3 kg^-1 s^-2
const double M_earth = 5.972e24; // mass of Earth in kg
const double R_earth = 6371e3; // radius of Earth in meters
const double PI=3.141562; //Pi....

double circular_orbit_velocity(double altitude) {
    // Calculate the velocity needed for a circular orbit at a given altitude above Earth.
    double r = R_earth + altitude;
    return sqrt(G * M_earth / r); 
}

double orbital_period(double altitude) {
    // Calculate the orbital period for a circular orbit at a given altitude above Earth.
    double r = R_earth + altitude;
    double velocity = circular_orbit_velocity(altitude);
    return 2 * PI * r / velocity;
}

double orbital_energy(double altitude, double mass) {
    // Calculate the total orbital energy (kinetic + potential) per unit mass for an orbit at a given altitude.
    double r = R_earth + altitude;
    double velocity = circular_orbit_velocity(altitude);
    double kinetic_energy_per_mass = 0.5 * pow(velocity, 2);
    double potential_energy_per_mass = -G * M_earth / r;
    return kinetic_energy_per_mass + potential_energy_per_mass;
}

int main() {
    // Example usage
    double altitude = 400e3; // 400 km above Earth's surface
    double mass = 2; // mass of the satellite in kg (ie 1U CubeSat)

    double velocity = circular_orbit_velocity(altitude);
    double period = orbital_period(altitude);
    double energy = orbital_energy(altitude, mass);

    printf("Circular Orbit Velocity: %f m/s\n", velocity);
    printf("Orbital Period: %f hours\n", period / 3600);
    printf("Orbital Energy per unit mass: %f J/kg\n", energy);

    return 0;
}
