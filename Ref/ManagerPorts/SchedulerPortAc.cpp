#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <Ref/ManagerPorts/SchedulerPortAc.hpp>
namespace Ref {


    namespace {

        class SchedulerPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity(void) const {
                    return sizeof(m_buff);
                }

                U8* getBuffAddr(void) {
                    return m_buff;
                }

                const U8* getBuffAddr(void) const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputSchedulerPort::SERIALIZED_SIZE];

        };

    }
    InputSchedulerPort::InputSchedulerPort(void) :
        Fw::InputPortBase(),
        m_func(0) {
    }

    void InputSchedulerPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputSchedulerPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputSchedulerPort::invoke(F32 message) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, message);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputSchedulerPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        F32 message;
        _status = buffer.deserialize(message);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, message);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputSchedulerPort::OutputSchedulerPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputSchedulerPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputSchedulerPort::addCallPort(InputSchedulerPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputSchedulerPort::invoke(F32 message) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(message);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        SchedulerPortBuffer _buffer;
        status = _buffer.serialize(message);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }    
#endif

} // end OutputSchedulerPort::invoke(...)

} // end namespace Ref
