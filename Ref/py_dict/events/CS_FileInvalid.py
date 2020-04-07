'''
Created on Monday, 06 April 2020
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

NAME = "CS_FileInvalid"
ID  = 0x220
SEVERITY = "WARNING_HI"
FORMAT_STRING = "Sequence file %s invalid. Stage: %s Error: %d"
EVENT_DESCRIPTION = "The sequence file format was invalid."

# Set arguments list with default values here.
ARGUMENTS = [
    ("fileName","The name of the sequence file",StringType(max_string_len=60)),
    ("stage","The read stage",EnumType("FileReadStage",{"SEQ_READ_HEADER":0,"SEQ_READ_HEADER_SIZE":1,"SEQ_DESER_SIZE":2,"SEQ_DESER_NUM_RECORDS":3,"SEQ_DESER_TIME_BASE":4,"SEQ_DESER_TIME_CONTEXT":5,"SEQ_READ_SEQ_CRC":6,"SEQ_READ_SEQ_DATA":7,"SEQ_READ_SEQ_DATA_SIZE":8,})),
    ("error","The error code",I32Type()),
    ]

