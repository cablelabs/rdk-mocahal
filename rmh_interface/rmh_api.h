#ifndef RMH_API_H
#define RMH_API_H

#ifdef __cplusplus
extern "C" {
#endif


RMH_API_IMPLEMENTATION_GENERIC_THEN_SOC(
/********************************************************************************************************************/
/* API Declaration */
RMH_Handle RMH_Initialize(const RMH_EventCallback eventCB, void * userContext),

/* API Name */
RMH_Initialize,

/* Description */
"Initialize the RMH library and return a handle to the instance. This handle will be used in all future communication "
"with the RMH library. This function will fail if the MoCA driver is not properly install or is not able to operate. "
"Multiple simultaneous instances of RMH_Initialize are supported in single and multiprocess environments.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(eventCB,            const RMH_EventCallback,
        "A pointer to a function which will handle any callbacks from the RMH MoCA library. A value of NULL is permitted if you do not wish to receive callbacks"),

    INPUT_PARAM(userContext,        void*,
        "A pointer to some data that will be passed back with each callback. A value of NULL is permitted if the client requires no context during callbacks")
),

/* Wrap API */
FALSE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_THEN_GENERIC(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Destroy(RMH_Handle handle),

/* API Name */
RMH_Destroy,

/* Description */
"Destroy the instance of RMH library which was created by RMH_Initialize",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             RMH_Handle,
        "The RMH handle as returned by RMH_Initialize")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_THEN_SOC(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_SetEventCallbacks(RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_SetEventCallbacks,

/* Description */
"Set the list of callbacks you which to receive. For each callback a call will be made to <eventCB> which is provided "
"in the call to <RMH_Initialize>. By default all callbacks are disabled. Any subsequent calls to this API will "
"overwrite previous calls. For example, if you originally set value to 'RMH_API_PRINT' and later set to "
"'LINK_STATUS_CHANGED | MOCA_VERSION_CHANGED' you will stop receiving callbacks for 'RMH_API_PRINT'.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,              const uint32_t,         "A bitmask list of <RMH_Event> indicating the callbacks to be received.")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_GetEventCallbacks(RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_GetEventCallbacks,

/* Description */
"Get the list of events for which the client has registered.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,          uint32_t*,              "A bitmask list of <RMH_Event> indicating the currently enabled callbacks.")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_GetAllAPIs(const RMH_Handle handle, RMH_APIList** apiList),

/* API Name */
RMH_GetAllAPIs,

/* Description */
"Return a list of all APIs which are part of RMH.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    OUTPUT_PARAM(apiList,       RMH_APIList**,          "Output list of APIs")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_GetUnimplementedAPIs(const RMH_Handle handle, RMH_APIList** apiList),

/* API Name */
RMH_GetUnimplementedAPIs,

/* Description */
"Return a list of all RMH APIs which are unimplemented by the SoC library.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    OUTPUT_PARAM(apiList,       RMH_APIList**,          "Output list of APIs")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_GetAPITags(const RMH_Handle handle, RMH_APITagList** apiTags),

/* API Name */
RMH_GetAPITags,

/* Description */
"Return the list of all RMH APIs grouped into lists by their tags.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    OUTPUT_PARAM(apiTags,       RMH_APITagList**,       "Output list of Tags and APIs which belong to them")
),

/* Wrap API */
TRUE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_ResultToString(const RMH_Result value),

/* API Name */
RMH_ResultToString,

/* Description */
"Convert <RMH_Result> to a string",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,            const RMH_Result,             "Value to be printed as a string")
),

/* Wrap API */
FALSE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_LinkStatusToString(const RMH_LinkStatus value),

/* API Name */
RMH_LinkStatusToString,

/* Description */
"Convert <RMH_LinkStatus> to a string",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,            const RMH_LinkStatus,        "Value to be printed as a string")
),

/* Wrap API */
FALSE,

/* Tags */
"Core,Link"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_AdmissionStatusToString(const RMH_AdmissionStatus value),

/* API Name */
RMH_AdmissionStatusToString,

/* Description */
"Convert <RMH_AdmissionStatus> to a string",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,            const RMH_AdmissionStatus,        "Value to be printed as a string")
),

/* Wrap API */
FALSE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_MoCAVersionToString(const RMH_MoCAVersion value),

/* API Name */
RMH_MoCAVersionToString,

/* Description */
"Convert <RMH_MoCAVersion> to a string",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,            const RMH_MoCAVersion,        "Value to be printed as a string")
),

/* Wrap API */
FALSE,

/* Tags */
"Core,Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_PowerModeToString(const uint32_t value, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_PowerModeToString,

/* Description */
"Return a the bitmask <value> as a string. The bitmask is expected to contain one or more of <RMH_PowerMode>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,              const uint32_t,             "A bitmask of <RMH_PowerMode> to be printed as a string"),
    OUTPUT_PARAM(responseBuf,       char*,                      "A buffer where the log level string will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,               "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
FALSE,

/* Tags */
"Core,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_LogLevelToString(const uint32_t value, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_LogLevelToString,

/* Description */
"Return a the bitmask <value> as a string. The bitmask is expected to contain one or more of <RMH_LogLevel>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,              const uint32_t,             "A bitmask of <RMH_LogLevel> to be printed as a string"),
    OUTPUT_PARAM(responseBuf,       char*,                      "A buffer where the log level string will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,               "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
FALSE,

/* Tags */
"Core,log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_EventToString(const uint32_t value, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_EventToString,

/* Description */
"Return a the bitmask <value> as a string. The bitmask is expected to contain one or more of <RMH_Event>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,              const uint32_t,             "A bitmask of <RMH_Event> to be printed as a string"),
    OUTPUT_PARAM(responseBuf,       char*,                      "A buffer where the log level string will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,               "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
FALSE,

/* Tags */
"Core"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
const char* const RMH_MacToString(const RMH_MacAddress_t value, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_MacToString,

/* Description */
"Return a the provded MAC address in <value> as a string.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(value,              const RMH_MacAddress_t,     "A byte array MAC address"),
    OUTPUT_PARAM(responseBuf,       char*,                      "A buffer where the MAC string will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,               "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
FALSE,

/* Tags */
"Core,mac"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetEnabled,

/* Description */
"Return if the MoCA driver is actively connected to or attempting to connect to a MoCA network",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,
        "Set to 'true' if the MoCA driver is active. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Status"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetEnabled,

/* Description */
"Enable or disable the MoCA driver to connect to a MoCA network. Once enabled the driver will use whatever "
"parameters it has been configured for.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,
        "Pass 'true' to enable the MoCA driver. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetMoCALinkUp(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetMoCALinkUp,

/* Description */
"Check if this device is actively connected to a MoCA network. If so, RMH_Network and RMH_Remote APIs will then be "
"valid to call.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,       bool*,
        "Set to 'true' if this is device is actively connected to a MoCA Network")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Link"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetLOF(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetLOF,

/* Description */
"The last frequency on which this device operated.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The last operating frequency of the device")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetLOF(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Self_SetLOF,

/* Description */
"Manually set the last operating frequency of the device. This can be helpful to control what frequency is used for "
" future network connections.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "The desired last operating frequency of the device")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetScanLOFOnly(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetScanLOFOnly,

/* Description */
"Return if the device is scanning only the last operating frequency when attempting to establish a connection to a "
"MoCA network",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,
        "Set to 'true' if only the LOF is being checked when joining a MoCA network. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetScanLOFOnly(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetScanLOFOnly,

/* Description */
"Indicate if the device should join networks only on the last operating frequency. This is helpful to control the "
"exact frequency used for MoCA",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,
        "Pass 'true' to ensure this node will only join a network at the LOF. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetPreferredNCEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetPreferredNCEnabled,

/* Description */
"Return if this device is a preferred NC.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,
        "Set to 'true' if the device is a preferred NC. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetPreferredNCEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetPreferredNCEnabled,

/* Description */
"Enable or disable preferred NC on this device. If this is enabled the device has a greater chance of becoming the NC, "
"if set disable the chance of becoming the NC is reduced. However, please keep in mind that depending on your network "
"configuration, a device with preferred NC disabled could still become the NC."
"\n**NOTE: Setting this value may trigger a restart of the MoCA driver and cause the device to temporarily leave the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,
        "Pass 'true' to enable this device as a preferred NC. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetSoftwareVersion(const RMH_Handle handle, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_Self_GetSoftwareVersion,

/* Description */
"Return the version of software being used by the MoCA driver on this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,   "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseBuf,       char*,              "A buffer where the software version string will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,       "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetHighestSupportedMoCAVersion(const RMH_Handle handle, RMH_MoCAVersion* response),

/* API Name */
RMH_Self_GetHighestSupportedMoCAVersion,

/* Description */
"Return the highest version of MoCA supported by the MoCA driver on this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_MoCAVersion*,       "The highest version of MoCA supported")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetFrequencyMask(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetFrequencyMask,

/* Description */
"Set the bit mask for specifying which frequencies should be scanned during the listening phase of network search. "
"Depending on the RF band of operation, the MSB of this parameter corresponds to the lowest frequency channel of the band. "
"Each subsequent bit of this parameter represents the next highest 25MHz channel. The base channels for each RF band "
"are as follows:\n\n"
"\tBand D-Low : 46 (1150 MHz)\n"
"\tBand D-High: 56 (1400 MHz)\n"
"\tBand Ext-D : 46 (1150 MHz)\n"
"\tBand C4 : 40 (1000 MHz)\n"
"\tBand E : 20 ( 500 MHz)\n"
"\tBand F : 27 ( 675 MHz)\n"
"\tBand H : 39 ( 975 MHz)",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,
        "The bitmask of frequencies this device will use when joining a network")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetFrequencyMask(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Self_SetFrequencyMask,

/* Description */
"Set the bit mask for specifying which frequencies should be scanned during the listening phase of network search. "
"Depending on the RF band of operation, the MSB of this parameter corresponds to the lowest frequency channel of the band. "
"Each subsequent bit of this parameter represents the next highest 25MHz channel. The base channels for each RF band "
"are as follows:\n\n"
"\tBand D-Low : 46 (1150 MHz)\n"
"\tBand D-High: 56 (1400 MHz)\n"
"\tBand Ext-D : 46 (1150 MHz)\n"
"\tBand C4 : 40 (1000 MHz)\n"
"\tBand E : 20 ( 500 MHz)\n"
"\tBand F : 27 ( 675 MHz)\n"
"\tBand H : 39 ( 975 MHz)\n",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,
        "The bitmask of frequencies this device should use when joining a network")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetMaxPacketAggregation(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetMaxPacketAggregation,

/* Description */
"Get the maximum number of packets this device will aggregate",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The maximum number of packets this device will aggregate")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetMaxPacketAggregation(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Self_SetMaxPacketAggregation,

/* Description */
"Set the maximum allowed packets for aggregated transmissions.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "The maximum number of packets this device can aggregate")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetLowBandwidthLimit(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetLowBandwidthLimit,

/* Description */
"Get the current lower limit for PHY rate between two nodes.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The lower PHY limit")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetLowBandwidthLimit(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Self_SetLowBandwidthLimit,

/* Description */
"Set the lower threshold for the PHY link bandwidth between two nodes. If the rate falls below this limit a callback "
"of type <RMH_EVENT_LOW_BANDWIDTH> will be triggered",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "The new value to use as the lower PHY limit")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetMaxBitrate(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetMaxBitrate,

/* Description */
"The maximum PHY rate supported in non-turbo mode.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The maximum PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetTxPowerLimit(const RMH_Handle handle, const int32_t value),

/* API Name */
RMH_Self_SetTxPowerLimit,

/* Description */
"Set the maximum transmitter power level for this device."
"\n**NOTE: Setting this value may trigger a restart of the MoCA driver and cause the device to temporarily leave the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const int32_t,          "Desired transmitter power level. Minimum value -31, maximum value 3.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetTxPowerLimit(const RMH_Handle handle, int32_t* response),

/* API Name */
RMH_Self_GetTxPowerLimit,

/* Description */
"Get the current maximum transmission power level for this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      int32_t*,               "The maximum transmission power for this device")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetSupportedFrequencies(const RMH_Handle handle, uint32_t* responseArray, const size_t responseArraySize, size_t* responseArrayUsed),

/* API Name */
RMH_Self_GetSupportedFrequencies,

/* Description */
"Return a list of frequencies in the band used by this node. This frequency list does not account for taboo channels "
"or other filters which would limit the scope of frequencies this device would use to join a network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseArray,     uint32_t*,              "An array where the frequency list should be stored"),
    INPUT_PARAM(responseArraySize,  const size_t,           "The size of the response array"),
    OUTPUT_PARAM(responseArrayUsed, size_t*,                "The number of entries in the response array which have valid data")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetQAM256Enabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetQAM256Enabled,

/* Description */
"Return if this device is set as QAM256 capable in admission negotiations.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if QAM256 support is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,QAM"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetQAM256Enabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetQAM256Enabled,

/* Description */
"Enable or disable the QAM256 ability in admission negotiations."
"\n**NOTE: Setting this value may trigger a restart of the MoCA driver and cause the device to temporarily leave the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable QAM256 support on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],QAM"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetQAM256TargetPhyRate(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Self_GetQAM256TargetPhyRate,

/* Description */
"Get the target PHY rate in Mbps.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The target PHY rate in Mbps")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,QAM,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetQAM256TargetPhyRate(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Self_SetQAM256TargetPhyRate,

/* Description */
"Set the target PHY rate in Mbps."
"\n**NOTE: Setting this value may trigger a restart of the MoCA driver and cause the device to temporarily leave the network.",


/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "The target PHY rate in Mbps")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],QAM,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetTurboEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetTurboEnabled,

/* Description */
"Return if turbo mode is enabled on this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if turbo is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Turbo"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetTurboEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetTurboEnabled,

/* Description */
"Enable or disable turbo mode on this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable turbo on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Turbo"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetBondingEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetBondingEnabled,

/* Description */
"Return if bonding mode is enabled on this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if bonding is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Bonding"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetBondingEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetBondingEnabled,

/* Description */
"Enable or disable bonding mode on this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable bonding on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Bonding"
/********************************************************************************************************************/
)


RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetEnabledRDK(const RMH_Handle handle),

/* API Name */
RMH_Self_SetEnabledRDK,

/* Description */
"Enable MoCA uisng RDK specific configuration",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetLinkStatus(const RMH_Handle handle, RMH_LinkStatus* status),

/* API Name */
RMH_Self_GetLinkStatus,

/* Description */
"Current operational status of the MoCA interface. This API combines all known information about the MoCA device, "
"including the driver, MoCA link, interface status, ect. to determine if the link is functional. >RMH_LINK_STATUS_UP> "
"indicates MoCA is ready for use.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(status,        RMH_LinkStatus*,        "The current link state of MoCA")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Link"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetPrivacyEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Self_GetPrivacyEnabled,

/* Description */
"Return if MoCA privacy is enabled on this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if MoCA privacy is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Privacy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetPrivacyEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Self_SetPrivacyEnabled,

/* Description */
"Enable or disable MoCA privacy on this device. If enabled the device will only be permitted to join networks with "
"other devices which have the same password.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable MoCA privacy on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Privacy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetPrivacyPassword(const RMH_Handle handle, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_Self_GetPrivacyPassword,

/* Description */
"Get the current MoCA privacy password.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,   "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseBuf,       char*,              "A buffer where the MoCA password will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,       "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Privacy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetPrivacyPassword(const RMH_Handle handle, const char* value),

/* API Name */
RMH_Self_SetPrivacyPassword,

/* Description */
"Set the network password used to generate privacy keys. This string must be between 12 and 17 characters long with "
"each character being a decimal number (0-9).",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const char*,            "The MoCA network password. Although this is a string only 0-9 are permitted.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Privacy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_GetTabooChannels(const RMH_Handle handle, uint32_t *channelMaskStart,  uint32_t *channelMask),

/* API Name */
RMH_Self_GetTabooChannels,

/* Description */
"Return which channels will be taboo on this device. <channelMaskStart> will indicate the channel number of the lowest "
"RF frequency covered by <channel mask>. The bitmask <channelMask> is then used to identify exactly which frequencies "
"are taboo. Each consecutive bit of <channelMask> corresponds to channels offset by multiples of 25MHz. A bit in "
"<channelMask> will be set to '1' if that channel is taboo.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(channelMaskStart,   uint32_t*,              "The channel number of the lowest frequency which is taboo"),
    INPUT_PARAM(channelMask,        uint32_t*,
        "A bitmask of channels which are taboo. The first bit corresponds to the frequency of <channelMaskStart>")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Taboo,Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_SetTabooChannels(const RMH_Handle handle, const uint32_t channelMaskStart,  const uint32_t channelMask),

/* API Name */
RMH_Self_SetTabooChannels,

/* Description */
"Set which channels will be taboo on this device. <channelMaskStart> will indicate the channel number of the lowest "
"RF frequency covered by <channel mask>. The bitmask <channelMask> is then used to identify exactly which frequencies "
"are taboo. Each consecutive bit of <channelMask> corresponds to channels offset by multiples of 25MHz. A bit in "
"<channelMask> must be set to '1' if that channel is taboo.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(channelMaskStart,   const uint32_t,         "The channel number of the lowest frequency which is taboo"),
    INPUT_PARAM(channelMask,        const uint32_t,
        "A bitmask of channels which are taboo. The first bit corresponds to the frequency of <channelMaskStart>")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Taboo"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Self_RestoreDefaultSettings(const RMH_Handle handle),

/* API Name */
RMH_Self_RestoreDefaultSettings,

/* Description */
"Return this device to its default configuration",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set]"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Interface_GetEnabled(const RMH_Handle handle, bool *response),

/* API Name */
RMH_Interface_GetEnabled,

/* Description */
"Check if the MoCA interface is enabled at the kernel level. Do not confuse with <RMH_Self_GetEnabled> which checks if "
"the MoCA driver is active",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,
        "Set to 'true' if the MoCA interface is enabled at the kernel level. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Interface"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Interface_SetEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Interface_SetEnabled,

/* Description */
"Set MoCA interface enabled or disabled at the kernel level. Do not confuse with <RMH_Self_SetEnabled> which checks "
"if the MoCA driver is active",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable the interface. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Interface"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Interface_GetName(const RMH_Handle handle, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_Interface_GetName,

/* Description */
"Return the Linux interface name associated with the MoCA device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,   "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseBuf,       char*,              "A buffer where the interface name will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,       "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Interface"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Interface_GetMac(const RMH_Handle handle, RMH_MacAddress_t* response),

/* API Name */
RMH_Interface_GetMac,

/* Description */
"Return the MAC address associated with this MoCA device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The MAC address as a byte array")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Interface,mac"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Interface_SetMac(const RMH_Handle handle, const RMH_MacAddress_t value),

/* API Name */
RMH_Interface_SetMac,

/* Description */
"Set the MAC address associated with this MoCA device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const RMH_MacAddress_t, "The desired MAC address as a byte array")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Interface,mac"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_GetMode(const RMH_Handle handle, RMH_PowerMode* response),

/* API Name */
RMH_Power_GetMode,

/* Description */
"Return the current MoCA power state of this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_PowerMode*,         "The current power mode of this device")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_GetSupportedModes(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Power_GetSupportedModes,

/* Description */
"Return a bitmask of <RMH_PowerMode> indicating all MoCA power modes supported by this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "A bitmask of <RMH_PowerMode> listing supported modes")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_GetTxPowerControlEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Power_GetTxPowerControlEnabled,

/* Description */
"Return if transmit power control is enabled or disabled for this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,
        "Set to 'true' if transmission power control is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_SetTxPowerControlEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Power_SetTxPowerControlEnabled,

/* Description */
"Enable or disable if transmit power control is enabled for this device",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable transmission power control on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_GetTxBeaconPowerReductionEnabled(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Power_GetTxBeaconPowerReductionEnabled,

/* Description */
"Return if beacon power reduction is enabled on this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if beacon power reduction is enabled. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_SetTxBeaconPowerReductionEnabled(const RMH_Handle handle, const bool value),

/* API Name */
RMH_Power_SetTxBeaconPowerReductionEnabled,

/* Description */
"Enable or disable if beacon power reduction on this device.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const bool,             "Pass 'true' to enable beacon power control on this device. Otherwise pass to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_GetTxBeaconPowerReduction(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Power_GetTxBeaconPowerReduction,

/* Description */
"Return the power control back-off used by this node for transmitting beacons",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "Beacon power reduction")
),

/* Wrap API */
TRUE,

/* Tags */
"Self,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Power_SetTxBeaconPowerReduction(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Power_SetTxBeaconPowerReduction,

/* Description */
"Set the power control back-off used by this node for transmitting beacons",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "Beacon power reduction. Minimum value 0, Maximum value 5.")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Set],Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetNumNodes(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetNumNodes,

/* Description */
"Return the number of MoCA nodes in the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "Number of MoCA nodes in the network")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetNodeId(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetNodeId,

/* Description */
"Return the node ID of this device. This is a zero based ID which uniquely identifies this node on the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The device's node ID")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetNodeIds(const RMH_Handle handle, RMH_NodeList_Uint32_t* response),

/* API Name */
RMH_Network_GetNodeIds,

/* Description */
"Return a list of every node ID on the network. This differs from <RMH_Network_GetRemoteNodeIds> as this API *includes* the self node",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeList_Uint32_t*, "Where the index is the node Id, if <nodePresent> is 'true', <nodeValue> is the node Id.")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetRemoteNodeIds(const RMH_Handle handle, RMH_NodeList_Uint32_t* response),

/* API Name */
RMH_Network_GetRemoteNodeIds,

/* Description */
"Return a list of every node ID on the network. This differs from <RMH_Network_GetNodeIds> as this API *does not include* the self node",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeList_Uint32_t*, "Where the index is the node Id, if <nodePresent> is 'true', <nodeValue> is the node Id.")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetAssociatedIds(const RMH_Handle handle, RMH_NodeList_Uint32_t* response),

/* API Name */
RMH_Network_GetAssociatedIds,

/* Description */
"Return a list of the associated ID for every node on the network. This is a one-based index of every remote node on the network. The self node is not included in this list.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeList_Uint32_t*, "Where the index is the node Id, if <nodePresent> is 'true', <nodeValue> is the associated Id for that node.")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetNCNodeId(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetNCNodeId,

/* Description */
"Return the node ID of the network coordinator.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The network coordinator node Id")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetBackupNCNodeId(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetBackupNCNodeId,

/* Description */
"Return the node ID of the backup network coordinator.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The backup network coordinator node Id")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetNCMac(const RMH_Handle handle, RMH_MacAddress_t* response),

/* API Name */
RMH_Network_GetNCMac,

/* Description */
"Return the MAC address of the network coordinator.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The MAC address of the network coordinator")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,NC,mac"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetLinkUptime(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetLinkUptime,

/* Description */
"Returns the amount of time this node has been part of the MoCA network. Time is in seconds",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "Number of seconds this node has been in the network")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Link"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetMixedMode(const RMH_Handle handle, bool* response),

/* API Name */
RMH_Network_GetMixedMode,

/* Description */
"Check if the MoCA network contains both 1.1 and 2.0 nodes",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if both 1.1 and 2.0 nodes are present in the network. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetRFChannelFreq(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetRFChannelFreq,

/* Description */
"Return the frequency which the MoCA network is operating on",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The frequency of the MoCA network")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetPrimaryChannelFreq(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetPrimaryChannelFreq,

/* Description */
"Return the primary MoCA 2.0 channel",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The primary MoCA 2.0 channel")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetSecondaryChannelFreq(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetSecondaryChannelFreq,

/* Description */
"Return the secondary MoCA 2.0 channel",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The secondary MoCA 2.0 channel")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetMoCAVersion(const RMH_Handle handle, RMH_MoCAVersion* response),

/* API Name */
RMH_Network_GetMoCAVersion,

/* Description */
"Return the version of MoCA under which the network is operating.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_MoCAVersion*,       "The MoCA version of the network")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxBroadcastPhyRate(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetTxBroadcastPhyRate,

/* Description */
"Return the PHY rate at which broadcast packets are transmitted from this node",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The broadcast transmission PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Configuration [Get],Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxMapPhyRate(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetTxMapPhyRate,

/* Description */
"Return the PHY rate at which MAP packets are transmitted from this node",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The MAP transmission PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxGcdPowerReduction(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Network_GetTxGcdPowerReduction,

/* Description */
"The transmit power control back-off used for broadcast transmissions from this node",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "Transmit power control reduction. Minimum value 0, Maximum value 35")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTabooChannels(const RMH_Handle handle, uint32_t *channelMaskStart,  uint32_t *channelMask),

/* API Name */
RMH_Network_GetTabooChannels,

/* Description */
"Return which beacon channels will be taboo on this device. <channelMaskStart> will indicate the channel number of the lowest "
"RF frequency covered by <channel mask>. The bitmask <channelMask> is then used to identify exactly which frequencies "
"are taboo. Each consecutive bit of <channelMask> corresponds to channels offset by multiples of 25MHz. A bit in "
"<channelMask> will be set to '1' if that channel is taboo.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,   "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(channelMaskStart,   uint32_t*,          "The channel number of the lowest frequency which is taboo"),
    INPUT_PARAM(channelMask,        uint32_t*,
        "A bitmask of channels which are taboo. The first bit corresponds to the frequency of <channelMaskStart>")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Taboo,Frequency"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxUnicastPhyRate(const RMH_Handle handle, RMH_NodeMesh_Uint32_t* response),

/* API Name */
RMH_Network_GetTxUnicastPhyRate,

/* Description */
"Return the unicast transmit PHY rates between all nodes on the network. The resulting matrix will be in "
"<RMH_NodeMesh_Uint32_t>. Where the index is the node Id, if <nodePresent> is 'true', then <nodeValue> is "
"a list of the unicast PHY rates from this node Id to every other node on the network.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeMesh_Uint32_t*, "The PHY rate mesh table")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxVLPER(const RMH_Handle handle, RMH_NodeMesh_Uint32_t* response),

/* API Name */
RMH_Network_GetTxVLPER,

/* Description */
"Return the transmit VLPER (Very Low Packet Error Rate) PHY rates *between* all MoCA 2.0 nodes on the network. The "
"resulting matrix will be in <RMH_NodeMesh_Uint32_t>. Where the index is the node Id, if <nodePresent> is 'true', "
"then <nodeValue> is a list of the unicast PHY rates from this node Id to every other node on the network. Note, "
"MoCA 1.1 nodes will have <nodePresent> set to 'true', however they <nodeValue> will be 0.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeMesh_Uint32_t*, "The PHY rate mesh table")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetTxNPER(const RMH_Handle handle, RMH_NodeMesh_Uint32_t* response),

/* API Name */
RMH_Network_GetTxNPER,

/* Description */
"Return the transmit NPER (Nominal Packet Error Rate) PHY rates *from* all MoCA 2.0 nodes on the network. The "
"resulting matrix will be in <RMH_NodeMesh_Uint32_t>. Where the index is the node Id, if <nodePresent> is 'true', "
"then <nodeValue> is a list of the unicast PHY rates from this node Id to every other node on the network. Note, "
"MoCA 1.1 nodes will have <nodePresent> set to 'true', however they <nodeValue> will be 0.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeMesh_Uint32_t*, "The PHY rate mesh table")
),

/* Wrap API */
TRUE,

/* Tags */
"Network,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Network_GetBitLoadingInfo(const RMH_Handle handle, RMH_NodeMesh_Uint32_t* response),

/* API Name */
RMH_Network_GetBitLoadingInfo,

/* Description */
"TBD",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeMesh_Uint32_t*, "The resulting bitloading information")
),

/* Wrap API */
TRUE,

/* Tags */
"Network"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetNodeIdFromAssociatedId(const RMH_Handle handle, const uint32_t associatedId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetNodeIdFromAssociatedId,

/* Description */
"Convert an associated Id into a Node Id.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(associatedId,   const uint32_t,         "The associated Id of the node"),
    OUTPUT_PARAM(response,      uint32_t*,              "The node Id")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetAssociatedIdFromNodeId(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetAssociatedIdFromNodeId,

/* Description */
"Convert a node Id into an associated Id.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The associated Id of the node")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetMac(const RMH_Handle handle, const uint32_t nodeId, RMH_MacAddress_t* response),

/* API Name */
RMH_RemoteNode_GetMac,

/* Description */
"Return the MAC address of the remote node specificed by <nodeId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The MAC address of the remote node as a byte array")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,mac"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetPreferredNC(const RMH_Handle handle, const uint32_t nodeId, bool* response),

/* API Name */
RMH_RemoteNode_GetPreferredNC,

/* Description */
"Return if the node indicated by <nodeId> is a preferred NC or not.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if the remote node is a preferred NC. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetHighestSupportedMoCAVersion(const RMH_Handle handle, const uint32_t nodeId, RMH_MoCAVersion* response),

/* API Name */
RMH_RemoteNode_GetHighestSupportedMoCAVersion,

/* Description */
"Return the highest supported version of MoCA by the remote node specified by <nodeId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      RMH_MoCAVersion*,       "The highest version of MoCA supported")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetActiveMoCAVersion(const RMH_Handle handle, const uint32_t nodeId, RMH_MoCAVersion* response),

/* API Name */
RMH_RemoteNode_GetActiveMoCAVersion,

/* Description */
"Return the active supported version of MoCA by the remote node specificed by <nodeId>. There are cases where devices that "
"support MoCA 2.0 may be actively using MoCA 1.1. For example, when the NC is a MoCA 1.1 node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      RMH_MoCAVersion*,       "The active version of MoCA on the remote node")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Version"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetQAM256Capable(const RMH_Handle handle, const uint32_t nodeId, bool* response),

/* API Name */
RMH_RemoteNode_GetQAM256Capable,

/* Description */
"Return if the node indicated by <nodeId> has QAM256 enabled or not.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if the remote node is a QAM256 capable. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetMaxPacketAggregation(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetMaxPacketAggregation,

/* Description */
"Return the maximum number of packets for aggregated transmissions for the node indicated by <nodeId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The maximum number of packets <nodeId> will aggregate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetBondingCapable(const RMH_Handle handle, const uint32_t nodeId, bool* response),

/* API Name */
RMH_RemoteNode_GetBondingCapable,

/* Description */
"Return if the node indicated by <nodeId> is bonding capable enabled or not.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      bool*,                  "Set to 'true' if the remote node supports bonding. Otherwise set to 'false'.")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Bonding"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxUnicastPhyRate(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxUnicastPhyRate,

/* Description */
"Return the PHY rate at which unicast packets are received from <nodeId> from the self node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The unicast receive PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxBroadcastPhyRate(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxBroadcastPhyRate,

/* Description */
"Return the PHY rate at which broadcast packets are received from <nodeId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The broadcast receive PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxBroadcastPower(const RMH_Handle handle, const uint32_t nodeId, float* response),

/* API Name */
RMH_RemoteNode_GetRxBroadcastPower,

/* Description */
"Return the power level at which broadcast packets are received from <nodeId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      float*,                 "The broadcast receive power level")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxUnicastPower(const RMH_Handle handle, const uint32_t nodeId, float* response),

/* API Name */
RMH_RemoteNode_GetRxUnicastPower,

/* Description */
"Return the power level at which unicast packets are received from <nodeId> from the self node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      float*,                 "The unicast receive power level rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxMapPower(const RMH_Handle handle, const uint32_t nodeId, float* response),

/* API Name */
RMH_RemoteNode_GetRxMapPower,

/* Description */
"Return the power level at which MAP packets are received by <nodeId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      float*,                 "The MAP receive power level rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxPackets(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxPackets,

/* Description */
"Return the number of packets <nodeId> has received.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "Number of packets received by <nodeId>")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxSNR(const RMH_Handle handle, const uint32_t nodeId, float* response),

/* API Name */
RMH_RemoteNode_GetRxSNR,

/* Description */
"The signal to noise ratio of <nodeId> based on the Type 1 probe from per node. Measured in dB.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      float*,                 "The SNR of <nodeId>")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxCorrectedErrors(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxCorrectedErrors,

/* Description */
"Return the number of packets with corrected errors <nodeId> has received",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of corrected packets with errors")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxUnCorrectedErrors(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxUnCorrectedErrors,

/* Description */
"Return the number of packets with uncorrected errors <nodeId> has received",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of uncorrected packets with errors")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetRxTotalErrors(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetRxTotalErrors,

/* Description */
"Return the total number of packets with errors <nodeId> has received",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of total number of packets with errors")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetTxUnicastPhyRate(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetTxUnicastPhyRate,

/* Description */
"Return the PHY rate at which unicast packets are transmitted from <nodeId> to the self node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The unicast transmission PHY rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Phy"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetTxUnicastPower(const RMH_Handle handle, const uint32_t nodeId, float* response),

/* API Name */
RMH_RemoteNode_GetTxUnicastPower,

/* Description */
"Return the power level rate at which unicast packets are transmitted from <nodeId> to the self node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      float*,                 "The unicast transmission power level rate")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetTxPowerReduction(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetTxPowerReduction,

/* Description */
"The transmit power control back-off used for transmissions from the specified <nodeId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The transmission power reduction of <nodeId>")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node,Power"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_RemoteNode_GetTxPackets(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_RemoteNode_GetTxPackets,

/* Description */
"Return the total number of packets <nodeId> has transmitted.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of packets transmitted by <nodeId>")
),

/* Wrap API */
TRUE,

/* Tags */
"Remote Node"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetNumIngressFlows(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_PQoS_GetNumIngressFlows,

/* Description */
"Return the number of ingress flows",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of ingress flows")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetNumEgressFlows(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_PQoS_GetNumEgressFlows,

/* Description */
"Return the number of egress flows",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of egress flows")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetEgressBandwidth(const RMH_Handle handle, const uint32_t nodeId, uint32_t* response),

/* API Name */
RMH_PQoS_GetEgressBandwidth,

/* Description */
"Return the amount of egress bandwidth available on a particular node.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(nodeId,         const uint32_t,         "The node Id of the remote node to inspect"),
    OUTPUT_PARAM(response,      uint32_t*,              "The available egress bandwidth")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetIngressFlowIds(const RMH_Handle handle, RMH_MacAddress_t* responseArray, const size_t responseArraySize, size_t* responseArrayUsed),

/* API Name */
RMH_PQoS_GetIngressFlowIds,

/* Description */
"Return a list of the unique Id for each existing ingress flows.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseArray,     RMH_MacAddress_t*,      "An array where the flow unique Ids should be returned"),
    INPUT_PARAM(responseArraySize,  const size_t,           "The size of the response array"),
    OUTPUT_PARAM(responseArrayUsed, size_t*,                "The number of entries in the response array which have valid data")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetPeakDataRate(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetPeakDataRate,

/* Description */
"Return the peak data rate in Kbps for the flow specified by <flowId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The peak data rate in Kbps")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetBurstSize(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetBurstSize,

/* Description */
"Return the number of packets per burst for the flow specified by <flowId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The packets per burst")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetLeaseTime(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetLeaseTime,

/* Description */
"Return the lease time in seconds for the flow specified by <flowId>. Zero indicates an infinite lease time.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The lease time in seconds")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetLeaseTimeRemaining(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetLeaseTimeRemaining,

/* Description */
"Return the lease time remaining in seconds for the flow specified by <flowId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The lease time remaining in seconds")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetFlowTag(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetFlowTag,

/* Description */
"Return the tag for the flow specified by <flowId>. This is optional for application use",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The flow tag")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetMaxLatency(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetMaxLatency,

/* Description */
"Return the maximum latency of the flow specified by <flowId>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The maximum latency")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetShortTermAvgRatio(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetShortTermAvgRatio,

/* Description */
"Return the short term average ratio for the flow specified by <flowId>. This is the ratio of the short term average "
"rate of the flow compared to the peak rate over the interval of <RMH_PQoSFlow_GetMaxLatency>. This value plus one "
"serves as the numerator of the ratio. The denominator is 256. This value is only applicable when the maximun latency "
"value is greater than or equal to 10 ms.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The short term average ratio")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetMaxRetry(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetMaxRetry,

/* Description */
"Retrun the maximum number of retransmission attempts for each MSDU of the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The maximum retransmission attempts")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetVLANTag(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetVLANTag,

/* Description */
"Return the VLAN priority for the flow specified by <flowId>. This is used for MSDU classification when "
"<RMH_PQoSFlow_GetIngressClassificationRule> is 6 or 7.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The VLAN tag")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetFlowPer(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetFlowPer,

/* Description */
"Return the flow packet error ratio profile for the flow specified by <flowId>. This is to specify whether the flow "
"should use the nominal packet error rate (PER) PHY profile or the Very Low PER PHY profile.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The flow PER profile")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetIngressClassificationRule(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetIngressClassificationRule,

/* Description */
"Return the ingress classification rule for assigning MSDUs to the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The ingress classification rule")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetPacketSize(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetPacketSize,

/* Description */
"Return the packet size in bytes of the flow specified by <flowId>. This includes the VLAN header but not including "
"the FCS.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The flow packet size")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetTotalTxPackets(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetTotalTxPackets,

/* Description */
"Return the total number of packets transmitted on the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of packets transmitted")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetDSCPMoCA(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetDSCPMoCA,

/* Description */
"Return the DSCP MoCA value for the flow specified by <flowId>. The value of the three MSB of the DSCP Type of "
"Service field is used for MSDU classification when <RMH_PQoSFlow_GetIngressClassificationRule> is set to 1 or 3.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The DSCP MoCA")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetDFID(const RMH_Handle handle, const RMH_MacAddress_t flowId, uint32_t* response),

/* API Name */
RMH_PQoSFlow_GetDFID,

/* Description */
"Return the destination flow ID of the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      uint32_t*,              "The DFID of the flow")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetDestination(const RMH_Handle handle, const RMH_MacAddress_t flowId, RMH_MacAddress_t *response),

/* API Name */
RMH_PQoSFlow_GetDestination,

/* Description */
"Return the destination MAC address of the traffic to be sent to the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The destination MAC of the flow")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetIngressMac(const RMH_Handle handle, const RMH_MacAddress_t flowId, RMH_MacAddress_t *response),

/* API Name */
RMH_PQoSFlow_GetIngressMac,

/* Description */
"Return the ingress MAC address of the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The ingress MAC of the flow")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoSFlow_GetEgressMac(const RMH_Handle handle, const RMH_MacAddress_t flowId, RMH_MacAddress_t *response),

/* API Name */
RMH_PQoSFlow_GetEgressMac,

/* Description */
"Return the egress MAC address of the flow specified by <flowId>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(flowId,         const RMH_MacAddress_t, "The unique flow identifier"),
    OUTPUT_PARAM(response,      RMH_MacAddress_t*,      "The egress MAC of the flow")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)


RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetMaxEgressBandwidth(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_PQoS_GetMaxEgressBandwidth,

/* Description */
"Return the node Id with the maximum available bandwidth",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The node Id with the maximum egress bandwidth")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_PQoS_GetMinEgressBandwidth(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_PQoS_GetMinEgressBandwidth,

/* Description */
"Return the node Id with the minimum available bandwidth",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The node Id with the minimum egress bandwidth")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetAdmissionAttempts(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetAdmissionAttempts,

/* Description */
"Return the number of admission attempts this node has made. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of admission attempts")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetAdmissionFailures(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetAdmissionFailures,

/* Description */
"Return the number of admission failures for this node"
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of admission failures by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetAdmissionSucceeded(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetAdmissionSucceeded,

/* Description */
"Return the number of successful admissions for this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of successful admissions by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetAdmissionsDeniedAsNC(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetAdmissionsDeniedAsNC,

/* Description */
"Return the number of admissions this node has denied when it was the NC. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of admissions this node has denied when it was the NC")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats,NC"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxTotalBytes(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxTotalBytes,

/* Description */
"Return the total number of bytes transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of bytes transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxTotalBytes(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxTotalBytes,

/* Description */
"Return the total number of bytes received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of bytes received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxTotalPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxTotalPackets,

/* Description */
"Return the total number of packets transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxTotalPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxTotalPackets,

/* Description */
"Return the total number of packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of received transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxUnicastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxUnicastPackets,

/* Description */
"Return the number of unicast packets transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of unicast packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxUnicastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxUnicastPackets,

/* Description */
"Return the number of unicast packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of unicast packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxBroadcastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxBroadcastPackets,

/* Description */
"Return the number of broadcast packets transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of broadcast packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxBroadcastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxBroadcastPackets,

/* Description */
"Return the number of broadcast packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of broadcast packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxMulticastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxMulticastPackets,

/* Description */
"Return the number of multicast packets transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of multicast packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxMulticastPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxMulticastPackets,

/* Description */
"Return the number of multicast packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of multicast packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxReservationRequestPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxReservationRequestPackets,

/* Description */
"Return the number of reservation request packets transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of reservation request packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxReservationRequestPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxReservationRequestPackets,

/* Description */
"Return the number of reservation request packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of reservation request packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxMapPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxMapPackets,

/* Description */
"Return the number of MAP transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of MAP packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxMapPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxMapPackets,

/* Description */
"Return the number of MAP received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of MAP packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxLinkControlPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxLinkControlPackets,

/* Description */
"Return the number of link control transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of link control packets transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxLinkControlPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxLinkControlPackets,

/* Description */
"Return the number of link control received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of link control packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxBeacons(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxBeacons,

/* Description */
"Return the number of beacons transmitted by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of beacons transmitted by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxBeacons(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxBeacons,

/* Description */
"Return the number of beacons received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of beacons received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxUnknownProtocolPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxUnknownProtocolPackets,

/* Description */
"Return the number of unknown packets received by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of unknown packets received by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxDroppedPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxDroppedPackets,

/* Description */
"Return the number of packets this node has dropped before transmitting. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of packets dropped by this node before transmitting")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxDroppedPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxDroppedPackets,

/* Description */
"Return the number of packets this node has dropped after receiving. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The number of received packets dropped by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxTotalErrors(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxTotalErrors,

/* Description */
"Return the total number of transmit errors by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of transmit errors by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxTotalErrors(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxTotalErrors,

/* Description */
"Return the total number of received errors by this node. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of receive errors by this node")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxCRCErrors(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxCRCErrors,

/* Description */
"Return the total number of packets this node has received with CRC errors. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of received packets with CRC errors")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxTimeoutErrors(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxTimeoutErrors,

/* Description */
"Return the total number of packets this node has received with timeout errors. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of received packets with timeout errors")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxTotalAggregatedPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetRxTotalAggregatedPackets,

/* Description */
"Return the total number of received aggregated packets. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of received aggregated packets")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxTotalAggregatedPackets(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Stats_GetTxTotalAggregatedPackets,

/* Description */
"Return the total number of transmitted aggregated packets. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The total number of transmitted aggregated packets")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)


RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxPacketAggregation(const RMH_Handle handle, uint32_t* responseArray, const size_t responseArraySize, size_t* responseArrayUsed),

/* API Name */
RMH_Stats_GetRxPacketAggregation,

/* Description */
"Return an array indicating the number of packets received per aggregation number. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseArray,     uint32_t*,              "An array where the aggregation information should be returned"),
    INPUT_PARAM(responseArraySize,  const size_t,           "The size of the response array"),
    OUTPUT_PARAM(responseArrayUsed, size_t*,                "The number of entries in the response array which have valid data")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetTxPacketAggregation(const RMH_Handle handle, uint32_t* responseArray, const size_t responseArraySize, size_t* responseArrayUsed),

/* API Name */
RMH_Stats_GetTxPacketAggregation,

/* Description */
"Return an array indicating the number of packets transmitted per aggregation number. The array index indicates "
"the number of transmitted bursts. So index 0 counts transmitted bursts with actual aggregation of 0, index 2 counts "
"actual aggregation of 2, and so on."
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseArray,     uint32_t*,              "An array where the aggregation information should be returned"),
    INPUT_PARAM(responseArraySize,  const size_t,           "The size of the response array"),
    OUTPUT_PARAM(responseArrayUsed, size_t*,                "The number of entries in the response array which have valid data")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxCorrectedErrors(const RMH_Handle handle, RMH_NodeList_Uint32_t* response),

/* API Name */
RMH_Stats_GetRxCorrectedErrors,

/* Description */
"Return the number of received packets from every node with errors which were corrected. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeList_Uint32_t*,
        "Where the index is the node Id, if <nodePresent> is 'true', <nodeValue> is the number of corrected errors for that node.")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_GetRxUncorrectedErrors(const RMH_Handle handle, RMH_NodeList_Uint32_t* response),

/* API Name */
RMH_Stats_GetRxUncorrectedErrors,

/* Description */
"Return the number of received packets from every node with errors which were not corrected. "
"\n**NOTE: This counter is reset by <RMH_Stats_Reset>",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_NodeList_Uint32_t*,
        "Where the index is the node Id, if <nodePresent> is 'true', <nodeValue> is the number of uncorrected errors for that node.")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Stats_Reset(const RMH_Handle handle),

/* API Name */
RMH_Stats_Reset,

/* Description */
"Reset MoCA statistics counters back to zero.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats"
/********************************************************************************************************************/
)


RMH_API_IMPLEMENTATION_GENERIC_THEN_SOC(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_GetAPILevel(const RMH_Handle handle, uint32_t* response),

/* API Name */
RMH_Log_GetAPILevel,

/* Description */
"Return a bitmask of <RMH_LogLevel> which indicates the currently enabled RMH log types in the RMH library. Note, this "
"API is for log messages from RMH libraries only. The log level of the lower level MoCA driver should be read with "
"<RMH_Log_GetDriverLevel>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      uint32_t*,              "The RMH API log level")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_THEN_SOC(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_SetAPILevel(const RMH_Handle handle, const uint32_t value),

/* API Name */
RMH_Log_SetAPILevel,

/* Description */
"Set the log level of the RMH library. This is set as a bitmask of <RMH_LogLevel> indicating the RMH log types to "
"enable in the RMH libraries. Note, this API is for log messages from RMH libraries only. The log level of the lower "
"level MoCA driver should be set with <RMH_Log_SetDriverLevel>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const uint32_t,         "The desired RMH API log level")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_GetDriverLevel(const RMH_Handle handle, RMH_LogLevel* response),

/* API Name */
RMH_Log_GetDriverLevel,

/* Description */
"Return a bitmask of <RMH_LogLevel> which indicates the currently enabled RMH log types in the MoCA driver. Note, this "
"API is for log messages from SoC MoCA driver only. The log level of the RMH library should be read with "
"<RMH_Log_GetAPILevel>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(response,      RMH_LogLevel*,          "The SoC MoCA Driver log level")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_SetDriverLevel(const RMH_Handle handle, const RMH_LogLevel value),

/* API Name */
RMH_Log_SetDriverLevel,

/* Description */
"Set the log level of the MoCA driver. This is set as a bitmask of <RMH_LogLevel> indicating the RMH log types to "
"enable at the driver. Note, this API is for log messages from SoC MoCA driver only. The log level of the RMH "
"libraries should be set with <RMH_Log_SetAPILevel>.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const RMH_LogLevel,     "The desired SoC MoCA Driver log level")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_GetDriverFilename(const RMH_Handle handle, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_Log_GetDriverFilename,

/* Description */
"Get the file name where MoCA driver logs are currently being captured.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,             const RMH_Handle,   "The RMH handle as returned by RMH_Initialize"),
    OUTPUT_PARAM(responseBuf,       char*,              "A buffer where the filename will be written"),
    INPUT_PARAM(responseBufSize,    const size_t,       "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_SOC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_SetDriverFilename(const RMH_Handle handle, const char* value),

/* API Name */
RMH_Log_SetDriverFilename,

/* Description */
"Set the file name where MoCA driver logs should be captured to. If logs are already being captured to a file this "
"capture will stop at that location and begin in this file. If the new log file already exists new logs will append "
"to it.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize"),
    INPUT_PARAM(value,          const char*,            "A file name where logs should be written.")
),

/* Wrap API */
TRUE,

/* Tags */
"Log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_CreateDriverFile(const RMH_Handle handle, char* responseBuf, const size_t responseBufSize),

/* API Name */
RMH_Log_CreateDriverFile,

/* Description */
"Create a new log file in standard RDK formate. This will:\n"
"\t1. Locate the file at a writable location in the rootfs.\n"
"\t2. Name the file using a RDK standard naming convention.\n"
"\t3. Put any necessary static information at the beginning of the file.\n"
"\t   This includes build details and other useful information.",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,       "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    INPUT_PARAM(responseBuf,       char *,              "The file name "),
    INPUT_PARAM(responseBufSize,    const size_t,       "The size in bytes of the buffer <responseBuf>")
),

/* Wrap API */
TRUE,

/* Tags */
"log"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_PrintStatus(const RMH_Handle handle, const char* filename),

/* API Name */
RMH_Log_PrintStatus,

/* Description */
"Print a generic status summary of the MoCA device and network. If <filename> is NULL all log messages are printed "
"with RMH_LOG_MESSAGE. If it is not NULL the status will be appended to that file",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,
        "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    INPUT_PARAM(filename,       const char *,
        "The file name where to write the status. If this is NULL the status will be written to RMH_LOG_MESSAGE")
),

/* Wrap API */
TRUE,

/* Tags */
"Status"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_PrintStats(const RMH_Handle handle, const char* filename),

/* API Name */
RMH_Log_PrintStats,

/* Description */
"Print a summary of of the Tx/Rx MoCA stats. If <filename> is NULL all log messages are printed "
"with RMH_LOG_MESSAGE. If it is not NULL the status will be appended to that file",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,
        "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    INPUT_PARAM(filename,       const char *,
        "The file name where to write the status. If this is NULL the status will be written to RMH_LOG_MESSAGE")
),

/* Wrap API */
TRUE,

/* Tags */
"Stats,Status"
/********************************************************************************************************************/
)



RMH_API_IMPLEMENTATION_GENERIC_ONLY(
/********************************************************************************************************************/
/* API Declaration */
RMH_Result RMH_Log_PrintFlows(const RMH_Handle handle, const char* filename),

/* API Name */
RMH_Log_PrintFlows,

/* Description */
"Print a generic status summary of the MoCA flows. If <filename> is NULL all log messages are printed with "
"RMH_LOG_MESSAGE with RMH_LOG_MESSAGE. If it is not NULL the status will be appended to that file",

/* Parameters */
PARAMETERS(
    INPUT_PARAM(handle,         const RMH_Handle,
        "The RMH handle as returned by RMH_Initialize. NULL is valid for this API."),
    INPUT_PARAM(filename,       const char *,
        "The file name where to write the status. If this is NULL the status will be written to RMH_LOG_MESSAGE")
),

/* Wrap API */
TRUE,

/* Tags */
"PQoS,Status"
/********************************************************************************************************************/
)


#ifdef __cplusplus
}
#endif

#endif /* RMH_API_H */
