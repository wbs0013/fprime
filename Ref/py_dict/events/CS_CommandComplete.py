'''
Created on Wednesday, 25 March 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Svc/CmdSequencer/CmdSequencerComponentAi.xml
'''

# Import the types this way so they do not need prefixing for execution.
from fprime.common.models.serialize.type_exceptions import *
from fprime.common.models.serialize.type_base import *

from fprime.common.models.serialize.bool_type import *
from fprime.common.models.serialize.enum_type import *
from fprime.common.models.serialize.f32_type import *
from fprime.common.models.serialize.f64_type import *

from fprime.common.models.serialize.u8_type import *
from fprime.common.models.serialize.u16_type import *
from fprime.common.models.serialize.u32_type import *
from fprime.common.models.serialize.u64_type import *

from fprime.common.models.serialize.i8_type import *
from fprime.common.models.serialize.i16_type import *
from fprime.common.models.serialize.i32_type import *
from fprime.common.models.serialize.i64_type import *

from fprime.common.models.serialize.string_type import *
from fprime.common.models.serialize.serializable_type import *

from fprime_gds.common.models.common import event
# Each file represents the information for a single event
# These module variables are used to instance the event object within the Gse


COMPONENT = "Svc::CmdSequencer"

NAME = "CS_CommandComplete"
ID  = 0x225
SEVERITY = "ACTIVITY_LO"
FORMAT_STRING = "Sequence file %s: Command %d (opcode %d) complete"
EVENT_DESCRIPTION = "The Command Sequencer issued a command and received a success status in return."

# Set arguments list with default values here.
ARGUMENTS = [
    ("fileName","The name of the sequence file",StringType(max_string_len=60)),
    ("recordNumber","The record number of the command",U32Type()),
    ("opCode","The command opcode",U32Type()),
    ]

