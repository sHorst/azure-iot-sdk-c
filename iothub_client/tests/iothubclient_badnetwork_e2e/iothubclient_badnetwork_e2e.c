// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"
#include "badnetwork.h"
#include "iothubtest.h"
#include "iothubtransportamqp.h"
#include "iothubtransporthttp.h"
#include "iothubtransportmqtt.h"
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

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_SAS_AMQP)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), AMQP_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_SAS_MQTT)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), MQTT_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_SAS_HTTP)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), HTTP_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_x509_AMQP)
    {
        ASSERT_FAIL("this test fails with lots of spew");
        //disconnect_create_send_reconnect(IoTHubAccount_GetX509Device(g_iothubAcctInfo), AMQP_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_x509_MQTT)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetX509Device(g_iothubAcctInfo), MQTT_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_SingleMessage_DisconnectedBeforeClientCreated_ReconnectedAfterMessageSent_x509_HTTP)
    {
        disconnect_create_send_reconnect(IoTHubAccount_GetX509Device(g_iothubAcctInfo), HTTP_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_MultipleMessages_DisconnectedAfterFirstConfirmmation_Reconnected30SecondsLater_SAS_AMQP)
    {
        confirm_disconnect_wait_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), AMQP_Protocol);
    }
    
    TEST_FUNCTION(IotHub_BadNetwork_D2C_MultipleMessages_DisconnectedAfterFirstConfirmmation_Reconnected30SecondsLater_SAS_MQTT)
    {
        confirm_disconnect_wait_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), MQTT_Protocol);
    }
    
    TEST_FUNCTION(IotHub_BadNetwork_D2C_MultipleMessages_DisconnectedAfterFirstConfirmmation_Reconnected30SecondsLater_SAS_HTTP)
    {
        confirm_disconnect_wait_reconnect(IoTHubAccount_GetSASDevice(g_iothubAcctInfo), HTTP_Protocol);
    }

    TEST_FUNCTION(IotHub_BadNetwork_D2C_MultipleMessages_SendDisconnectSendReconnectSendDisconnectSendReconnect)
    {

    }

END_TEST_SUITE(iothubclient_badnetwork_e2e)

