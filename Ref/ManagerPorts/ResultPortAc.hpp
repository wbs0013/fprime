/*
 * ResultPort.hpp
 *
 *  Created on: Thursday, 26 March 2020
 *  Author:     wbs0013
 *
 */
#ifndef REF_RESULT_PORT_HPP_
#define REF_RESULT_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Ref {

    /// Input Result port description
    /// 

    class InputResultPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(F32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, F32 result); //!< port callback definition

        InputResultPort(void); //!< constructor
        void init(void); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(F32 result); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Input Result port description
    /// 
    
    class OutputResultPort : public Fw::OutputPortBase {
      public: 
        OutputResultPort(void);
        void init(void);
        void addCallPort(InputResultPort* callPort);
        void invoke(F32 result);
      protected:
      private:
        InputResultPort* m_port;
    };
} // end namespace Ref
#endif /* REF_RESULT_PORT_HPP_ */

