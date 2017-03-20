// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"
#include "badnetwork.h"
#include "iothubtest.h"
#include "iothubclient_common_e2e.h"
#include "iothubtransportamqp.h"
#include "network_disconnect.h"

static TEST_MUTEX_HANDLE g_dllByDll;

IOTHUB_CLIENT_TRANSPORT_PROVIDER g_protocol = AMQP_Protocol;

void set_badnetwork_test_protocol(IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol)
{
    g_protocol = protocol;
}
    
BEGIN_TEST_SUITE(iothubclient_badnetwork_e2e)

    TEST_SUITE_INITIALIZE(TestClassInitialize)
    {
        e2e_init();
        TEST_INITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_SUITE_CLEANUP(TestClassCleanup)
    {
        e2e_deinit();
        TEST_DEINITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_FUNCTION_CLEANUP(TestFunctionCleanup)
    {
        printf("Function cleanup -- reconnecting\n");
        network_reconnect();
    }

    TEST_FUNCTION(IotHub_BadNetwork_disconnect_create_send_reconnect_SAS)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo),g_protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_disconnect_after_first_confirmation_then_close_SAS)
    {
        disconnect_after_first_confirmation_then_close(IoTHubAccount_GetSASDevice(g_iothubAcctInfo),g_protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_send_disconnect_send_reconnect_etc_SAS)
    {
        send_disconnect_send_reconnect_etc(IoTHubAccount_GetSASDevice(g_iothubAcctInfo),g_protocol);
    }

END_TEST_SUITE(iothubclient_badnetwork_e2e)

