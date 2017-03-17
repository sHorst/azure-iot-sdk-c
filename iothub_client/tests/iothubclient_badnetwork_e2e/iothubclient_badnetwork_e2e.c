// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"
#include "badnetwork.h"
#include "iothubtest.h"
#include "iothubtransportamqp.h"
#include "iothubtransporthttp.h"
#include "iothubtransportmqtt.h"
#include "iothubtransportamqp_websockets.h"
#include "iothubtransportmqtt_websockets.h"
#include "iothubclient_common_e2e.h"

static TEST_MUTEX_HANDLE g_dllByDll;

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
    }

    
#define TEST_FUNCTION_SAS(name, longprotocol,shortprotocol) \
    TEST_FUNCTION(IotHub_BadNetwork_##name##_SAS_##shortprotocol) \
    { \
        name(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), longprotocol); \
    }
    
#define TEST_FUNCTION_X509(name, longprotocol,shortprotocol) \
    TEST_FUNCTION(IotHub_BadNetwork_##name##_X509_##shortprotocol) \
    { \
        name(IoTHubAccount_GetX509Device(g_iothubAcctInfo), longprotocol); \
    }

#define MATRIX_TEST_FUNCTION(name)  \
    TEST_FUNCTION_SAS(name, MQTT_Protocol, MQTT) \
    TEST_FUNCTION_X509(name, MQTT_Protocol, MQTT) \
    TEST_FUNCTION_SAS(name, MQTT_WebSocket_Protocol, MQTT_WS) \
    TEST_FUNCTION_X509(name, MQTT_WebSocket_Protocol, MQTT_WS) \
    TEST_FUNCTION_SAS(name, AMQP_Protocol, AMQP) \
    TEST_FUNCTION_X509(name, AMQP_Protocol, AMQP) \
    TEST_FUNCTION_SAS(name, AMQP_Protocol_over_WebSocketsTls, AMQP_WS) \
    TEST_FUNCTION_X509(name, AMQP_Protocol_over_WebSocketsTls, AMQP_WS) \
    TEST_FUNCTION_SAS(name, HTTP_Protocol, HTTP) \
    TEST_FUNCTION_X509(name, HTTP_Protocol, HTTP)

    MATRIX_TEST_FUNCTION(disconnect_create_send_reconnect);
    MATRIX_TEST_FUNCTION(disconnect_after_first_confirmation_then_close);
    MATRIX_TEST_FUNCTION(send_disconnect_send_reconnect_etc);
    

END_TEST_SUITE(iothubclient_badnetwork_e2e)

