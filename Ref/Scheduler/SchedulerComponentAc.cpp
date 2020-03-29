// ======================================================================
// \title  SchedulerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for Scheduler component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <stdio.h>
#include <Fw/Cfg/Config.hpp>
#include <Ref/Scheduler/SchedulerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/EightyCharString.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      SCHEDULER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      CMD_SCHEDULE
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE cmdPort[Fw::InputCmdPort::SERIALIZED_SIZE];
    } BuffUnion;

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component

    class ComponentIpcSerializableBuffer :
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Max. message size = size of data + message id + port
          SERIALIZATION_SIZE =
            sizeof(BuffUnion) +
            sizeof(NATIVE_INT_TYPE) +
            sizeof(NATIVE_INT_TYPE)
        };

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
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputCmdPort *SchedulerComponentBase ::
    get_CmdDisp_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_CmdDisp_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_CmdDisp_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    set_schedulerOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputSchedulerPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_schedulerOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_schedulerOut_OutputPort[portNum].addCallPort(port);
  }

  void SchedulerComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_CmdStatus_OutputPort[portNum].addCallPort(port);
  }

  void SchedulerComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdRegPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_CmdReg_OutputPort[portNum].addCallPort(port);
  }

  void SchedulerComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Tlm_OutputPort[portNum].addCallPort(port);
  }

  void SchedulerComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void SchedulerComponentBase ::
    set_schedulerOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_schedulerOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_schedulerOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SchedulerComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_CmdStatus_OutputPort[portNum].registerSerialPort(port);
  }

  void SchedulerComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_CmdReg_OutputPort[portNum].registerSerialPort(port);
  }

  void SchedulerComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Tlm_OutputPort[portNum].registerSerialPort(port);
  }

  void SchedulerComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Command registration
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    regCommands(void)
  {
    FW_ASSERT(this->m_CmdReg_OutputPort[0].isConnected());
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_SCHEDULE
    );
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SchedulerComponentBase ::
#if FW_OBJECT_NAMES == 1
    SchedulerComponentBase(const char* compName) :
      Fw::ActiveComponentBase(compName)
#else
    SchedulerComponentBase() :
      Fw::ActiveComponentBase()
#endif
  {



  }

  void SchedulerComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port CmdDisp
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_CmdDisp_InputPorts();
        port++
    ) {

      this->m_CmdDisp_InputPort[port].init();
      this->m_CmdDisp_InputPort[port].addCallComp(
          this,
          m_p_CmdDisp_in
      );
      this->m_CmdDisp_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdDisp_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_CmdDisp_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port schedulerOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_schedulerOut_OutputPorts();
        port++
    ) {
      this->m_schedulerOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_schedulerOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_schedulerOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdStatus
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_CmdStatus_OutputPorts();
        port++
    ) {
      this->m_CmdStatus_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdStatus_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_CmdStatus_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdReg
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_CmdReg_OutputPorts();
        port++
    ) {
      this->m_CmdReg_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdReg_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_CmdReg_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Tlm
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Tlm_OutputPorts();
        port++
    ) {
      this->m_Tlm_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Tlm_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Tlm_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Time
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Time_OutputPorts();
        port++
    ) {
      this->m_Time_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[80];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Time_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Time_OutputPort[port].setObjName(portName);
#endif

    }

    Os::Queue::QueueStatus qStat =
    this->createQueue(
        queueDepth,
        ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
    );
    FW_ASSERT(
        Os::Queue::QUEUE_OK == qStat,
        static_cast<AssertArg>(qStat)
    );

  }

  SchedulerComponentBase::
    ~SchedulerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    schedulerOut_out(
        NATIVE_INT_TYPE portNum,
        F32 message
    )
  {
    FW_ASSERT(portNum < this->getNum_schedulerOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_schedulerOut_OutputPort[portNum].invoke(message);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_schedulerOut_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_schedulerOut_OutputPort
    );
  }

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_CmdDisp_InputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_CmdDisp_InputPort
    );
  }

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_CmdStatus_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_CmdStatus_OutputPort
    );
  }

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_CmdReg_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_CmdReg_OutputPort
    );
  }

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_Tlm_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_Tlm_OutputPort
    );
  }

  NATIVE_INT_TYPE SchedulerComponentBase ::
    getNum_Time_OutputPorts(void)
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(
        this->m_Time_OutputPort
    );
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool SchedulerComponentBase ::
    isConnected_schedulerOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_schedulerOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_schedulerOut_OutputPort[portNum].isConnected();
  }

  bool SchedulerComponentBase ::
    isConnected_CmdStatus_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdStatus_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_CmdStatus_OutputPort[portNum].isConnected();
  }

  bool SchedulerComponentBase ::
    isConnected_CmdReg_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdReg_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_CmdReg_OutputPort[portNum].isConnected();
  }

  bool SchedulerComponentBase ::
    isConnected_Tlm_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Tlm_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Tlm_OutputPort[portNum].isConnected();
  }

  bool SchedulerComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for messages received on command input ports
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Select base class function based on opcode
    FW_ASSERT(callComp);
    SchedulerComponentBase* compPtr =
      (SchedulerComponentBase*) callComp;

    const U32 idBase = callComp->getIdBase();
    FW_ASSERT(opCode >= idBase, opCode, idBase);
    switch (opCode - idBase) {

      case OPCODE_SCHEDULE: /*!< Schedule a command */
        compPtr->SCHEDULE_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      default: {
        compPtr->cmdResponse_out(
            opCode,cmdSeq,
            Fw::COMMAND_INVALID_OPCODE
        );
        break;
      }

    }

  }

  void SchedulerComponentBase ::
    cmdResponse_out(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FW_ASSERT(this->m_CmdStatus_OutputPort[0].isConnected());
    this->m_CmdStatus_OutputPort[0].invoke(opCode,cmdSeq,response);
  }

  // ----------------------------------------------------------------------
  // Base class command functions
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    SCHEDULE_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Call pre-message hook
    this->SCHEDULE_preMsgHook(opCode,cmdSeq);

    // Defer deserializing arguments to the message dispatcher
    // to avoid deserializing and reserializing just for IPC
    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize for IPC
    _status = msg.serialize((NATIVE_INT_TYPE)CMD_SCHEDULE);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
        );

    // Fake port number to make message dequeue work
    NATIVE_INT_TYPE port = 0;
    _status = msg.serialize(port);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(opCode);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(cmdSeq);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(args);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );

  }

  void SchedulerComponentBase::
    SCHEDULE_preMsgHook(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // Defaults to no-op; can be overridden
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void SchedulerComponentBase ::
    tlmWrite_SCHED_SENT(bool arg)
  {

    if (this->m_Tlm_OutputPort[0].isConnected()) {
      Fw::Time _tlmTime;
      if (this->m_Time_OutputPort[0].isConnected()) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_SCHED_SENT;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SchedulerComponentBase ::
    tlmWrite_TIME_WAIT(F32 arg)
  {

    if (this->m_Tlm_OutputPort[0].isConnected()) {
      Fw::Time _tlmTime;
      if (this->m_Time_OutputPort[0].isConnected()) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_TIME_WAIT;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time SchedulerComponentBase ::
    getTime(void)
  {
    if (this->m_Time_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_Time_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus SchedulerComponentBase ::
    doDispatch(void)
  {
    ComponentIpcSerializableBuffer msg;
    NATIVE_INT_TYPE priority;

    Os::Queue::QueueStatus msgStatus = this->m_queue.receive(msg,priority,Os::Queue::QUEUE_BLOCKING);
    FW_ASSERT(
        msgStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    NATIVE_INT_TYPE desMsg;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == SCHEDULER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    switch (msgType) {

      // Handle command SCHEDULE
      case CMD_SCHEDULE: {
        // Deserialize opcode
        FwOpcodeType opCode;
        deserStatus = msg.deserialize(opCode);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Deserialize command sequence
        U32 cmdSeq;
        deserStatus = msg.deserialize(cmdSeq);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Deserialize command argument buffer
        Fw::CmdArgBuffer args;
        deserStatus = msg.deserialize(args);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(deserStatus)
        );

        // Reset buffer
        args.resetDeser();

        // Deserialize argument time
        F32 time;
        deserStatus = args.deserialize(time);
        if (deserStatus != Fw::FW_SERIALIZE_OK) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(
                opCode,
                cmdSeq,
                Fw::COMMAND_FORMAT_ERROR
            );
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }

        // Make sure there was no data left over.
        // That means the argument buffer size was incorrect.
#if FW_CMD_CHECK_RESIDUAL
        if (args.getBuffLeft() != 0) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_FORMAT_ERROR);
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }
#endif
        // Call handler function
        this->SCHEDULE_cmdHandler(
            opCode,
            cmdSeq,
            time
        );

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Ref
