<title>Temperature Component Dictionary</title>
# Temperature Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|Temperature_Settings|0 (0x0)|| | |
| | | |temperature|F32||
| | | |highBound|F32||
| | | |lowBound|F32||
| | | |change|ChangeOfTemp||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|TEMP_SET|0 (0x0)|bool||
|CURRENT_TEMP|1 (0x1)|F32||
|TEMP_HI_THRESHOLD|2 (0x2)|F32||
|TEMP_LO_THRESHOLD|3 (0x3)|F32||
|FLAG1|4 (0x4)|bool||
|FLAG2|5 (0x5)|bool||
|FLAG3|6 (0x6)|bool||
|FLAG4|7 (0x7)|bool||
|FLAG5|8 (0x8)|bool||
|FLAG6|9 (0x9)|bool||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|TEMP_NOMINAL|0 (0x0)|| | | | |
| | | |tempNominal|bool||The val1 argument|
|TEMP_HIGH|1 (0x1)|| | | | |
| | | |tempHigh|bool||The val1 argument|
|TEMP_LOW|2 (0x2)|| | | | |
| | | |tempLow|bool||The val1 argument|
