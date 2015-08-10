/**
 * @file GblTrack.cxx
 * @brief Class used to encapsulate GBL track information.
 * @author Per Hansson Adrian <phansson@slac.stanford.edu>
 *          SLAC
 * @author Omar Moreno <omoreno1@ucsc.edu>
 *         Santa Cruz Institute for Particle Physics
 *         University of California, Santa Cruz
 * @date February 3, 2014
 */

#include <GblTrack.h>

ClassImp(GblTrack)

GblTrack::GblTrack() 
    : TObject(),
      seed_track(NULL), 
      cov_matrix(5, 5),
      d0(0),
      phi0(0),
      kappa(0),
      theta(0),
      z0(0),      
      chi_squared(-1.), 
      ndof(0), 
      px(0), 
      py(0), 
      pz(0) {
}

GblTrack::~GblTrack() {
    Clear(); 
}

void GblTrack::Clear(Option_t *option) { 
    TObject::Clear(); 
}

void GblTrack::setTrackParameters(const double d0, 
        const double phi0,
        const double kappa,
        const double theta,
        const double z0) {

    this->d0 = d0; 
    this->phi0 = phi0; 
    this->kappa = kappa; 
    this->theta = theta;
    this->z0 = z0;  
}

void GblTrack::setMomentumVector(double x, double y, double z) {
    px = x;
    py = y;
    pz = z;
}

std::vector<double> GblTrack::getMomentum() {
    std::vector<double> p(3, 0);
    p[0] = px; 
    p[1] = py; 
    p[2] = pz;
    return p; 
}

void GblTrack::toString() {
    std::cout << "GblTrack: " << std::endl;
    std::cout << "    (kappa, theta, phi0, d0, z0): " 
        << getKappa() 
        << "," << getTheta() 
        << "," << getPhi0() 
        << "," << getD0() 
        << "," << getZ0() << std::endl;
}
