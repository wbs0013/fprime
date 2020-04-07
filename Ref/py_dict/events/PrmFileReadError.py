'''
Created on Monday, 06 April 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Svc/PrmDb/PrmDbComponentAi.xml
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


COMPONENT = "Svc::PrmDb"

NAME = "PrmFileReadError"
ID  = 0x93
SEVERITY = "WARNING_HI"
FORMAT_STRING = "Parameter file read failed in stage %s with record %d and error %d"
EVENT_DESCRIPTION = "Failed to read parameter file"

# Set arguments list with default values here.
ARGUMENTS = [
    ("stage","The write stage",EnumType("PrmReadError",{"PRM_READ_OPEN":0,"PRM_READ_DELIMETER":1,"PRM_READ_DELIMETER_SIZE":2,"PRM_READ_DELIMETER_VALUE":3,"PRM_READ_RECORD_SIZE":4,"PRM_READ_RECORD_SIZE_SIZE":5,"PRM_READ_RECORD_SIZE_VALUE":6,"PRM_READ_PARAMETER_ID":7,"PRM_READ_PARAMETER_ID_SIZE":8,"PRM_READ_PARAMETER_VALUE":9,"PRM_READ_PARAMETER_VALUE_SIZE":10,})),
    ("record","The record that had the failure",I32Type()),
    ("error","The error code",I32Type()),
    ]

