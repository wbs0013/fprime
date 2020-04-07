// ======================================================================
// \title  TemperatureComponentImpl.hpp
// \author wbs0013
// \brief  hpp file for Temperature component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Temperature_HPP
#define Temperature_HPP

#include "Ref/Temperature/TemperatureComponentAc.hpp"

namespace Ref {

  class TemperatureComponentImpl :
    public TemperatureComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Temperature
      //!
      TemperatureComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Temperature
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Temperature
      //!
      ~TemperatureComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for Temperature_Settings command handler
      //! 
      void Temperature_Settings_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 temperature, 
          F32 highBound, 
          F32 lowBound, 
          ChangeOfTemp change 
      );


    };

} // end namespace Ref

#endif
