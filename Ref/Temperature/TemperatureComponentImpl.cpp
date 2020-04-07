// ======================================================================
// \title  TemperatureComponentImpl.cpp
// \author wbs0013
// \brief  cpp file for Temperature component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Temperature/TemperatureComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

#include <unistd.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  TemperatureComponentImpl ::
#if FW_OBJECT_NAMES == 1
    TemperatureComponentImpl(
        const char *const compName
    ) :
      TemperatureComponentBase(compName)
#else
    TemperatureComponentImpl(void)
#endif
  {

  }

  void TemperatureComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    TemperatureComponentBase::init(queueDepth, instance);
  }

  TemperatureComponentImpl ::
    ~TemperatureComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void TemperatureComponentImpl ::
    Temperature_Settings_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 temperature,
        F32 highBound,
        F32 lowBound,
        ChangeOfTemp change
    )
  {
    
	this->tlmWrite_TEMP_SET(true);
	this->tlmWrite_FLAG1(true);
		this->tlmWrite_FLAG2(true);
		this->tlmWrite_FLAG3(true);
		this->tlmWrite_FLAG4(true);
		this->tlmWrite_FLAG5(true);
		this->tlmWrite_FLAG6(true);
	this->tlmWrite_CURRENT_TEMP(temperature);
	this->tlmWrite_TEMP_HI_THRESHOLD(highBound);
	this->tlmWrite_TEMP_LO_THRESHOLD(lowBound);
    switch (change) {
	case Decrease:
		while (temperature >= lowBound) {
			temperature = temperature - 1;
			this->tlmWrite_CURRENT_TEMP(temperature);
			sleep(2);
		}
		this->log_ACTIVITY_HI_TEMP_LOW(true);
		this->tlmWrite_FLAG1(false);
		this->tlmWrite_FLAG2(false);
		this->tlmWrite_FLAG3(false);
		this->tlmWrite_FLAG4(false);
		this->tlmWrite_FLAG5(false);
		this->tlmWrite_FLAG6(false);
		break;
	case Increase:
		while (temperature <= highBound) {
			temperature++;
			this->tlmWrite_CURRENT_TEMP(temperature);
			sleep(2);
		}
		this->log_ACTIVITY_HI_TEMP_HIGH(true);
		this->tlmWrite_FLAG1(false);
		this->tlmWrite_FLAG2(false);
		this->tlmWrite_FLAG3(false);
		this->tlmWrite_FLAG4(false);
		this->tlmWrite_FLAG5(false);
		this->tlmWrite_FLAG6(false);
		break;
	}
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
