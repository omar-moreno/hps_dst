/**
 *	@file   HpsEventBuilder.h
 *	@author Omar Moreno <omoreno1@ucsc.edu>
 *		    Santa Cruz Institute for Particle Physics
 *		    University of California, Santa Cruz
 *	@date   December 31, 2013
 *
 */

#ifndef __HPS_EVENT_BUILDER_H__
#define __HPS_EVENT_BUILDER_H__


//-----------//
//--- DST ---//
//-----------//
#include <EventBuilder.h>
#include <SvtDataWriter.h>
#include <EcalDataWriter.h>
#include <MCParticleDataWriter.h>
#include <GblDataWriter.h>
#include <GblTrackWriter.h>
#include <HpsParticleDataWriter.h>

class HpsEventBuilder : public EventBuilder {

	public: 

        /**
         *  Default Constructor
         */
		HpsEventBuilder(); 

        /**
         *  Destructor
         */
		~HpsEventBuilder(); 

		/**
         *  Write collections present in the LCEvent to an HpsEvent.
         *
         *  @param event - The LCEvent to process
         *  @param hps_event - The HpsEvent to write the LCEvent data to
         */
		void makeHpsEvent(EVENT::LCEvent* event, HpsEvent* hps_event); 

		/**
         *  Set the strenght of the magnetic field during the run.  This is 
         *  currently used by GBL only and will be removed when the B field
         *  information can be retrieved from the recon file.
         *
         *  @param b_field - The strength of the magnetic field in tesla
         */
		void setBField(const double);
		
        /**
         *  Enable/disble the processing of SVT tracks with GBL.
         *
         *  @param run_gbl - true to enable GBL, false otherwise
         */
        void runGbl(const bool run_gbl) { this->run_gbl = run_gbl; };
	
        /**
         *  Enable/disable the creation of an HpsEvent using recon files 
         *  containing ECal data only.
         *
         *  @param ecal_only - true to write ECal data only, false otherwise
         */    
        void writeEcalOnly(const bool ecal_only) { this->ecal_only = ecal_only; }; 

	private:

		SvtDataWriter* svt_writer; 
		EcalDataWriter* ecal_writer; 
		MCParticleDataWriter* mc_particle_writer;
		HpsParticleDataWriter* particle_writer; 
		GblDataWriter* gbl_data_writer;
		GblTrackWriter* gbl_track_writer;

		bool run_gbl;
        bool ecal_only;

}; // HpsEventBuilder

#endif // __HPS_EVENT_BUILDER_H__
