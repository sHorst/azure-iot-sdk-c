// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#include "badnetwork.h"
#include "iothubclient_common_e2e.h"
#include "iothubtransportamqp.h"
#include "testrunnerswitcher.h"
#include "network_disconnect.h"

#include "azure_c_shared_utility/platform.h"

void disconnect_create_send_reconnect(IOTHUB_PROVISIONED_DEVICE* deviceToUse, IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol)
{
    IOTHUB_CLIENT_HANDLE iotHubClientHandle;
    D2C_MESSAGE_HANDLE d2cMessage;

    // Disconnect
    network_disconnect();

    // create
    iotHubClientHandle = client_connect_to_hub(deviceToUse, protocol);

    // Send the Event from the client
    d2cMessage = client_create_and_send_d2c(iotHubClientHandle);

    // reconnect
    network_reconnect();

    // Wait for confirmation that the event was recevied
    bool dataWasRecv = client_wait_for_d2c_confirmation(d2cMessage);
    ASSERT_IS_TRUE_WITH_MSG(dataWasRecv, "Failure sending data to IotHub"); // was received by the callback...

    // close the client connection
    IoTHubClient_Destroy(iotHubClientHandle);

    // Why?  Ask dan. 
    (void)platform_init();

    // Waigt for the message to arrive
    service_wait_for_d2c_event_arrival(deviceToUse, d2cMessage);

    // cleanup
    destroy_d2c_message_handle(d2cMessage);
}

void confirm_disconnect_wait_reconnect(IOTHUB_PROVISIONED_DEVICE* deviceToUse, IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol)
{
    (void)deviceToUse, protocol;
}


