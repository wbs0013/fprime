'''
Created on Wednesday, 25 March 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Svc/Health/HealthComponentAi.xml
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


COMPONENT = "Svc::Health"

NAME = "HLTH_PING_LATE"
ID  = 0x16a
SEVERITY = "FATAL"
FORMAT_STRING = "Ping entry %s did not respond"
EVENT_DESCRIPTION = "Declare FATAL since task is no longer responding"

# Set arguments list with default values here.
ARGUMENTS = [
    ("entry","The entry passing the warning level",StringType(max_string_len=40)),
    ]

