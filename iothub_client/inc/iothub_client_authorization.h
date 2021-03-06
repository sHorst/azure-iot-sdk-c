// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef IOTHUB_CLIENT_AUTHORIZATION_H
#define IOTHUB_CLIENT_AUTHORIZATION_H

#ifdef __cplusplus
extern "C" {
#include <cstdbool>
#else
#include <stdbool.h>
#endif /* __cplusplus */

#include "azure_c_shared_utility/macro_utils.h"
#include "azure_c_shared_utility/umock_c_prod.h"

typedef struct IOTHUB_AUTHORIZATION_DATA_TAG* IOTHUB_AUTHORIZATION_HANDLE;

#define IOTHUB_CREDENTIAL_TYPE_VALUES       \
    IOTHUB_CREDENTIAL_TYPE_UNKNOWN,         \
    IOTHUB_CREDENTIAL_TYPE_DEVICE_KEY,      \
    IOTHUB_CREDENTIAL_TYPE_X509,            \
    IOTHUB_CREDENTIAL_TYPE_SAS_TOKEN

DEFINE_ENUM(IOTHUB_CREDENTIAL_TYPE, IOTHUB_CREDENTIAL_TYPE_VALUES);

MOCKABLE_FUNCTION(, IOTHUB_AUTHORIZATION_HANDLE, IoTHubClient_Auth_Create, const char*, device_key, const char*, device_id, const char*, device_sas_token);
MOCKABLE_FUNCTION(, void, IoTHubClient_Auth_Destroy, IOTHUB_AUTHORIZATION_HANDLE, handle);
MOCKABLE_FUNCTION(, IOTHUB_CREDENTIAL_TYPE, IoTHubClient_Auth_Get_Credential_Type, IOTHUB_AUTHORIZATION_HANDLE, handle);
MOCKABLE_FUNCTION(, char*, IoTHubClient_Auth_Get_SasToken, IOTHUB_AUTHORIZATION_HANDLE, handle, const char*, scope, size_t, expire_time);
MOCKABLE_FUNCTION(, const char*, IoTHubClient_Auth_Get_DeviceId, IOTHUB_AUTHORIZATION_HANDLE, handle);
MOCKABLE_FUNCTION(, bool, IoTHubClient_Auth_Is_SasToken_Valid, IOTHUB_AUTHORIZATION_HANDLE, handle);

#ifdef __cplusplus
}
#endif

#endif /* IOTHUB_CLIENT_AUTHORIZATION_H */
